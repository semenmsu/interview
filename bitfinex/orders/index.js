/*Order = {
    gid:1,
    cid:0,
    getcid : () => {
        let newcid = Date.now()
        Order.cid = newcid > Order.cid ? newcid : Order.cid +1
        return Order.cid
    },
    createLimit: (symbol, price, amount) => {
        return (
            [
                0,
                "on",
                null,
                {
                    "gid":1,
                    "cid": Order.getcid(),
                    "type":"EXCHANGE LIMIT",
                    "symbol":symbol,
                    "amount":amount.toString(),
                    "price":price.toString(),
                }
            ]
        )
    },
    createCancelByCid: (cid) => {
        return([
            0,
            "oc",
            null,
            {
              "cid": cid,
              "cid_date": "2018-04-24"
            }
        ])
    },
    createCancelById: (orderId) => {
        return([
            0,
            "oc",
            null,
            {
              "id": orderId
            }
          ])
    }
}

module.exports = Order*/
let cid = Date.now();

function GetCid() {
    let newcid = Date.now();
    cid = newcid > cid ? newcid : cid + 1;
    return cid;
}

function createLimitOrder(symbol, price, amount, gid = 1) {
    return [
        0,
        "on",
        null,
        {
            gid: gid,
            cid: GetCid(),
            type: "EXCHANGE LIMIT",
            symbol: symbol,
            amount: amount.toString(),
            price: price.toString()
        }
    ];
}

function createCancelOrderById(orderId) {
    return [
        0,
        "oc",
        null,
        {
            id: orderId
        }
    ];
}

function convertToTradeSymbol(symbol) {
    return `t${symbol}`;
}

function getSymbolFromTradeSymbol(tradeSymbol) {
    return tradeSymbol.slice(1);
}

function normilizePrice(price, symbol) {
    console.log("normilizePrice ", symbol, " ", price);
    if (symbol === "tZECBTC") {
        return price / 10000000;
    }
}

module.exports = {
    createLimitOrder,
    convertToTradeSymbol,
    getSymbolFromTradeSymbol,
    createCancelOrderById,
    normilizePrice
};
