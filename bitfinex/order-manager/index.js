const {
    createLimitOrder,
    convertToTradeSymbol,
    createCancelOrderById,
    normilizePrice
} = require("../orders");

class OrderManager {
    constructor(vfs) {
        this.ordersTable = vfs["/orders/table"];
        this.ordersReplyTable = vfs["/orders-reply/table"];
        this.orders = new Map();
        this.add = this.add.bind(this);
        this.get_extid_and_remove = this.get_extid_and_remove.bind(this);
        this.pipeOrders = this.pipeOrders.bind(this);
        this.pipeOrdersReply = this.pipeOrdersReply(this);
        this.ext_id = 0;
    }

    add(ext_id, order) {
        console.log("order", order);
        console.log(`OrderManager.add ext_id = ${ext_id}, cid = ${order.cid}`);
        this.orders.set(order.cid, ext_id);
    }

    get_extid_and_remove(cid) {
        if (this.orders.has(cid)) {
            let ext_id = this.orders.get(cid);
            this.orders.delete(cid);
            return ext_id;
        }
        return undefined;
    }

    //сюда перенаправляюем ордера от робота
    pipeOrders(userOrder) {
        //order = transformFromYardOrdersStream(order)
        const {
            symbol,
            price,
            dir,
            amount,
            type,
            exchange,
            ext_id
        } = userOrder;
        if (type == "new_order") {
            let exchange_ = exchange;
            let symbol_ = convertToTradeSymbol(symbol);
            let amount_ = parseFloat(amount);
            let price_ = normilizePrice(parseInt(price), symbol_);
            if (dir == "2") {
                amount_ = -amount_;
            }

            console.log(
                `@@@@@@@@@@@@@@@@@@@   ${exchange_} ${symbol_} amount = ${amount_} price = ${price_}`
            );
            const order = createLimitOrder(symbol_, price_, amount_);
            if (this.ws) {
                console.log("ws.Open ", this.ws.OPEN);
                if (this.ws.readyState == this.ws.OPEN) {
                    //orderManager.add(ext_id, order[3]);
                    this.add(ext_id, order[3]);
                    this.ws.send(JSON.stringify(order));
                } else {
                    console.log("ws not ready state = ", this.ws.readyState);
                }
            }
            console.log(order);
            this.ordersTable.update(order);
        } else if (type == "cancel_order") {
            let symbol_ = convertToTradeSymbol(symbol);
            const { order_id } = userOrder;
            console.log("cancel ", symbol_, " ", order_id);
            const cancelOrder = createCancelOrderById(order_id);
            console.log(cancelOrder);
            if (this.ws.readyState == this.ws.OPEN) {
                this.ws.send(JSON.stringify(cancelOrder));
            } else {
                console.log("ws not ready state = ", this.ws.readyState);
            }
            this.ordersTable.update(cancelOrder);
        }
    }

    //сюда перенапраяляем ответы, чтобы обработать
    pipeOrdersReply(reply) {
        //reply = transformOrdersReplyYardStream(reply)
        this.ordersReplyTable.update(reply);
    }

    trades(trade) {}
}

module.exports = {
    OrderManager
};
