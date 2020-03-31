const tradeSubscribeAction = (ws, symbol) => {
    let msg = JSON.stringify({
        event: "subscribe",
        channel: "trades",
        symbol: symbol
    });
    ws.send(msg);
};

const tradeSubscribe = (ws, symbol) => {
    let msg = JSON.stringify({
        event: "subscribe",
        channel: "trades",
        symbol: symbol
    });
    ws.send(msg);
};

const tickerSubscribeAction = (ws, symbol) => {
    let msg = JSON.stringify({
        event: "subscribe",
        channel: "ticker",
        symbol: symbol
    });
    ws.send(msg);
};

const tickerSubscribe = (ws, symbol) => {
    let msg = JSON.stringify({
        event: "subscribe",
        channel: "ticker",
        symbol: symbol
    });
    ws.send(msg);
};

module.exports = {
    tradeSubscribeAction,
    tickerSubscribeAction,
    tradeSubscribe,
    tickerSubscribe
};
