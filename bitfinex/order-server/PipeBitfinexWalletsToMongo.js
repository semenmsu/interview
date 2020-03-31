require("dotenv").config();
const vfs = require("../vfs");

const MongoClient = require("mongodb").MongoClient;
class PipeBitfinexWalletsToMongo {
    constructor() {
        this.run = this.run.bind(this);
        this.updateWallet = this.updateWallet.bind(this);
        this.client = new MongoClient(process.env.MONGODB_URL, {
            native_parser: true
        });
        this.initialized = false;
        this._updateWallet = undefined;
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

        const updateWallet = async wallet => {
            let result = await this.client
                .db("backend")
                .collection("wallets")
                .insertOne(wallet);
        };

        this._isConnected = isConnected;
        this._updateWallet = updateWallet;

        this.initialized = true;
    }

    updateWallet(balance) {
        if (this._isConnected && this._isConnected() && this._updateWallet) {
            this._updateWallet(balance);
        } else {
            console.log("can't send order ");
        }
    }
}
const pipeBitfinexWalletsToMongo = new PipeBitfinexWalletsToMongo();
vfs["/wallets/snapshot_online"] = pipeBitfinexWalletsToMongo.updateWallet;
