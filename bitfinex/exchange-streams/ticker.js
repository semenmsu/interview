const { tickerSubscribeAction } = require("../actions2");

const transformToL1DataYardStream = message => {
    const { pair, bid, ask } = message;
    const symbol = `bitfinex@${pair}`;
    let zmqMsg = {
        symbol,
        bid: parseFloat(bid) * 10000000,
        ask: parseFloat(ask) * 10000000
    };
    return { symbol, message: zmqMsg };
};

const GetTickerPipe = provider => {
    if (provider === "zeromq") {
        var zmq = require("zeromq");
        let socket = zmq.socket("pub");
        socket.bind("tcp://127.0.0.1:15562");
        const pipeToL1DataYardStream2 = ticker => {
            let { symbol, message } = transformToL1DataYardStream(ticker);
            console.log(symbol, message);
            socket.send([symbol + "!", JSON.stringify(message)]);
        };
        return pipeToL1DataYardStream2;
    }
};

const tickerSubscribe = (ws, symbol) => {
    let msg = tickerSubscribeAction(symbol);
    ws.send(msg);
};

const subscribe = tickerSubscribe;

const GetPipe = GetTickerPipe;

module.exports = {
    GetTickerPipe,
    GetPipe,
    subscribe,
    tickerSubscribe
};
