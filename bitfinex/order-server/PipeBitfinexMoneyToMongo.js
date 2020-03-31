require("dotenv").config();
const vfs = require("../vfs");

const MongoClient = require("mongodb").MongoClient;
class PipeBitfinexMoneyToMongo {
    constructor() {
        this.run = this.run.bind(this);
        this.updateBalance = this.updateBalance.bind(this);
        this.client = new MongoClient(process.env.MONGODB_URL, {
            native_parser: true
        });
        this.initialized = false;
        this._updateBalance = undefined;
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

        const updateBalance = async balance => {
            let result = await this.client
                .db("backend")
                .collection("money")
                .insertOne(balance);
        };

        this._isConnected = isConnected;
        this._updateBalance = updateBalance;

        this.initialized = true;
    }

    updateBalance(balance) {
        if (this._isConnected && this._isConnected() && this._updateBalance) {
            this._updateBalance(balance);
        } else {
            console.log("can't send order ");
        }
    }
}
const pipeBitfinexMoneyToMongo = new PipeBitfinexMoneyToMongo();
vfs["/money/online"] = pipeBitfinexMoneyToMongo.updateBalance;
