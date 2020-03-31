/*[
    CHAN_ID,
    'bu',
    [
      AUM,
      AUM_NET,
      ...
    ]
]*/

const vfs = require("../vfs");

function GetBalanceUpdateHandler() {
    const eventTable = vfs["/money/table"];
    const balanceUpdate = data => {
        let [AUM, AUM_NET, ...rest] = data;
        eventTable.update({
            mode: "online",
            stream: "money",
            exchange: "bitfinex",
            type: "money",
            aum: AUM,
            aum_net: AUM_NET
        });
    };
    return balanceUpdate;
}

module.exports = GetBalanceUpdateHandler;
