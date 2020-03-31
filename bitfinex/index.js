const ws = require("ws");
const vfs = require("./vfs");
const { GetChannelHandler } = require("./handlers");

const { tradeSubscribeAction, tickerSubscribeAction } = require("./actions");

const w = new ws("wss://api-pub.bitfinex.com/ws/2");

channels = {};

vfs["/trades/subscribe"] = tradeSubscribeAction;
vfs["/ticker/subscribe"] = tickerSubscribeAction;
vfs["/books/subscribe"] = "";
vfs["/rawbooks/subscribe"] = "";
vfs["/candles/subscribe"] = "";
vfs["/status/subscribe"] = "";


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
});

w.once("open", () => {
    //vfs["/trades/subscribe"](w, "tBTCUSD");
    vfs["/ticker/subscribe"](w, "tBTCUSD");
});

w.on("close", () => {
    console.log("connection closed");
});
