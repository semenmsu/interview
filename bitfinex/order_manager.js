class OrderManager {
    constructor() {
        this.orders = new Map();
        this.add = this.add.bind(this);
        this.get_extid_and_remove = this.get_extid_and_remove.bind(this);
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
}

module.exports = {
    OrderManager
};
