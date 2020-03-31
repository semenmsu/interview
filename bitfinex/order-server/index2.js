require("dotenv").config();
require("./PipeBitfinexOrdersReplyToMongo"); //не нравится
require("./PipeBitfinexMoneyToMongo");
require("./PipeBitfinexWalletsToMongo");
const WebSocket = require("ws");
const vfs = require("../vfs");
const PipeMongoOrderToBitfinex = require("./PipeMongoOrdersToBitfinex"); //не нравится, что так надо объявлять
const createAuthMessage = require("../auth/createAuthMessage");
const { GetAuthChannelHandler } = require("../handlers");
const { logger } = require("./Logger");

const ws = new WebSocket("wss://api.bitfinex.com/ws/2");
const pipeOrdersToBitfinex = new PipeMongoOrderToBitfinex(ws);

let channels = {};
let handlers = {};

ws.once("open", () => {
    const authMessage = createAuthMessage();
    console.log(authMessage);
    ws.send(authMessage);
});

let authenticated = false;
let channelId = undefined;
let status = undefined;

ws.on("message", message => {
    //console.log("message", message);
    //message = JSON.parse(message);
    let msg = JSON.parse(message);
    let { event, chanId } = msg;
    console.log(msg);
    if (event) {
        if (event === "auth") {
            authenticated = true;
            channelId = chanId;
            status = msg.status;
            handlers["on"] = GetAuthChannelHandler("on");
            handlers["oc"] = GetAuthChannelHandler("oc");
            handlers["ou"] = GetAuthChannelHandler("ou");
            handlers["os"] = GetAuthChannelHandler("os");
            handlers["te"] = GetAuthChannelHandler("te");
            handlers["tu"] = GetAuthChannelHandler("tu");
            handlers["bu"] = GetAuthChannelHandler("bu");
            handlers["wu"] = GetAuthChannelHandler("wu");
            handlers["ws"] = GetAuthChannelHandler("ws");
        }
    } else {
        if (channelId != undefined) {
            let [chanId, channelType, data] = msg;
            let handler = handlers[channelType];
            if (handler) {
                handler(data);
            }
        }
    }
    logger.info(message);
});

//message {"event":"info","version":2,"serverId":"26ffbc84-40d8-4427-a335-7cf6958a0923","platform":{"status":1}}
//message {"event":"auth","status":"OK","chanId":0,"userId":634574,"auth_id":"3b28b5e3-8799-4979-9d6a-6a5ec1f163fd","caps":{"orders":{"read":1,"write":1},"account":{"read":1,"write":0},"funding":{"read":1,"write":1},"history":{"read":1,"write":0},"wallets":{"read":1,"write":1},"withdraw":{"read":0,"write":0},"positions":{"read":1,"write":1}}}

ws.on("close", (code, reason) => {
    logger.info({ code, reason });
    authenticated = false;
});

ws.on("error", err => {
    logger.info({ err });
    authenticated = false;
});

//не очень удачные названия, надо переработать
vfs["/orders/table"].subscribe(vfs["/orders/reply"]);
vfs["/money/table"].subscribe(vfs["/money/online"]);
vfs["/wallets/table"].subscribe(vfs["/wallets/snapshot_online"]);

/*
w.on("message", msg => {
    console.log("on message");
    msg = JSON.parse(msg);
    let { event, chanId } = msg;

    if (event == "subscribed") {
        chanId = parseInt(chanId);
        channels[chanId] = GetChannelHandler(msg);
    }

    if (!event) {
        let [channelID, ...rest] = msg;
        channelID = parseInt(channelID);
        let handler = channels[channelID];
        if (handler) {
            console.log("handle message");
            handler(msg);
        }
    }
});*/
