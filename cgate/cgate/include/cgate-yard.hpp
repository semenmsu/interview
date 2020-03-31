#ifndef __CGATE_YARD_HEADER__
#define __CGATE_YARD_HEADER__
#include <cgate.h>
#include <functional>
#include <sstream>
#include "cgate_structs_helper.hpp"
#include <type_traits>
#include "logger.h"
#include "publisher.hpp"

typedef CG_RESULT (*__stream_callback)(cg_conn_t *conn, cg_listener_t *listener, struct cg_msg_t *msg, void *data);
typedef std::map<int32_t, std::function<void(void *)>> __inserts;
typedef std::map<std::string, std::function<void(void *, int)>> __loaders;
typedef std::vector<std::function<void(void *)>> __commits;
typedef std::map<std::string, std::function<int64_t(void)>> __revisions;

struct CGateEnvironment
{
    std::string settings_{""};

    CGateEnvironment(std::string settings);

    ~CGateEnvironment();
};

struct CGateConnection
{
    cg_conn_t *conn_{0};

    std::string settings_{""};

    CGateConnection(std::string settings);

    uint32_t GetState();

    void Close();

    void Destroy();

    int32_t Process(uint32_t timeout);

    ~CGateConnection();
};

//CGateListener жестко связан с CGateConnection
struct CGateListener
{
    std::function<std::string(void)> OpenStringGetter_{[]() { return ""; }};
    std::string settings_{""};
    std::string openString_{""};
    CGateConnection *cgateConnection_{0};
    __stream_callback callback_;
    void *userContext_;
    cg_listener_t *listener_{0};

    CGateListener(CGateConnection &conn,
                  std::string settings,
                  __stream_callback callback,
                  void *userContext,
                  std::function<std::string(void)> OpenStringGetter);

    uint32_t CheckStateIfNeededOpen();

    void Close();

    void Destroy();

    ~CGateListener();
};

struct StreamRegime
{
    static const std::string Online;
    static const std::string SnapshotOnline;
    static const std::string Snapshot;
};

const std::string StreamRegime::Online = "online";
const std::string StreamRegime::SnapshotOnline = "snapshot+online";
const std::string StreamRegime::Snapshot = "snapshot";

struct Registrator
{
    static int Register(std::string name)
    {
        //std::cout << "register name: " << name << std::endl;
        return cgate_indexes[name];
    }
};

template <class, class = std::void_t<>>
struct HasInsert : std::false_type
{
};

template <class T>
struct HasInsert<T,
                 std::void_t<decltype(&T::Insert)>> : std::true_type
{
};

template <class, class = std::void_t<>>
struct HasCommit : std::false_type
{
};

template <class T>
struct HasCommit<T,
                 std::void_t<decltype(&T::Commit)>> : std::true_type
{
};

template <class, class = std::void_t<>>
struct HasGetHandler : std::false_type
{
};

template <class T>
struct HasGetHandler<T,
                     std::void_t<decltype(&T::GetHandler)>> : std::true_type
{
};

class CGateStream
{
public:
    std::string name_;
    std::string regime_{"snapshot+online"};
    CGateListener *lsn_{0};
    CGateConnection *conn_{0};
    std::function<void(std::string, int32_t lifenum)> lifeNumSetter_;
    std::function<int32_t(std::string)> lifeNumGetter_;
    std::map<int32_t, int64_t> revisionsFilter;

    __inserts inserts;
    __loaders loaders;
    __commits commits;
    __revisions revisions;
    bool online_{false};

    CGateStream(CGateConnection &conn, std::string name, std::string regime);

    CGateStream(CGateConnection &conn,
                std::string name,
                std::string regime,
                std::function<int32_t(std::string)> lifeNumGetter,
                std::function<void(std::string, int32_t lifenum)> lifeNumSetter);

    //create config from mode, lifeNumGetter, revisionsGetter,
    //set like openConnectionGetter for listener
    std::string GetConfig();

    int32_t GetLifenum();

    void SetLifenum(int32_t lifenum);

    uint32_t CheckStateIfNeededOpen();

    void Pipe(std::string name, std::function<void(void *)> insert)
    {
        std::string table_name = name_ + "/tables/" + name + "/index";
        //std::cout << "table_name = " << table_name << std::endl;
        int idx = Registrator::Register(table_name);
        inserts.insert({idx, insert});
    }

    void Pipe(std::string name, std::function<void(void *)> insert,
              std::function<int64_t(void)> revisionGetter)
    {
        std::string table_name = name_ + "/tables/" + name + "/index";
        //std::cout << "table_name = " << table_name << std::endl;
        int idx = Registrator::Register(table_name);
        inserts.insert({idx, insert});
        revisions.insert({name, revisionGetter});
    }

    template <typename T>
    constexpr void Pipe(std::string tableName, T &t)
    {
        //std::cout << "pipe" << std::endl;
        //1 check if it has GetHandler("table_name")
        if constexpr (HasGetHandler<T>::value)
        {
            //std::string _tableName = name_ + "/tables/" + tableName + "/index";
            //std::cout << "table_name = " << _tableName << std::endl;
            //int idx = Registrator::Register(_tableName);
            //auto insert = t.GetHandler(tableName);
            //inserts.insert({idx, insert});
            PipeHandler(tableName, t);
        }
        else
        {
            if constexpr (HasInsert<T>::value)
            {
                PipeInsert(tableName, t);
            }
            if constexpr (HasCommit<T>::value)
            {
                PipeCommit(tableName, t);
            }
        }
        //2 check if it have Insert, Commit
    }

    /*
    template <typename T>
    void Pipe(std::string table_name, T &t, std::function<int64_t(void)> revisionGetter)
    {
        if constexpr (HasGetHandler<T>::value)
        {
            //std::string _tableName = name_ + "/tables/" + tableName + "/index";
            //std::cout << "table_name = " << _tableName << std::endl;
            //int idx = Registrator::Register(_tableName);
            //auto insert = t.GetHandler(tableName);
            //inserts.insert({idx, insert});
            PipeHandler(tableName, t, revisionGetter);
        }
        else
        {
            if constexpr (HasInsert<T>::value)
            {
                PipeInsert(tableName, t, revisionGetter);
            }
            if constexpr (HasCommit<T>::value)
            {
                PipeCommit(tableName, t, revisionGetter);
            }
        }
    }*/

    void Insert(struct cg_msg_streamdata_t &replmsg);

    void InsertData(void *msg);

    void SetOnline();

    bool IsOnline();

    void Commit();

    void Close()
    {
        lsn_->Close();
    }

    void Destroy()
    {
        lsn_->Destroy();
    }

private:
    template <typename T>
    void PipeHandler(std::string tableName, T &t)
    {
        auto insert = t.GetHandler(tableName);
        std::string table_name = name_ + "/tables/" + tableName + "/index";
        //std::cout << "table_name = " << table_name << std::endl;
        int idx = Registrator::Register(table_name);
        //std::cout << "tableIndex : " << idx << std::endl;
        inserts.insert({idx, insert});
    }

    template <typename T>
    void PipeInsert(std::string tableName, T &t)
    {
        //std::cout << "pipe insert" << std::endl;
        std::string table_name = name_ + "/" + tableName;
        //std::cout << "table_name = " << table_name << std::endl;

        int idx = Registrator::Register(table_name);
        auto insert = [&t](void *data) {
            t.Insert(data);
        };
        inserts.insert({idx, insert});
    }

    template <typename T>
    void PipeCommit(std::string tableName, T &t)
    {
        std::cout << "pipe commit" << std::endl;
    }

    /*
    std::string GetName();

    template <typename T>
    void AddTableAndHandler(std::string name, T &t);

    template <typename T>
    void PipeTable(std::string name, T &t);

    void PipeInsert(std::string name, std::function<void(void *)> insert);

    void PipeInsert(std::string name, std::function<void(void *)> insert,
                    std::function<int64_t(void)> get_revision);

    template <typename I, typename L>
    void AddTableAndHandlers2(std::string name, I &i, L &l);

    //for repl
    void Insert(struct cg_msg_streamdata_t &replmsg);

    //for publisher
    void InsertData(void *data);

    void SetOnline();

    bool IsOnline();

    void Commit();

    void SetLifenumHandlers(std::function<void(std::string, int32_t lifenum)> lifenum_setter,
                            std::function<int32_t(std::string)> lifenum_getter);

    std::string GetConfig();

    int32_t GetLifenum();

    void SetLifenum(int32_t lifenum);

    template <typename T>
    std::string RestoreState(T &t);

    CGateListener &GetListener();

    void CloseListener();

    CGateConnection &GetConnection();

    uint32_t CheckStateIfNeededOpen();

    CGateListener &GetListener(CGateConnection &conn, __stream_callback callback);

    ~Stream();*/
};

CG_RESULT CgateCallback(cg_conn_t *conn, cg_listener_t *listener, struct cg_msg_t *msg, void *data)
{

    CGateStream *stream = (CGateStream *)data;
    //std::cout << "STREAM NAME!!!!!!!!!!!!!!!!!" << stream->name_ << std::endl;

    switch (msg->type)
    {
    case CG_MSG_STREAM_DATA:
    {

        struct cg_msg_streamdata_t *replmsg = (struct cg_msg_streamdata_t *)msg;
        //stream->Insert(*replmsg);
        //std::cout << "insert" << std::endl;
        std::cout << "CGateCallback: " << std::endl;
        stream->Insert(*replmsg);
        break;
    }
    case CG_MSG_P2REPL_ONLINE:
    {
        logger.info("cgate: %s stream is ONLINE", stream->name_.c_str());
        //stream->Process();
        //stream->SetOnline();
        //HandleOnlineTransitionState(user_data);
        stream->SetOnline();
        break;
    }
    case CG_MSG_TN_BEGIN:
        break;
    case CG_MSG_TN_COMMIT:
    {
        //stream->Process();
        stream->Commit();
        break;
    }
    case CG_MSG_OPEN:
    {
        logger.info("cgate: %s CG_MSG_OPEN", stream->name_.c_str());
        break;
    }
    case CG_MSG_CLOSE:
    {
        logger.info("cgate: %s CG_MSG_CLOSE", stream->name_.c_str());
        int *reason = (int *)msg->data;
        //ProcessCgateMsgClose(*reason);
        break;
    }
    case CG_MSG_P2REPL_LIFENUM:
    { //

        int *lifenum = (int *)msg->data;
        logger.info("cgate: %s change_lifenum %d", stream->name_.c_str(), *lifenum);
        stream->SetLifenum(*lifenum);
        break;
    }
    case CG_MSG_P2REPL_CLEARDELETED:
    {

        struct cg_data_cleardeleted_t *cleardeleted = (struct cg_data_cleardeleted_t *)msg->data;
        //stream->SetClearDeleted(cleardeleted->table_idx, cleardeleted->table_rev);
        if (cleardeleted->table_rev == CG_MAX_REVISON)
        {
            logger.info("cgate: %s CG_MSG_P2REPL_CLEARDELETED CG_MAX_REVISION table_idx %d", stream->name_.c_str(),
                        cleardeleted->table_idx);
        }
        else
        {
            logger.info("cgate: %s CG_MSG_P2REPL_CLEARDELETED table_idx %d rev %ld", stream->name_.c_str(),
                        cleardeleted->table_idx,
                        cleardeleted->table_rev);
        }
        break;
    }
    case CG_MSG_P2REPL_REPLSTATE:
    {
        //logger.info("cgate: %s replicat state %s", stream->name_.c_str(), (char *)msg->data);
        //stream->SetReplState(std::string((char *)msg->data));
        break;
    }
    default:
    {
        logger.info("cgate: %s Message 0x%X \n", stream->name_.c_str(), msg->type);
    }
    }

    return CG_ERR_OK;
}

CG_RESULT CgateOrderCallback(cg_conn_t *conn, cg_listener_t *listener, struct cg_msg_t *msg, void *data)
{
    //std::cout << "CgateOrderCallback " << std::endl;
    CGateStream *stream = (CGateStream *)data;
    //std::cout << "STREAM NAME!!!!!!!!!!!!!!!!!" << stream->name_ << std::endl;

    switch (msg->type)
    {
    case CG_MSG_DATA:
    {
        uint32_t *data = (uint32_t *)msg->data;
        logger.info("cgate: Client received reply [id:%d, data: %d, user-id: %d, name: %s]",
                    ((struct cg_msg_data_t *)msg)->msg_id,
                    *((uint32_t *)msg->data),
                    ((struct cg_msg_data_t *)msg)->user_id,
                    ((struct cg_msg_data_t *)msg)->msg_name);

        stream->InsertData(msg);

        /*{
			struct scheme_desc_t* scheme;
			size_t bufSize;
			
			if (cg_lsn_getscheme(listener, &scheme) != CG_ERR_OK)
				scheme = 0;
				
			if (cg_msg_dump(msg, scheme, 0, &bufSize) == CG_ERR_BUFFERTOOSMALL)
			{
				char* buffer = (char*)malloc(bufSize+1);
				
				bufSize++;
				if (cg_msg_dump(msg, scheme, buffer, &bufSize) == CG_ERR_OK)
					log_info("client dump: %s\n", buffer);
				free(buffer);
				
			}
		}*/
        break;
    }
    case CG_MSG_P2MQ_TIMEOUT:
    {
        logger.info("Client reply TIMEOUT\n");
        break;
    }
    case CG_MSG_STREAM_DATA:
    {

        struct cg_msg_streamdata_t *replmsg = (struct cg_msg_streamdata_t *)msg;
        //stream->Insert(*replmsg);
        //std::cout << "insert" << std::endl;
        stream->Insert(*replmsg);
        break;
    }
    case CG_MSG_P2REPL_ONLINE:
    {
        logger.info("cgate: %s stream is ONLINE", stream->name_.c_str());
        //stream->Process();
        //stream->SetOnline();
        //HandleOnlineTransitionState(user_data);
        stream->SetOnline();
        break;
    }
    case CG_MSG_TN_BEGIN:
        break;
    case CG_MSG_TN_COMMIT:
    {
        //stream->Process();
        stream->Commit();
        break;
    }
    case CG_MSG_OPEN:
    {
        logger.info("cgate: %s CG_MSG_OPEN", stream->name_.c_str());
        break;
    }
    case CG_MSG_CLOSE:
    {
        logger.info("cgate: %s CG_MSG_CLOSE", stream->name_.c_str());
        int *reason = (int *)msg->data;
        //ProcessCgateMsgClose(*reason);
        break;
    }
    case CG_MSG_P2REPL_LIFENUM:
    { //

        int *lifenum = (int *)msg->data;
        logger.info("cgate: %s change_lifenum %d", stream->name_.c_str(), *lifenum);
        //stream->SetLifenum(*lifenum);
        break;
    }
    case CG_MSG_P2REPL_CLEARDELETED:
    {

        struct cg_data_cleardeleted_t *cleardeleted = (struct cg_data_cleardeleted_t *)msg->data;
        //stream->SetClearDeleted(cleardeleted->table_idx, cleardeleted->table_rev);
        if (cleardeleted->table_rev == CG_MAX_REVISON)
        {
            logger.info("cgate: %s CG_MSG_P2REPL_CLEARDELETED CG_MAX_REVISION table_idx %d", stream->name_.c_str(),
                        cleardeleted->table_idx);
        }
        else
        {
            logger.info("cgate: %s CG_MSG_P2REPL_CLEARDELETED table_idx %d rev %ld", stream->name_.c_str(),
                        cleardeleted->table_idx,
                        cleardeleted->table_rev);
        }
        break;
    }
    case CG_MSG_P2REPL_REPLSTATE:
    {
        logger.info("cgate: %s replicat state %s", stream->name_.c_str(), (char *)msg->data);
        //stream->SetReplState(std::string((char *)msg->data));
        break;
    }
    default:
    {
        logger.info("cgate: %s Message 0x%X \n", stream->name_.c_str(), msg->type);
    }
    }

    return CG_ERR_OK;
}

template <typename... Args>
void AwaitUntilOnline(CGateConnection &conn, Args &&... args)
{
    std::vector<CGateStream *> streams{&args...};
    for (int i = 0; i < streams.size(); i++)
    {
        auto stream = streams[i];
        while (!stream->IsOnline())
        {
            auto state = conn.GetState();
            if (state == CG_STATE_ACTIVE)
            {
                conn.Process(1000);
                stream->CheckStateIfNeededOpen();
            }
        }
    }
}

template <typename... Args>
void RunStreamsForever(CGateConnection &conn, Args &&... args)
{
    //std::cout << "RunStreamsForever " << std::endl;
    std::vector<CGateStream *> streams{&args...};
    auto size = streams.size();
    while (true)
    {
        auto state = conn.GetState();
        if (state == CG_STATE_ACTIVE)
        {
            auto res = conn.Process(1000);
            if (res != -1)
            {
                for (int i = 0; i < size; i++)
                {
                    streams[i]->CheckStateIfNeededOpen();
                }
            }
        }
    }
}

template <typename T, typename... Args>
void RunStreamsForever(CGateConnection &conn, Publisher<T> &pub, Args &&... args)
{
    //std::cout << "RunStreamsForever " << std::endl;
    std::vector<CGateStream *> streams{&args...};
    auto size = streams.size();
    while (true)
    {
        auto state = conn.GetState();
        if (state == CG_STATE_ACTIVE)
        {
            auto res = conn.Process(1000);

            if (res != -1)
            {
                pub.CheckStateIfNeededOpen();
                for (int i = 0; i < size; i++)
                {
                    streams[i]->CheckStateIfNeededOpen();
                }
            }
        }
    }
}

template <typename... Args>
void CloseStreams(Args &&... args)
{
    std::vector<CGateStream *> streams{&args...};
    for (int i = 0; i < streams.size(); i++)
    {
        streams[i]->Close();
    }
}

template <typename... Args>
void CloseAndDestroyStreams(Args &&... args)
{
    std::vector<CGateStream *> streams{&args...};
    for (int i = 0; i < streams.size(); i++)
    {
        streams[i]->Close();
        streams[i]->Destroy();
    }
}

CGateEnvironment::CGateEnvironment(std::string settings)
{
    settings_ = settings;
    auto res = cg_env_open(settings_.c_str());

    if (res != CG_ERR_OK)
    {
        logger.error("cgate: ENV cg_env_open client gate error: %x", res);
        exit(EXIT_FAILURE);
    }
    logger.info("cgate: ENV opened");
}

CGateEnvironment::~CGateEnvironment()
{

    auto res = cg_env_close();

    if (res != CG_ERR_OK)
    {
        logger.error("cgate: ENV cg_env_close client gate error: %x", res);
        exit(EXIT_FAILURE);
    }
    logger.info("cgate: ENV closed");
}

CGateConnection::CGateConnection(std::string settings)
{
    settings_ = settings;
    auto res = cg_conn_new(settings_.c_str(), &conn_);

    if (res != CG_ERR_OK)
    {
        logger.error("cgate: CONNECTION cg_conn_new client gate error: %x", res);
        exit(EXIT_FAILURE);
    }

    logger.info("cgate: CONNECTION cg_conn_new");
}

uint32_t CGateConnection::GetState()
{
    uint32_t state;

    auto res = cg_conn_getstate(conn_, &state);

    if (res != CG_ERR_OK)
    {
        logger.warn("cgate: CONNECTION cg_conn_getstate error: %x", res);
        sleep(1);
    }

    if (state == CG_STATE_ERROR)
    {
        res = cg_conn_close(conn_);
        if (res != CG_ERR_OK)
        {
            logger.warn("cgate: CONNECTION cg_conn_close error: %x", res);
        }

        logger.error("cgate: CONNECTION change connection state to CG_STATE_ERROR");
        sleep(2);
    }
    else if (state == CG_STATE_CLOSED)
    {
        // WARN_FAIL(cg_conn_open(conn, 0));
        res = cg_conn_open(conn_, 0);
        if (res != CG_ERR_OK)
        {
            logger.warn("cgate: CONNECTION cg_conn_open error: %x", res);
            //когда роутер отключен
            sleep(2);
        }
    }
    else if (state == CG_STATE_OPENING)
    {
        logger.info("cgate: CONNECTION CG_STATE_OPENING");
        sleep(1);
    }

    return state;
}

int32_t CGateConnection::Process(uint32_t timeout)
{
    uint32_t result = cg_conn_process(conn_, timeout, 0);
    uint32_t state;
    if (result != CG_ERR_OK && result != CG_ERR_TIMEOUT)
    {
        cg_log_info("Warning: connection state request failed: %X", result);
        logger.warn("cgate: CONNECTION PROCESS connection state request failed: %X", result);
        return -1;
    }
    return result;
}

CGateConnection::~CGateConnection()
{
    //printf("~CGateConnection\n");
    /*if (conn)
        {
            printf("start \n");
            cg_conn_close(conn);
            printf("start \n");
            cg_conn_destroy(conn);

            //logger.info("cgate: CONNECTION cg_conn_closed");
        }*/
}

CGateListener::CGateListener(CGateConnection &conn,
                             std::string settings,
                             __stream_callback callback,
                             void *userContext,
                             std::function<std::string(void)> openStringGetter)
{
    cgateConnection_ = &conn;
    settings_ = settings;
    callback_ = callback;
    userContext_ = userContext;
    OpenStringGetter_ = openStringGetter;

    auto res = cg_lsn_new(cgateConnection_->conn_, settings_.c_str(), callback_, userContext, &listener_);

    if (res != CG_ERR_OK)
    {
        logger.error("cgate: LISTENER cg_lsn_new client gate error: %x", res);
        exit(EXIT_FAILURE);
    }

    logger.info("cgate: LISTENER cg_conn_new");
}

uint32_t CGateListener::CheckStateIfNeededOpen()
{

    uint32_t state;
    auto res = cg_lsn_getstate(listener_, &state);

    if (res != CG_ERR_OK)
    {
        logger.warn("cgate: LISTENER cg_lsn_getstate error: %x", res);
    }

    switch (state)
    {
    case CG_STATE_CLOSED:
    {
        char open_str[255];
        auto openString = OpenStringGetter_();
        logger.info("cgate: LISTENER  state CLOSED, try open with string = %s", openString.c_str());
        res = cg_lsn_open(listener_, openString.c_str());
        if (res != CG_ERR_OK)
        {
            logger.warn("cgate: LISTENER cg_lsn_close error: %x", res);
        }
        sleep(1);
        break;
    }
    case CG_STATE_ERROR:
    {
        cg_lsn_close(listener_);
        logger.error("cgate: LISTENER state ERROR");
        sleep(2);
        break;
    }
    }

    return state;
}

void CGateListener::Close()
{
    cg_lsn_close(listener_);
}

void CGateListener::Destroy()
{
    cg_lsn_destroy(listener_);
}

CGateListener::~CGateListener()
{
    Close();
    Destroy();
}

CGateStream::CGateStream(CGateConnection &conn, std::string name, std::string regime)
{
    conn_ = &conn;
    name_ = name;
    regime_ = regime;

    if (name_ == "FORTS_FUTCOMMON_REPL")
    {
        lsn_ = new CGateListener(conn,
                                 "p2repl://FORTS_FUTCOMMON_REPL;scheme=|FILE|../ini/fut_common.ini|FORTS_FUTCOMMON_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_OPTCOMMON_REPL")
    {
        lsn_ = new CGateListener(conn,
                                 "p2repl://FORTS_OPTCOMMON_REPL;scheme=|FILE|../ini/opt_common.ini|FORTS_OPTCOMMON_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_FUTINFO_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://FORTS_FUTINFO_REPL;scheme=|FILE|../ini/fut_info.ini|FORTS_FUTINFO_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_OPTINFO_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://FORTS_OPTINFO_REPL;scheme=|FILE|../ini/opt_info.ini|FORTS_OPTINFO_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_PART_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://FORTS_PART_REPL;scheme=|FILE|../ini/part.ini|FORTS_PART_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_POS_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://FORTS_POS_REPL;scheme=|FILE|../ini/pos.ini|FORTS_POS_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "MOEX_RATES_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://MOEX_RATES_REPL;scheme=|FILE|../ini/rates.ini|MOEX_RATES_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_FUTTRADE_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://FORTS_FUTTRADE_REPL;scheme=|FILE|../ini/fut_trades.ini|FORTS_FUTTRADE_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_OPTTRADE_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://FORTS_OPTTRADE_REPL;scheme=|FILE|../ini/opt_trades.ini|FORTS_OPTTRADE_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "MCXCC_MDCOMMON_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://MCXCC_MDCOMMON_REPL;scheme=|FILE|../ini/mcxcc_mdcommon.ini|MCXCC_MDCOMMON_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "MESSAGE_PUB")
    {
        lsn_ = new CGateListener(conn, "p2mqreply://;ref=servlink",
                                 CgateOrderCallback, this, [this]() { return ""; });
    }
    else
    {
        throw "unknown stream";
    }
}

CGateStream::CGateStream(CGateConnection &conn,
                         std::string name,
                         std::string regime,
                         std::function<int32_t(std::string)> lifeNumGetter,
                         std::function<void(std::string, int32_t lifenum)> lifeNumSetter)
{
    name_ = name;
    regime_ = regime;
    lifeNumGetter_ = lifeNumGetter;
    lifeNumSetter_ = lifeNumSetter;

    if (name_ == "FORTS_FUTCOMMON_REPL")
    {
        lsn_ = new CGateListener(conn,
                                 "p2repl://FORTS_FUTCOMMON_REPL;scheme=|FILE|../ini/fut_common.ini|FORTS_FUTCOMMON_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_OPTCOMMON_REPL")
    {
        lsn_ = new CGateListener(conn,
                                 "p2repl://FORTS_OPTCOMMON_REPL;scheme=|FILE|../ini/opt_common.ini|FORTS_OPTCOMMON_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_FUTINFO_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://FORTS_FUTINFO_REPL;scheme=|FILE|../ini/fut_info.ini|FORTS_FUTINFO_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_OPTINFO_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://FORTS_OPTINFO_REPL;scheme=|FILE|../ini/opt_info.ini|FORTS_OPTINFO_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_PART_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://FORTS_PART_REPL;scheme=|FILE|../ini/part.ini|FORTS_PART_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_POS_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://FORTS_POS_REPL;scheme=|FILE|../ini/pos.ini|FORTS_POS_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "MOEX_RATES_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://MOEX_RATES_REPL;scheme=|FILE|../ini/rates.ini|MOEX_RATES_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_FUTTRADE_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://FORTS_FUTTRADE_REPL;scheme=|FILE|../ini/fut_trades.ini|FORTS_FUTTRADE_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_OPTTRADE_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://FORTS_OPTTRADE_REPL;scheme=|FILE|../ini/opt_trades.ini|FORTS_OPTTRADE_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "MCXCC_MDCOMMON_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://MCXCC_MDCOMMON_REPL;scheme=|FILE|../ini/mcxcc_mdcommon.ini|MCXCC_MDCOMMON_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "MESSAGE_PUB")
    {
        lsn_ = new CGateListener(conn, "p2mqreply://;ref=servlink",
                                 CgateOrderCallback, this, [this]() { return ""; });
    }
    else
    {
        throw "unknown stream";
    }
}

int32_t CGateStream::GetLifenum()
{
    //std::cout << "GetLifenum " << std::endl;
    if (lifeNumGetter_)
    {
        //std::cout << "receive :::::::::::::::::: " << lifeNumGetter_(name_) << " >>>>>>>" << std::endl;
        return lifeNumGetter_(name_);
    }
    else
    {
        //::cout << "NO LIFENUM GETTER" << std::endl;
    }
    return 0;
}
void CGateStream::SetLifenum(int32_t lifenum)
{
    if (lifeNumSetter_)
    {
        lifeNumSetter_(name_, lifenum);
    }
}

uint32_t CGateStream::CheckStateIfNeededOpen()
{

    return lsn_->CheckStateIfNeededOpen();
}

std::string CGateStream::GetConfig()
{

    std::stringstream ss;
    ss << "mode=" << regime_ << ";";
    ss << "lifenum=" << GetLifenum() << ";";
    for (auto &kvp : revisions)
    {
        //get table_id
        auto table_revision = kvp.second();
        std::string table_name = name_ + "/tables/" + kvp.first + "/index";
        //std::cout << "table_name = " << table_name << std::endl;
        int idx = Registrator::Register(table_name);
        //std::cout << "table_idx " << idx << std::endl;
        if (table_revision > 0)
        {
            ss << "rev." << kvp.first << "=" << table_revision + 1 << ";";
            revisionsFilter.insert({idx, table_revision});
        }
        else
        {
            revisionsFilter.insert({idx, -1});
            ss << "rev." << kvp.first << "="
               << "0"
               << ";";
        }
    }
    return ss.str();
}

void CGateStream::Insert(struct cg_msg_streamdata_t &replmsg)
{

    int32_t msg_index = (int32_t)replmsg.msg_index;
    std::cout << "msg_index: " << msg_index << std::endl;
    std::cout << "start print current indexes " << std::endl;
    for (auto &i : inserts)
    {
        std::cout << "index: " << i.first << std::endl;
    }
    std::cout << "stop print current indexes " << std::endl;
    if (inserts.count(msg_index))
    {
        //std::cout << "Insert revision:" << replmsg.rev << std::endl;
        if (revisionsFilter[msg_index] < replmsg.rev)
        {
            revisionsFilter[msg_index] = replmsg.rev;
            inserts[msg_index]((void *)replmsg.data);
        }
        else
        {
            std::cout << "discard message with revision " << replmsg.rev << std::endl;
        }
    }
}

void CGateStream::InsertData(void *msg)
{
    struct cg_msg_data_t *replmsg = (struct cg_msg_data_t *)msg;
    auto msg_index = replmsg->msg_index;
    //std::cout << "Insert Data index = " << msg_index << std::endl;
    if (inserts.count(msg_index))
    {
        //std::cout << "exist for inserts , sould be updated" << std::endl;
        inserts[msg_index](msg);
    }
}

void CGateStream::SetOnline()
{
    online_ = true;
}

bool CGateStream::IsOnline()
{
    return online_;
}

void CGateStream::Commit()
{
    int i = 0;
    for (auto commit : commits)
    {
        commit(NULL);
    }
}

//Application Utils
struct SessionStorage
{
    struct IsinInfo
    {
        std::string symbol;

        IsinInfo()
        {
        }
        IsinInfo(std::string prefix, std::string symbol)
        {
            this->symbol = prefix + "@" + symbol;
        }
    };

    std::map<int32_t, IsinInfo> instruments;

    SessionStorage()
    {
    }

    bool isOnline{false};

    void HandleFutSessContents(FORTS_FUTINFO_REPL::fut_sess_contents &record)
    {
        auto symbol = std::string(record.isin);
        //auto isinInfo = IsinInfo("moex_forts", symbol);
        IsinInfo isinInfo("moex_forts", symbol);
        //std::cout << record.isin_id << " " << isinInfo.symbol << std::endl;
        instruments.insert({record.isin_id, isinInfo});
    }

    void HandleOptSessContents(FORTS_OPTINFO_REPL::opt_sess_contents &record)
    {
        auto symbol = std::string(record.isin);
        //auto isinInfo = IsinInfo("moex_opt", symbol);
        IsinInfo isinInfo("moex_opt", symbol);
        //std::cout << record.isin_id << " " << isinInfo.symbol << std::endl;
        instruments.insert({record.isin_id, isinInfo});
    }

    std::string GetFullSymbolByIsinId(int32_t isin_id)
    {
        if (instruments.count(isin_id))
        {
            return instruments[isin_id].symbol;
        }
        return "";
    }

    std::function<void(void *)> GetHandler(std::string table_name)
    {
        if (table_name == "fut_sess_contents")
        {
            auto lambda = [this](void *data) {
                FORTS_FUTINFO_REPL::fut_sess_contents *record = (FORTS_FUTINFO_REPL::fut_sess_contents *)data;
                this->HandleFutSessContents(*record);
            };
            return lambda;
        }
        else if (table_name == "opt_sess_contents")
        {
            auto lambda = [this](void *data) {
                FORTS_OPTINFO_REPL::opt_sess_contents *record = (FORTS_OPTINFO_REPL::opt_sess_contents *)data;
                this->HandleOptSessContents(*record);
            };
            return lambda;
        }
        else
        {
            return [&table_name](void *data) {
                std::cout << table_name << "  "
                          << "unknown handler for StreamInfoStorage" << std::endl;
            };
        }
    }
};

#endif // !__CGATE_YARD_HEADER__
