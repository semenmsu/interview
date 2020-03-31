#include <iostream>
#include <cgate.h>
#include <zmq.h>
#include <assert.h>
#include <thread>
#include <mutex>
#include "../../cgate/include/cgate-yard.hpp"
#include "../../cgate/helpers/mongodb.hpp"
#include "../../cgate/include/order_reply.hpp"
#include "../cgate/include/order.hpp"
#include "../cgate/include/publisher.hpp"

struct ReplyDown
{
    MongoClient *client_;
    MongoCollection *collection_;
    std::string gateway_name_{"gw-cgate"};

    ReplyDown(std::map<std::string, std::string> &settings)
    {

        std::string url = settings["url"];
        std::string db_name = settings["db_name"];
        std::string collection_name = settings["collection_name"];
        gateway_name_ = settings["gw-name"];
        client_ = new MongoClient(url);
        collection_ = new MongoCollection(*client_, db_name, collection_name);
    }

    template <typename T>
    void Down(T &t)
    {
        std::cout << to_csv(t) << std::endl;
        auto bson_ = to_bson(t);
        BSON_APPEND_UTF8(*bson_, "from", gateway_name_.c_str());
        size_t len;
        char *str = bson_as_canonical_extended_json(*bson_, &len);
        //printf("%s\n", str);
        logger.info("cgate REPLY: %s", str);
        collection_->InsertOne(*bson_);
        bson_free(str);
        //save to mongo
    }

    void Down(OrderReply &reply)
    {
        auto bson_ = reply.toBSON();
        BSON_APPEND_UTF8(bson_, "from", gateway_name_.c_str());
        size_t len;
        char *str = bson_as_canonical_extended_json(bson_, &len);
        logger.info("cgate: REPLY: %s", str);
        collection_->InsertOne(bson_);
        bson_free(str);
        //save to mongo
    }

    void Down(SpamReply &reply)
    {
        auto bson_ = reply.toBSON();
        BSON_APPEND_UTF8(bson_, "from", gateway_name_.c_str());
        size_t len;
        char *str = bson_as_canonical_extended_json(bson_, &len);
        logger.info("cgate: REPLY: %s", str);
        collection_->InsertOne(bson_);
        bson_free(str);
        //save to mongo
    }

    ~ReplyDown()
    {
        if (client_)
        {
            delete client_;
        }
        if (collection_)
        {
            delete collection_;
        }
    }
};

struct OrderUp
{
    MongoClient *client_;
    MongoChangeStream *changeStream_;
    std::string watch_filter_ = "";
    OrderUp(std::string url, std::string db_name, std::string collection_name)
    {
        client_ = new MongoClient("mongodb://172.26.1.2:27017,172.26.1.3:27018/test?replicaSet=rs0");
        changeStream_ = new MongoChangeStream(*client_, db_name, collection_name);
    }

    OrderUp(std::map<std::string, std::string> &settings)
    {
        std::string url = settings["url"];
        std::string db_name = settings["db_name"];
        std::string collection_name = settings["collection_name"];
        watch_filter_ = settings["watch"];

        client_ = new MongoClient(url);
        changeStream_ = new MongoChangeStream(*client_, db_name, collection_name);
    }

    void Watch(__change_stream_callback callback)
    {
        changeStream_->Watch(watch_filter_, callback);
    }

    ~OrderUp()
    {
        if (client_)
        {
            delete client_;
        }
        if (changeStream_)
        {
            delete changeStream_;
        }
    }
};

void Watch(OrderUp &receiver, Publisher<ReplyDown> &publisher)
{
    receiver.Watch(publisher.GetOrderHandler());
}

int main()
{
    MongoInitializer();
    std::map<std::string, std::string> orderUpSettings{{"url", "mongodb://172.26.1.2:27017,172.26.1.3:27018/test?replicaSet=rs0"},
                                                       {"db_name", "test"},
                                                       {"collection_name", "test"},
                                                       {"watch", "cgate-gw"}};
    std::map<std::string, std::string> replyDownSettings{{"url", "mongodb://172.26.1.2:27017,172.26.1.3:27018/test?replicaSet=rs0"},
                                                         {"db_name", "test"},
                                                         {"collection_name", "test"},
                                                         {"gw-name", "cgate-gw"}};
    std::map<std::string, std::string> publisherSettings{{"url", "mongodb://172.26.1.2:27017,172.26.1.3:27018/test?replicaSet=rs0"},
                                                         {"db_name", "test"},
                                                         {"collection_name", "test"},
                                                         {"name", "pub"},
                                                         {"broker_code", "FZ00"},
                                                         {"client_code", "FB3"},
                                                         {"config", "p2mq://FORTS_SRV;category=FORTS_MSG;name=servlink;timeout=5000;scheme=|FILE|../ini/forts_messages.ini|MESSAGE_PUB"}};

    OrderUp orderUp(orderUpSettings);
    ReplyDown replyDown(replyDownSettings);
    Publisher publisher(publisherSettings, replyDown);
    std::thread watch(Watch, std::ref(orderUp), std::ref(publisher));

    //cgate part
    CGateEnvironment env("ini=../config/order_router.ini;key=11111111");
    CGateConnection conn("p2tcp://127.0.0.1:4001;local_pass=123;app_name=order_router");
    CGateStream orders(conn, "MESSAGE_PUB", "");
    orders.Pipe("FORTS_MSG101", publisher);
    orders.Pipe("FORTS_MSG102", publisher);
    orders.Pipe("FORTS_MSG103", publisher);
    orders.Pipe("FORTS_MSG105", publisher);
    orders.Pipe("FORTS_MSG109", publisher);
    orders.Pipe("FORTS_MSG110", publisher);
    orders.Pipe("FORTS_MSG111", publisher);
    orders.Pipe("FORTS_MSG113", publisher);
    orders.Pipe("CODHeartbeat", publisher);
    orders.Pipe("FORTS_MSG99", publisher);
    orders.Pipe("FORTS_MSG100", publisher);

    publisher.Init(conn.conn_);
    RunStreamsForever(conn, publisher, orders);
    watch.join();
    return 0;
}