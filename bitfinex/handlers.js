const vfs = require("./vfs");
const GetTickerHandler = require("./handlers/GetTickerHandler");
const GetTradesHandler = require("./handlers/GetTradesHandler");
const GetDefaultHandler = require("./handlers/GetDefaultHandler");
const GetNewOrderHandler = require("./handlers/GetNewOrderHandler");
const GetCancelOrderHandler = require("./handlers/GetCancelOrderHandler");
const GetUpdateOrderHandler = require("./handlers/GetUpdateOrderHandler");
const GetSnapshotOrdersHandler = require("./handlers/GetSnapshotOrdersHandler");
const GetTradeExecutedHandler = require("./handlers/GetTradeExecutedHandler");
const GetTradeUpdatedHandler = require("./handlers/GetTradeUpdatedHandler");
const GetBalanceUpdateHandler = require("./handlers/GetBalanceUpdateHandler");
const GetUpdateWalletHandler = require("./handlers/GetUpdateWalletHandler");
const GetSnapshotWalletsHandler = require("./handlers/GetSnapshotWalletsHandler");

function GetChannelHandler(response) {
    const { channel, chanId, symbol, pair } = response;

    if (channel == "trades") {
        return GetTradesHandler(response);
    } else if (channel == "ticker") {
        return GetTickerHandler(response);
    }

    return GetDefaultHandler(response);
}

function GetAuthChannelHandler(channel) {
    switch (channel) {
        case "os":
            return GetSnapshotOrdersHandler();
        case "fos":
            return GetDefaultHandler();
        case "fcs":
            return GetDefaultHandler();
        case "fls":
            return GetDefaultHandler();
        case "ws":
            return GetSnapshotWalletsHandler();
        case "wu":
            return GetUpdateWalletHandler();
        case "bu":
            return GetBalanceUpdateHandler();
        case "n":
            return GetDefaultHandler();
        case "on":
            return GetNewOrderHandler();
        case "oc":
            return GetCancelOrderHandler();
        case "ou":
            return GetUpdateOrderHandler();
        case "te":
            return GetTradeExecutedHandler();
        case "tu":
            return GetTradeUpdatedHandler();
        default:
            return GetDefaultHandler(channel);
    }
}

module.exports = {
    GetChannelHandler,
    GetAuthChannelHandler
};
