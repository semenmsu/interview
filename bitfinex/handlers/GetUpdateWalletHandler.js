const vfs = require("../vfs");

function GetUpdateWalletHandler() {
    const eventTable = vfs["/wallets/table"];
    const updateWalletHandler = data => {
        //console.log(msg);

        let [
            WALLET_TYPE,
            CURRENCY,
            BALANCE,
            UNSETTLED_INTEREST,
            BALANCE_AVAILABLE,
            ...rest
        ] = data;

        eventTable.update({
            mode: "online",
            stream: "wallet",
            exchange: "bitfinex",
            type: "wallet",
            wallet_type: WALLET_TYPE,
            currency: CURRENCY,
            balance: BALANCE,
            unsettled_interest: UNSETTLED_INTEREST,
            balance_available: BALANCE_AVAILABLE
        });
    };
    return updateWalletHandler;
}

module.exports = GetUpdateWalletHandler;
