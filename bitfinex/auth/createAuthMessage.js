const dotenv = require("dotenv");
dotenv.config();
const crypto = require("crypto");

const { API_BITFINEX_KEY, API_BITFINEX_SECRET } = process.env;

function createAuthMessage() {
    const { API_BITFINEX_KEY, API_BITFINEX_SECRET } = process.env;
    const apiKey = API_BITFINEX_KEY;
    const apiSecret = API_BITFINEX_SECRET;

    const authNonce = Date.now() * 1000;
    const authPayload = "AUTH" + authNonce;
    const authSig = crypto
        .createHmac("sha384", apiSecret)
        .update(authPayload)
        .digest("hex");

    const payload = {
        apiKey,
        authSig,
        authNonce,
        authPayload,
        event: "auth"
    };
    return JSON.stringify(payload);
}

module.exports = createAuthMessage;
