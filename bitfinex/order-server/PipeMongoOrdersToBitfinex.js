const vfs = require("../vfs");
require("dotenv").config();
const MongoClient = require("mongodb").MongoClient;
const {
    createLimitOrder,
    convertToTradeSymbol,
    createCancelOrderById
} = require("../orders");
const orderManager = vfs["/order_manager"];

function normilizePrice(price, symbol) {
    console.log("normilizePrice ", symbol, " ", price);
    if (symbol === "tZECBTC") {
        return price / 10000000;
    }
}
class PipeMongoOrdersStreamToBitfinex {
    constructor(ws) {
        this.mongoClient = new MongoClient(process.env.MONGODB_URL, {
            native_parser: true,
            useNewUrlParser: true,
            useUnifiedTopology: true
        });
        this.ws = ws;

        this.pipeline2 = [
            {
                $match: { "fullDocument.exchange": "bitfinex" }
            },
            {
                $project: { documentKey: false }
            }
        ];

        this.pipeline = [
            {
                $match: { "fullDocument.to": "bitfinex-gw" }
            },
            {
                $project: { documentKey: false }
            }
        ];

        this.client = undefined;

        this.isConnected = () => {
            return client && topology && client.topology.isConnected();
        };

        this.connect = this.connect.bind(this);

        this.connect();
    }

    async connect() {
        //while (true) {
        try {
            this.client = await this.mongoClient.connect();
            //const changeStream = this.client
            //    .db("backend")
            //    .collection("orders")
            //    .watch(this.pipeline);
            const changeStream = this.client
                .db("test")
                .collection("test")
                .watch(this.pipeline);

            changeStream.on("change", change => {
                console.log(change);

                const { fullDocument } = change;
                const {
                    symbol,
                    price,
                    dir,
                    amount,
                    type,
                    exchange,
                    ext_id
                } = fullDocument;
                if (type == "new_order") {
                    //let [exchange_, symbol_] = symbol.split("@");
                    let exchange_ = exchange;
                    let symbol_ = convertToTradeSymbol(symbol);
                    let amount_ = parseFloat(amount);
                    //let price_ = parseFloat(price);
                    let price_ = normilizePrice(parseInt(price), symbol_);

                    if (dir == "2") {
                        amount_ = -amount_;
                    }

                    //if (dir == "SELL") {
                    //    amount_ = -amount_;
                    //}
                    console.log(
                        `@@@@@@@@@@@@@@@@@@@   ${exchange_} ${symbol_} amount = ${amount_} price = ${price_}`
                    );
                    const order = createLimitOrder(symbol_, price_, amount_);
                    console.log("ws.Open ", this.ws.OPEN);
                    if (this.ws.readyState == this.ws.OPEN) {
                        orderManager.add(ext_id, order[3]);
                        this.ws.send(JSON.stringify(order));
                    } else {
                        console.log(
                            "ws not ready state = ",
                            this.ws.readyState
                        );
                    }
                    console.log(order);
                } else if (type == "cancel_order") {
                    //let [exchange_, symbol_] = symbol.split("@");
                    //symbol_ = convertToTradeSymbol(symbol_);
                    let exchange_ = exchange;
                    let symbol_ = convertToTradeSymbol(symbol);
                    const { order_id } = fullDocument;
                    console.log("cancel ", symbol_, " ", order_id);
                    const cancelOrder = createCancelOrderById(order_id);
                    console.log(cancelOrder);
                    if (this.ws.readyState == this.ws.OPEN) {
                        this.ws.send(JSON.stringify(cancelOrder));
                    } else {
                        console.log(
                            "ws not ready state = ",
                            this.ws.readyState
                        );
                    }
                }
            });
            return;
        } catch (error) {
            console.log(error);
            setTimeout(() => {
                this.connect();
            }, 1000);
        }
    }
}

/*let mongoClient = new MongoClient(process.env.MONGODB_URL, {
    native_parser: true,
    useNewUrlParser: true,
    useUnifiedTopology: true
});

let client = undefined;
const pipeline = [
    {
        $match: { "fullDocument.exchange": "bitfinex" }
    },
    {
        $project: { documentKey: false }
    }
];*/

/*
async function connect() {
    //while (true) {
    try {
        client = await mongoClient.connect();
        const changeStream = client
            .db("backend")
            .collection("orders")
            .watch(pipeline);

        changeStream.on("change", change => {
            console.log(change);
            const { fullDocument } = change;
            const { symbol, price, dir, amount, type } = fullDocument;
            let [exchange_, symbol_] = symbol.split("@");
            symbol_ = convertToTradeSymbol(symbol_);
            let amount_ = parseFloat(amount);
            amount_ = 0.06;
            const price_ = parseFloat(price);
            if (dir == "SELL") {
                amount_ = -amount_;
            }
            const order = createLimitOrder(symbol_, price_, amount_);
            console.log("ws.Open ", ws.OPEN);
            if (ws.readyState == ws.OPEN) {
                ws.send(JSON.stringify(order));
            } else {
                console.log("ws not ready state = ", ws.readyState);
            }
            console.log(order);
        });
        return;
    } catch (error) {
        console.log(error);
        setTimeout(() => {
            connect();
        }, 1000);
    }
    //}
}*/

/*
const isConnected = () => {
    return client && topology && client.topology.isConnected();
};*/

//connect();

module.exports = PipeMongoOrdersStreamToBitfinex;
