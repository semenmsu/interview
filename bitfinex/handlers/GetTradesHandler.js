const vfs = require("../vfs");

function GetTradesHandler(response) {
    const { channel, chanId, symbol, pair } = response;

    const eventTable = vfs["/trades/table"];
    let id = 0;
    const tradesHandler = msg => {
        //console.log(type);
        //console.log(channel, chanId, symbol, pair, msg);
        console.log(msg);
        let [channelID, payload, rest] = msg;
        if (payload == "hb") {
            return;
        }
        //console.log(msg);
        if (id == 0) {
            for (let trade of payload) {
                //console.log("sn ", symbol, " ", trade);
                let [id, mts, amount, price] = trade;
                eventTable.update({
                    type: "sn",
                    symbol,
                    id,
                    mts,
                    amount,
                    price
                });
            }
        } else if (payload == "te") {
            //console.log("te ", symbol, " ", msg);
            //console.log("rest ", rest);
            let [id, mts, amount, price] = rest;
            eventTable.update({
                type: "te",
                symbol,
                id,
                mts,
                amount,
                price
            });
        } else if (payload == "tu") {
            //console.log("tu ", symbol, " ", msg);
            let [id, mts, amount, price] = rest;
            eventTable.update({
                type: "tu",
                symbol,
                id,
                mts,
                amount,
                price
            });
        }
        id++;
        //eventTable.update(msg);
    };
    return tradesHandler;
}

module.exports = GetTradesHandler;
