const bunyan = require("bunyan");
const fs = require("fs");

const fileName = "./log/auth-stream.json";
const fileStream = fs.createWriteStream(fileName);
var logger = bunyan.createLogger({
    name: "bitfinex-auth-stream",
    streams: [
        {
            level: "info",
            stream: fileStream
        }
    ]
});

module.exports = {
    logger
};
