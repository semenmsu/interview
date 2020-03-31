const vfs = require("../vfs");

function GetTickerHandler(response) {
    const { channel, chanId, symbol, pair } = response;

    const eventTable = vfs["/ticker/table"];
    const tickerHandler = msg => {
        //console.log(msg);
        let [channelID, payload] = msg;
        if (payload == "hb") {
            return;
        }
        let [
            bid,
            bid_size,
            ask,
            ask_size,
            daily_change,
            deaily_change_perc,
            last_price,
            volume,
            high,
            low
        ] = payload;

        eventTable.update({
            pair,
            bid,
            bid_size,
            ask,
            ask_size,
            daily_change,
            deaily_change_perc,
            last_price,
            volume,
            high,
            low
        });
    };
    return tickerHandler;
}

module.exports = GetTickerHandler;
