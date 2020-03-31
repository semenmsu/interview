#include <iostream>
#include <cgate.h>
#include <zmq.h>
#include <assert.h>
#include "../../cgate/include/cgate-yard.hpp"
#include "../../cgate/helpers/zmq_common_server.hpp"

int main()
{
    CGateEnvironment env("ini=../config/common.ini;key=11111111");
    //"p2tcp://%s:%s;local_pass=%s;app_name=%s
    CGateConnection conn("p2tcp://127.0.0.1:4001;local_pass=123;app_name=common_server");
    SessionStorage storage;
    ZmqCommonServer server(storage, "tcp://127.0.0.1:5561");
    CGateStream futInfo(conn, "FORTS_FUTINFO_REPL", "snapshot+online");
    CGateStream optInfo(conn, "FORTS_OPTINFO_REPL", "snapshot+online");
    CGateStream futCommon(conn, "FORTS_FUTCOMMON_REPL", "online");
    CGateStream optCommon(conn, "FORTS_OPTCOMMON_REPL", "online");
    futInfo.Pipe("fut_sess_contents", storage);
    optInfo.Pipe("opt_sess_contents", storage);
    futCommon.Pipe("common", server.GetHandler("fut"));
    optCommon.Pipe("common", server.GetHandler("opt"));
    AwaitUntilOnline(conn, futInfo, optInfo);
    CloseAndDestroyStreams(futInfo, optInfo);
    RunStreamsForever(conn, optCommon, futCommon);
    return 0;
}
