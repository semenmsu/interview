const vfs = require("../vfs");

function GetSnapshotWalletsHandler() {
    const eventTable = vfs["/wallets/table"];
    const snapshotWalletsHandler = wallets => {
        for (let wallet of wallets) {
            let [
                WALLET_TYPE,
                CURRENCY,
                BALANCE,
                UNSETTLED_INTEREST,
                BALANCE_AVAILABLE,
                ...rest
            ] = wallet;
            eventTable.update({
                exchange: "bitfinex",
                mode: "snapshot",
                stream: "wallet",
                type: "snapshot_wallet",
                wallet_type: WALLET_TYPE,
                currency: CURRENCY,
                balance: BALANCE,
                unsettled_interest: UNSETTLED_INTEREST,
                balance_available: BALANCE_AVAILABLE
            });
        }
    };
    return snapshotWalletsHandler;
}

module.exports = GetSnapshotWalletsHandler;
