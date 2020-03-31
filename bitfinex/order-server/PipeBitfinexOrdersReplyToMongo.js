const vfs = require("../vfs");
require("dotenv").config();
const { getSymbolFromTradeSymbol } = require("../orders");
const orderManager = vfs["/order_manager"];

const MongoClient = require("mongodb").MongoClient;
class PipeBitfinexOrdersReplyToMongo {
    constructor() {
        this.run = this.run.bind(this);
        this.sendOrder = this.sendOrder.bind(this);
        this.client = new MongoClient(process.env.MONGODB_URL, {
            native_parser: true
        });
        this.initialized = false;
        this._sendOrder = undefined;
        this._isConnected = undefined;
        this.run();
    }

    async run() {
        this.client = await this.client.connect();

        const isConnected = () => {
            return (
                !!this.client &&
                !!this.client.topology &&
                this.client.topology.isConnected()
            );
        };

        const sendOrder = async order => {
            console.log("sendOrder try:::::::::::::::::::::::::::::;;");
            let ext_id = orderManager.get_extid_and_remove(order.cid);
            if (ext_id) {
                order.ext_id = ext_id;
                let result = await this.client
                    .db("backend")
                    .collection("reply")
                    .insertOne(order);
            } else {
                console.log("ext_id undefined!!!!!");
            }
        };

        this._isConnected = isConnected;
        this._sendOrder = sendOrder;

        this.initialized = true;
    }

    sendOrder(order) {
        let symbol = "bitfinex@" + getSymbolFromTradeSymbol(order.symbol);
        order.symbol = symbol;
        if (this._isConnected && this._isConnected() && this._sendOrder) {
            this._sendOrder(order);
        } else {
            console.log("can't send order ");
        }
    }
}
const pipeBitfinexOrdersReplyToMongo = new PipeBitfinexOrdersReplyToMongo();
vfs["/orders/reply"] = pipeBitfinexOrdersReplyToMongo.sendOrder;
