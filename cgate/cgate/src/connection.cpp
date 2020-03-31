#include <string>
#include <cgate.h>
#include <unistd.h>
#include "../../utils/logger.h"
#include "../include/cgate-yard.hpp"

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