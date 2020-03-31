### Example

```c++
SessionStorage storage;
TradesDb tradesDb;
ZmqCommonServer server(storage);
CGateConnection conn("default");
CGateStream info(conn, "FORTS_FUTINFO_REPL","snapshot+online");
CGateStream common(conn, "FORTS_FUTCOMMON_REPL", "online");
CGateStream trades(conn, "FORTS_FUTTRADES_REPL","online", lifeNumGetter, lifeNumSetter);
info.Pipe("session", storage);
info.Pipe("fut_sess_contents", storage);
common.Pipe("common", server);
trades.Pipe("trades", tradesDb, revisionGetter);
AwaitUntilOnline(conn, info);
RunForever(conn, common, trades);
```

### Program Structure

-   CGateEnvironment - обертка на cg_env_init/cg_env_close
-   CgateConnection - обертка над cg_conn_t\*
-   CGateStream - обертка над cg_listener_t\*
-   CGateStream - внутри себя делают всю работу над распределением приходящих сообщений в нужные обработчики, восстановление соединения, переоткрытие, правильная настройка connection string
-   CGateStream.Pipe(table_name, handler, ...) - общий подход, когда сообщения по определенной таблице, перенаправляются обработчику handler, который в общем случае имеет вид void function(void \*data).
-   Таким образом, общий подход в том, чтобы перенаправить потоки сообщений в обработчики и далее запустить получение новых сообщений, всю сложную роботу, по правильной синхронизации должен делать CGateStream
-   AwaitUntilOnline(conn, stream1, stream2, ...) - последовательно дожидается пока все stream не выйдут онлайн (блокируется до выхода всех потокв в онлайн). Можно через запятую указать любое количество stream
-   RunForever(conn, stream1, stream2,...) - запускает в бесконечном цикле получения сообщений по всем потокам. Можно через запятую указать любое количество stream

### Helpers

-   cgate_struct_helpers - содержит в cgate_indexes индексы таблиц, чтобы в stream можно было легко идентифицировать
-   cgate_struct_helpers - содержит преобрaзования структур cgate в csv , bson формат
-   cgate_struct_helpers требует , чтобы на машине присутствовала libmongoc-1.0

### CGateStream

-   Это обертка над Listener
-   Жестко привязан к connection
-   Внутри себя фильтрует поток на revision
-   Можно задать режим mode получения данных (online, snapshot, snapshot+online), укажет его в connection string.
-   Внутри себя содержит обработчики для разных таблиц, которые вызывает, возможные варианты это
    Insert (CG_MSG_STREAM_DATA, добавление данных по данной таблице), Commit (CG_MSG_TN_COMMIT, завершение транзакции)
-   Если задать revisionGetter , то вначале попытается получить revision и укажет его в connection string. Например, можно задать обработчик на Insert как сохранение в базе данных в таблицу, например, trades, а revisionGetter указать как: взять последнюю запись в таблице trades и установить revision в lastRecord.revision+1
-   На уровне потока(stream, несколько таблиц) отслеживает ChangeLifenum, Online, Commit, ClearDeleted
-   Для того, чтобы stream мог сохранять состояние необходимо указать lifeNumGetter, lifeNumSetter - это функции, которые можно передать в конструктор, чтобы не зашивать логику сохранения жестко в код. lifenum полученный lifeNumGetter укажется в connection string. Если придёт событие CG_MSG_P2REPL_LIFENUM по потоку, то вызовется lifeNumSetter. Например можно указать getter и setter функции , которые ходят в базу данных и по именем потока получают и сохраняют lifenum потока.
-   stream.Pipe("table_name", handlerClass) перенаправит поток в handlerClass по следующим правилам:
    -   если handlerClass содержит метод GetHandler("table_name") который возвращает функцию, то данные будут передаваться этой функции для обработки
    -   если handerClass не содержит метод GetHandler то будут искаться метод Insert, Commit , которым и будет передаваться обработка при соответствующих событиях
-   stream.Pipe("table_name", handlerClass, revisionGetter) - перед открытием потока, вызывается revisionGetter и возвращаемое значение укажется в connection string для revision для это таблицы.
-   Пример минимального обработчика, который будет выводить на консоль сообщения в csv формате:

```c++
template <typename T>
struct PrintHandler
{
    void Insert(void *data)
    {
        T *t = (T *)data;
        std::cout << to_csv(*t) << std::endl;
    }
};
//применяется в коде
PrintHandler<FORTS_FUTINFO_REPL::session> printHandler;
info.Pipe("session", printHandler);
```

### Общий подход к хранению данных

-   \*Store - сущность хранящая данные на уровне всего потока + добавочная информация (из других потоков возможно тоже) + функции обработки более общии
-   \*Stream - сущность хранящая данные на уровне таблицы cgate + функции обработки более специализированные
-   предложение по названиям:
    -   SmartMongoStorage, SmartMongoStream
    -   SmartRedisStorage, SmartRedisStream
    -   SmartFileStorage, SmartFileStream
    -   SmartBinaryStorage, SmartBinaryStream

### SmartSessionStorage

-   реализованный класс с минимальной функциональностью, который аггрегируется необходимые для торговли параметры инструментов и сессии
-   позволяет избавиться от написания стандартного кода, ограничиться лишь storage.Init(), который запустит необходимые потоки и заполнит необходимые стуктуры, после закроет и уничтожит потоки
-   необходимы файлы в ini дириктории: fut_info.ini, opt_info.ini

### SmartMongoStorage

-   сохраняет lifenum (в test, lifenum) по имени потока
-   умеет получать lifenum

### SmartMongoStream

-   работает на уровне таблицы cgate
-   задача реплицировать cgate stream в collection
-   умееть GetLastRevision() по таблице сделать

### OrderManager

-   Концептуально участвуют 3 сущности: OrderReceiver, Publisher, ReplyReceiver
-   OrderReceiver - получает ордера от User (db, rpc, ...) интерфейс для взаимодействия с другими системами, взаимодествует с Publisher , ничего не должен знать о cgate
-   Publisher непосредственно работает с протоколом cgate, отвечает за отсылку сообщений и приём ответов
-   ReplyReceiver - перенаправляет от Publisher ответы дальше в систему
-   Для упрощения. Поток от биржи считаем как нисходящий, а поток от систем к бирже как восходящий. Биржа находится на вершине, а система вниз идёт и расширяется. Возможно в дальнейшем подумать над переименованием в OrderUp, ReplyDown для более устойчивой когнитивной модели (названия пока слабая сторона ....)

### Docker

-   clear logs "truncate -s 0 /var/lib/docker/containers/\*/\*-json.log"
