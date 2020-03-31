const vfs = require("../vfs");
const { AuthSession } = require("../exchange-session");
const { UserSession } = require("../user-session/mongodb-session");
const { OrderManager } = require("../order-manager");

orderManager = new OrderManager(vfs);
//session = new AuthSession();
userSession = new UserSession(orderManager);

//vfs["/ticker/table"].subscribe(pipeToL1DataYardStream);
//vfs["/wallets/table"].subscribe(msg => {
//    console.log(msg);
//});
//vfs["/money/table"].subscribe(msg => {
//    console.log(msg);
//});
