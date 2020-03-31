#include <iostream>
#include <cgate.h>
#include <zmq.h>
#include <assert.h>
#include <functional>
#include "../../cgate/include/cgate-yard.hpp"
#include "../../cgate/helpers/smart_session_storage.hpp"
#include "../../cgate/helpers/mongodb.hpp"

template <>
void SmartMongoStream::Insert<FORTS_PART_REPL::part>(void *data)
{
    //std::cout << "FORTS_PART_REPL" << std::endl;
    FORTS_PART_REPL::part *t = (FORTS_PART_REPL::part *)data;
    auto _bson = to_bson(*t);
    collection_->InsertOne(*_bson);
}
template <>
void SmartMongoStream::Insert<FORTS_POS_REPL::position>(void *data)
{
    //std::cout << "FORTS_POS_REPL" << std::endl;
    FORTS_POS_REPL::position *t = (FORTS_POS_REPL::position *)data;
    auto _bson = to_bson(*t);
    auto symbol = sessionStorage_->GetFullSymbolByIsinId(t->isin_id); //session->isinid2symbol[t->isin_id];
    BSON_APPEND_UTF8(*_bson, "symbol", symbol.c_str());
    collection_->InsertOne(*_bson);
}
int main()
{
    MongoInitializer();
    std::map<std::string, std::string> posSettings{{"url", "mongodb://172.26.1.2:27017,172.26.1.3:27018/test?replicaSet=rs0"},
                                                   {"db_name", "test"},
                                                   {"collection_name", "pos"},
                                                   {"gw-name", "cgate-gw"}};
    std::map<std::string, std::string> partSettings{{"url", "mongodb://172.26.1.2:27017,172.26.1.3:27018/test?replicaSet=rs0"},
                                                    {"db_name", "test"},
                                                    {"collection_name", "part"},
                                                    {"gw-name", "cgate-gw"}};
    SmartSessionStorage storage;
    SmartMongoStream posMongoStream(storage, posSettings);
    SmartMongoStream partMongoStream(storage, partSettings);
    CGateEnvironment env("ini=../config/part_pos.ini;key=11111111");
    CGateConnection conn("p2tcp://127.0.0.1:4001;local_pass=123;app_name=pos_server");
    std::function<void(void *)> posHandler = [&posMongoStream](void *data) { posMongoStream.Insert<FORTS_POS_REPL::position>(data); };
    std::function<void(void *)> partHandler = [&partMongoStream](void *data) { partMongoStream.Insert<FORTS_PART_REPL::part>(data); };
    CGateStream pos(conn, "FORTS_POS_REPL", "snapshot+online");
    CGateStream part(conn, "FORTS_PART_REPL", "snapshot+online");
    pos.Pipe("position", posHandler);
    part.Pipe("part", partHandler);
    storage.Init(conn);
    RunStreamsForever(conn, pos, part);
    return 0;
}