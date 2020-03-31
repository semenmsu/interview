const { EventTable } = require("./tables");
const { OrderManager } = require("./order_manager");

const vfs = {};

vfs["/order_manager"] = new OrderManager();
vfs["/trades/table"] = new EventTable();
vfs["/ticker/table"] = new EventTable();
vfs["/books/table"] = new EventTable();
vfs["/rawbooks/table"] = new EventTable();
vfs["/candles/table"] = new EventTable();
vfs["/status/table"] = new EventTable();

vfs["/orders/table"] = new EventTable();
vfs["/orders/mode"] = "online"

vfs["/orders-reply/table"] = new EventTable();
vfs["/orders-reply/mode"] = "online";

vfs["/money/table"] = new EventTable();
vfs["/money/mode"] = "online";

vfs["/wallets/table"] = new EventTable();
vfs["/wallets/mode"] = "snapshot+online";

//initialization
const { tickerSubscribe } = require("./actions");
vfs["/ticker/subscribe"] = tickerSubscribe;

module.exports = vfs;
