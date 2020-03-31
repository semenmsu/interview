const vfs = require("../vfs");
const { Session } = require("../exchange-session");
const { ticker } = require("../exchange-streams");

session = new Session();
session.on("open", w => {
    ticker.subscribe(w, "tBTCUSD");
    ticker.subscribe(w, "tLTCUSD");
    ticker.subscribe(w, "tZECBTC");
});

const pipeToL1DataYardStream = ticker.GetPipe("zeromq");
vfs["/ticker/table"].subscribe(pipeToL1DataYardStream);
