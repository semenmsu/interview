const vfs = require("../vfs");

function GetUpdateOrderHandler() {
    const eventTable = vfs["/orders/table"];
    const updateOrderHandler = data => {
        let [
            ID,
            GID,
            CID,
            SYMBOL,
            MTS_CREATE,
            MTS_UPDATE,
            AMOUNT,
            AMOUNT_ORIG,
            TYPE,
            TYPE_PREV,
            _PLACEHOLDER,
            _PLACEHOLDER2,
            FLAGS,
            STATUS,
            _PLACEHOLDER3,
            _PLACEHOLDER4,
            PRICE,
            PRICE_AVG,
            PRICE_TRAILING,
            PRICE_AUX_LIMIT,
            _PLACEHOLDER5,
            _PLACEHOLDER6,
            _PLACEHOLDER7,
            NOTIFY,
            HIDDEN,
            PLACED_ID,
            _PLACEHOLDER8,
            _PLACEHOLDER9,
            ROUTING,
            _PLACEHOLDER10,
            _PLACEHOLDER11,
            _PLACEHOLDER12
        ] = data;
        eventTable.update({
            type: "update_reply",
            id: ID,
            gid: GID,
            cid: CID,
            symbol: SYMBOL,
            mts_create: MTS_CREATE,
            mts_update: MTS_UPDATE,
            amount: AMOUNT,
            amount_orig: AMOUNT_ORIG,
            exchange_type: TYPE,
            type_prev: TYPE_PREV,
            flags: FLAGS,
            status: STATUS,
            price: PRICE,
            price_avg: PRICE_AVG,
            price_trailing: PRICE_TRAILING,
            price_aux_limit: PRICE_AUX_LIMIT,
            notify: NOTIFY,
            hidden: HIDDEN,
            placed_id: PLACED_ID,
            routing: ROUTING
        });
    };
    return updateOrderHandler;
}

module.exports = GetUpdateOrderHandler;
