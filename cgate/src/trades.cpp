#include <iostream>
#include <cgate.h>
#include <zmq.h>
#include <assert.h>
#include "../../cgate/include/cgate-yard.hpp"
//#include "../../cgate/include/cgate_structs_helper.hpp"
#include "../../cgate/helpers/smart_session_storage.hpp"
#include "../../cgate/helpers/mongodb.hpp"

struct OrdersLog
{
    int32_t lifenum;
    int64_t revision;
    int64_t replRev;
    int32_t sess_id;
    int64_t orderid;
    int32_t action;
    int64_t price;
    int64_t deal_price;
    int32_t amount;
    int32_t ext_id;
    int32_t isin_id;
    std::string symbol{""};
    uint64_t moment_ns;
    char dir;
    std::string comment;

    auto to_bson(std::string exchange, std::string account, std::string login)
    {
        bson_t *doc;

        doc = BCON_NEW(
            "revision", BCON_UTF8(std::to_string(revision).c_str()),
            "replRev", BCON_UTF8(std::to_string(revision).c_str()),
            "sess_id", BCON_UTF8(std::to_string(sess_id).c_str()),
            "order_id", BCON_UTF8(std::to_string(orderid).c_str()),
            "isin_id", BCON_UTF8(std::to_string(isin_id).c_str()),
            "symbol", BCON_UTF8(symbol.c_str()),
            "action", BCON_UTF8(std::to_string(action).c_str()),
            "price", BCON_UTF8(std::to_string(price).c_str()),
            "deal_price", BCON_UTF8(std::to_string(deal_price).c_str()),
            "amount", BCON_UTF8(std::to_string(amount).c_str()),
            "dir", BCON_UTF8(std::to_string(dir).c_str()),
            "ext_id", BCON_UTF8(std::to_string(ext_id).c_str()),
            "comment", BCON_UTF8(comment.c_str()),
            "exchange", BCON_UTF8(exchange.c_str()),
            "account", BCON_UTF8(account.c_str()),
            "login", BCON_UTF8(login.c_str()));

        //return std::move(doc);
        return std::make_unique<bson_t *>(doc);
    }
};

//для некоторых типов необходимы специфичные преобразования
template <>
void SmartMongoStream::Insert<FORTS_FUTTRADE_REPL::orders_log>(void *data)
{
    FORTS_FUTTRADE_REPL::orders_log *t = (FORTS_FUTTRADE_REPL::orders_log *)data;
    OrdersLog orders_log;
    orders_log.replRev = t->replRev;
    orders_log.revision = t->replRev;
    orders_log.sess_id = t->sess_id;
    orders_log.orderid = t->id_ord;
    orders_log.action = t->action;
    orders_log.price = cg_bcd_to_int64(t->price);
    orders_log.deal_price = cg_bcd_to_int64(t->deal_price);
    orders_log.amount = t->xamount;
    orders_log.isin_id = t->isin_id;
    orders_log.moment_ns = t->moment_ns;
    orders_log.dir = t->dir;
    orders_log.comment = t->comment;
    orders_log.ext_id = t->ext_id;
    orders_log.symbol = sessionStorage_->GetShortSymbolByIsinId(t->isin_id); //session->isinid2symbol[t->isin_id];
    auto bson_ = orders_log.to_bson("moex_forts", "xxx", "yyy");
    BSON_APPEND_UTF8(*bson_, "from", gateway_name_.c_str());
    size_t len;
    char *str = bson_as_canonical_extended_json(*bson_, &len);
    //printf("%s\n", str);
    collection_->InsertOne(*bson_);
    logger.info("cgate: %s", str);
    bson_free(str);
}

template <>
void SmartMongoStream::Insert<FORTS_OPTTRADE_REPL::orders_log>(void *data)
{
    FORTS_FUTTRADE_REPL::orders_log *t = (FORTS_FUTTRADE_REPL::orders_log *)data;
    OrdersLog orders_log;
    orders_log.replRev = t->replRev;
    orders_log.revision = t->replRev;
    orders_log.sess_id = t->sess_id;
    orders_log.orderid = t->id_ord;
    orders_log.action = t->action;
    orders_log.price = cg_bcd_to_int64(t->price);
    orders_log.deal_price = cg_bcd_to_int64(t->deal_price);
    orders_log.amount = t->xamount;
    orders_log.isin_id = t->isin_id;
    orders_log.moment_ns = t->moment_ns;
    orders_log.dir = t->dir;
    orders_log.comment = t->comment;
    orders_log.ext_id = t->ext_id;
    orders_log.symbol = sessionStorage_->GetShortSymbolByIsinId(t->isin_id); //session->isinid2symbol[t->isin_id];
    auto bson_ = orders_log.to_bson("moex_opt", "xxx", "yyy");
    BSON_APPEND_UTF8(*bson_, "from", gateway_name_.c_str());
    size_t len;
    char *str = bson_as_canonical_extended_json(*bson_, &len);
    //printf("%s\n", str);
    collection_->InsertOne(*bson_);
    logger.info("cgate: %s", str);
    bson_free(str);
}

struct SmartMongoStorage
{
    std::string url_{""};

    SmartMongoStorage(std::map<std::string, std::string> &settings)
    {
        url_ = settings["url"];
    }

    void SetLifenum(std::string stream_name, int32_t lifenum)
    {
        std::cout << "SetLifenum " << std::endl;
        MongoClient client(url_);
        MongoCollection collection(client, "test", "lifenum");
        bson_t *doc;
        doc = bson_new();
        BSON_APPEND_UTF8(doc, "lifenum", std::to_string(lifenum).c_str());
        BSON_APPEND_UTF8(doc, "stream", stream_name.c_str());
        collection.InsertOne(doc);
        bson_destroy(doc);
    }

    int32_t GetLifenum(std::string stream_name)
    {
        MongoClient client(url_);
        MongoCollection collection(client, "test", "lifenum");
        return collection.GetLastLifenum(stream_name);
    }

    ~SmartMongoStorage()
    {
    }
};

int main()
{
    MongoInitializer();
    std::map<std::string, std::string> mongoStorageSettings{{"url", "mongodb://172.26.1.2:27017,172.26.1.3:27018/test?replicaSet=rs0"}};
    std::map<std::string, std::string> mongoStreamSettings{{"url", "mongodb://172.26.1.2:27017,172.26.1.3:27018/test?replicaSet=rs0"},
                                                           {"db_name", "test"},
                                                           {"collection_name", "trades"},
                                                           {"gw-name", "cgate-gw"}};
    CGateEnvironment env("ini=../config/trades.ini;key=11111111");
    CGateConnection conn("p2tcp://127.0.0.1:4001;local_pass=123;app_name=futtrade_server");
    SmartSessionStorage storage;
    SmartMongoStorage mongoStorage(mongoStorageSettings);
    SmartMongoStream tradesMongoStream(storage, mongoStreamSettings);
    auto lifeNumGetter = [&mongoStorage](std::string stream_name) { return mongoStorage.GetLifenum(stream_name); };
    auto lifeNumSetter = [&mongoStorage](std::string stream_name, int32_t lifenum) { mongoStorage.SetLifenum(stream_name, lifenum); };
    auto revisionFutTradesGetter = [&tradesMongoStream](void) { return tradesMongoStream.GetRevision("moex_forts"); };
    auto revisionOptTradesGetter = [&tradesMongoStream](void) { return tradesMongoStream.GetRevision("moex_opt"); };
    auto futTradesHandler = [&tradesMongoStream](void *data) { tradesMongoStream.Insert<FORTS_FUTTRADE_REPL::orders_log>(data); };
    auto optTradesHandler = [&tradesMongoStream](void *data) { tradesMongoStream.Insert<FORTS_OPTTRADE_REPL::orders_log>(data); };
    std::function<void(void *)> futHeartbeatHandler = [](void *data) {
        FORTS_FUTTRADE_REPL::heartbeat *hb = (FORTS_FUTTRADE_REPL::heartbeat *)data;
        std::cout << to_csv(*hb) << std::endl;
    };
    CGateStream futTrades(conn, "FORTS_FUTTRADE_REPL", "snapshot+online", lifeNumGetter, lifeNumSetter);
    CGateStream optTrades(conn, "FORTS_OPTTRADE_REPL", "snapshot+online", lifeNumGetter, lifeNumSetter);
    futTrades.Pipe("orders_log", futTradesHandler, revisionFutTradesGetter);
    futTrades.Pipe("heartbeat", futHeartbeatHandler);
    optTrades.Pipe("orders_log", optTradesHandler, revisionOptTradesGetter);

    storage.Init(conn);
    RunStreamsForever(conn, futTrades, optTrades);
    return 0;
}
