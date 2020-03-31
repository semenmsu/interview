#ifndef __ZMQ_COMMON_SERVER__
#define __ZMQ_COMMON_SERVER__
#include <iostream>
#include <cgate.h>
#include <zmq.h>
#include <assert.h>
#include "../include/cgate-yard.hpp"

template <typename T>
char *ToJSON(std::string &symbol, T &t)
{
    char *buffer = (char *)malloc(256);
    sprintf(buffer, "{\"symbol\":\"%s\", \"bid\":\"%ld\", \"ask\":\"%ld\"}%c",
            symbol.c_str(),
            cg_bcd_to_int64(t.best_buy),
            cg_bcd_to_int64(t.best_sell),
            '\0');
    //std::cout << buffer << std::endl;
    return buffer;
}

struct ZmqCommonServer
{
    void *context;
    void *client;
    std::string host{"127.0.0.1"};
    std::string protocol{"tcp://"};
    std::string port{"5561"};
    std::string url_{"tcp://127.0.0.1:5561"};
    SessionStorage *storage_;

    ZmqCommonServer(SessionStorage &storage, std::string url)
    {
        if (url.length() > 0)
        {
            url_ = url;
        }
        storage_ = &storage;
        context = zmq_ctx_new();
        client = zmq_socket(context, ZMQ_PUB);
        int rc = zmq_bind(client, url_.c_str());
        if (rc == -1)
        {
            std::cout << "error" << std::endl;
        }
        assert(rc == 0);
    }

    void HandleCommonFut(FORTS_FUTCOMMON_REPL::common &record)
    {
        std::string symbol = storage_->GetFullSymbolByIsinId(record.isin_id);
        if (symbol.length() > 0)
        {
            char *json_msg = ToJSON<FORTS_FUTCOMMON_REPL::common>(symbol, record);
            std::string full_symbol = symbol + "!";
            zmq_send(client, full_symbol.c_str(), full_symbol.length(), ZMQ_SNDMORE);
            zmq_send(client, json_msg, strlen(json_msg), 0);
            delete json_msg;
        }
    }

    void HandleCommonOpt(FORTS_OPTCOMMON_REPL::common &record)
    {
        std::string symbol = storage_->GetFullSymbolByIsinId(record.isin_id);
        if (symbol.length() > 0)
        {
            char *json_msg = ToJSON<FORTS_OPTCOMMON_REPL::common>(symbol, record);
            std::string full_symbol = symbol + "!";
            zmq_send(client, full_symbol.c_str(), full_symbol.length(), ZMQ_SNDMORE);
            zmq_send(client, json_msg, strlen(json_msg), 0);
            delete json_msg;
        }
    }

    //одинаковые названия для таблиц(
    std::function<void(void *)> GetHandler(std::string sub_exchange)
    {
        if (sub_exchange == "fut")
        {
            auto lambda = [this](void *data) {
                FORTS_FUTCOMMON_REPL::common *record = (FORTS_FUTCOMMON_REPL::common *)data;
                this->HandleCommonFut(*record);
            };
            return lambda;
        }
        else if (sub_exchange == "opt")
        {
            auto lambda = [this](void *data) {
                FORTS_OPTCOMMON_REPL::common *record = (FORTS_OPTCOMMON_REPL::common *)data;
                this->HandleCommonOpt(*record);
            };
            return lambda;
        }
        else
        {
            auto lambda = [this](void *data) {
                std::cout << "Not Implemented" << std::endl;
            };
            return lambda;
        }
    }

    ~ZmqCommonServer()
    {
        if (client)
        {
            zmq_close(client);
        }
        if (context)
        {
            zmq_ctx_destroy(context);
        }
    }
};
#endif // !__ZMQ_COMMON_SERVER__
