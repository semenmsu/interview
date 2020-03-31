const tradeSubscribeAction = symbol => {
    let msg = JSON.stringify({
        event: "subscribe",
        channel: "trades",
        symbol: symbol
    });
    return msg;
};

const tickerSubscribeAction = symbol => {
    let msg = JSON.stringify({
        event: "subscribe",
        channel: "ticker",
        symbol: symbol
    });
    return msg;
};

module.exports = {
    tradeSubscribeAction,
    tickerSubscribeAction
};
