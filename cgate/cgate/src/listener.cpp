#include <cgate.h>
#include <functional>
#include <unistd.h>
#include "../../utils/logger.h"
#include "../include/cgate-yard.hpp"

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
