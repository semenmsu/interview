const vfs = require("../vfs");

function GetTradeExecutedHandler() {
    const eventTable = vfs["/orders/table"];
    const tradeExecutedHandler = data => {
        //console.log(msg);

        let [
            ID,
            SYMBOL,
            MTS_CREATE,
            ORDER_ID,
            EXEC_AMOUNT,
            EXEC_PRICE,
            ORDER_TYPE,
            ORDER_PRICE,
            MAKER
        ] = data;

        eventTable.update({
            type: "trade_reply",
            mts_create: MTS_CREATE,
            id: ID,
            order_id: ORDER_ID,
            symbol: SYMBOL, //поправить symbol
            amount: EXEC_AMOUNT,
            price: EXEC_PRICE,
            order_type: ORDER_TYPE,
            order_price: ORDER_PRICE,
            maker: MAKER
        });
    };
    return tradeExecutedHandler;
}

module.exports = GetTradeExecutedHandler;
