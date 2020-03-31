#include <string>
#include <cgate.h>
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