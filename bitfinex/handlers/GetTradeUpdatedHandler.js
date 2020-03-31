const vfs = require("../vfs");

function GetTradeUpdatedHandler() {
    const eventTable = vfs["/orders/table"];
    const tradeUpdateHandler = data => {
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
            MAKER,
            FEE,
            FEE_CURRENCY
        ] = data;

        eventTable.update({
            type: "update_trade_reply",
            trade_id: ID,
            order_id: ORDER_ID,
            mts_create: MTS_CREATE,
            symbol: SYMBOL, //поправить symbol
            amount: EXEC_AMOUNT,
            price: EXEC_PRICE,
            order_type: ORDER_TYPE,
            order_price: ORDER_PRICE,
            maker: MAKER,
            fee: FEE,
            fee_currency: FEE_CURRENCY
        });
    };
    return tradeUpdateHandler;
}

module.exports = GetTradeUpdatedHandler;
