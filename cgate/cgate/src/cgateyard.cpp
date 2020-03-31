#include <string>
#include <cgate.h>
#include <unistd.h>
#include "../../utils/logger.h"
#include "../include/cgate-yard.hpp"

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
    printf("~CGateConnection\n");
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
        //lsn_ = new CGateListener(conn, "p2mqreply://;ref=servlink",
        //                         "", CgateCallback, this);
    }
    else
    {
        throw "unknown stream";
    }
}

int32_t CGateStream::GetLifenum()
{

    if (lifeNumGetter)
    {
        return lifeNumGetter(name_);
    }
    return 0;
}
void CGateStream::SetLifenum(int32_t lifenum)
{
    if (lifeNumSetter)
    {
        lifeNumSetter(name_, lifenum);
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
        std::cout << "table_name = " << table_name << std::endl;
        int idx = Registrator::Register(table_name);
        std::cout << "table_idx " << idx << std::endl;
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
    auto msg_index = replmsg.msg_index;

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
    std::cout << "Insert Data index = " << msg_index << std::endl;
    if (inserts.count(msg_index))
    {
        std::cout << "exist for inserts , sould be updated" << std::endl;
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
