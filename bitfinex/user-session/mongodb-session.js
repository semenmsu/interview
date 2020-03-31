const transformToOrdersReplyYardStream = message => {};

const MongoClient = require("mongodb").MongoClient;

//сделит за соединением с бд и перенаправляет оредра, это всё
class UserSession {
    constructor(orderManager) {
        this.client = new MongoClient(process.env.MONGODB_URL, {
            native_parser: true,
            useUnifiedTopology: true,
            useNewUrlParser: true
        });
        this.orderManager = orderManager;
        this.toUser = this.toUser.bind(this);
        this.initialized = false;
        this.isConnected = undefined;
        this.run = this.run.bind(this);
        this.startStreamFromUser = this.startStreamFromUser.bind(this);
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
        this.isConnected = isConnected;
        this.initialized = true;
        await this.startStreamFromUser();
    }

    async startStreamFromUser() {
        this.pipeline = [
            {
                $match: { "fullDocument.to": "bitfinex-gw" }
            },
            {
                $project: { documentKey: false }
            }
        ];

        try {
            const changeStream = this.client
                .db("test")
                .collection("test")
                .watch(this.pipeline);

            changeStream.on("change", change => {
                console.log(change);
                const { fullDocument } = change;
                this.orderManager.pipeOrders(fullDocument)
            });
            return;
        } catch (error) {
            console.log(error);
            setTimeout(() => {
                this.connect();
            }, 1000);
        }
    }

    async toUser(table, message) {
        //new_reply //orders
        //cancel_reply //orders
        //trades
        if (this.isConnected) {
            if (table === "orders") {
                let result = await this.client
                    .db("backend")
                    .collection("reply")
                    .insertOne(message);
            } else if (table === "trades") {
                let result = await this.client
                    .db("backend")
                    .collection("trades")
                    .insertOne(message);
            }
        }
    }
}

module.exports = {
    UserSession
};
