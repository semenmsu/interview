const ws = require("ws");
const vfs = require("./vfs");
const createAuthMessage = require("./auth/createAuthMessage");
const { createLimitOrder } = require("./orders");
//const w = new ws("wss://api-pub.bitfinex.com/ws/2");

const authMessage = createAuthMessage();
console.log(authMessage);

let order = createLimitOrder("tZECBTC", "0.02900", "0.06");

console.log(order);
