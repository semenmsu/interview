//vfs
const ws = require("ws");
const { GetChannelHandler } = require("../handlers");

class Session {
    constructor() {
        this.ws = new ws("wss://api-pub.bitfinex.com/ws/2");
        this._emit = this._emit.bind(this);
        this._onopen = this._onopen.bind(this);
        this._onerror = this._onerror.bind(this);
        this._onclose = this._onclose.bind(this);
        this._onmessage = this._onmessage.bind(this);

        this.ws.on("open", this._onopen);
        this.ws.on("message", this._onmessage);
        this.ws.on("error", this._onerror);
        this.ws.on("close", this._onclose);

        this.callbacks = new Map();
        this.channels = {};
    }

    on(event, callback) {
        if (this.callbacks.has(event)) {
            if (!(callback in this.callbacks)) {
                this.callbacks.get(event).push(callback);
            }
        } else {
            this.callbacks.set(event, []);
            this.callbacks.get(event).push(callback);
        }
    }

    _emit(event) {
        if (this.callbacks.has(event)) {
            let cbs = this.callbacks.get(event);
            if (event == "open") {
                for (let c of cbs) {
                    c(this.ws);
                }
            }
        }
    }

    _onmessage(msg) {
        console.log("on message", msg);
        msg = JSON.parse(msg);
        let { event, chanId } = msg;

        if (event == "subscribed") {
            chanId = parseInt(chanId);
            this.channels[chanId] = GetChannelHandler(msg);
        }

        if (!event) {
            let [channelID, ...rest] = msg;
            channelID = parseInt(channelID);
            let handler = this.channels[channelID];
            if (handler) {
                handler(msg);
            }
        }
    }

    _onopen() {
        this.ws._socket.setKeepAlive(true); //resolve drop internet connection
        console.log("on open");
        this._emit("open");
    }

    _onclose() {
        console.log("connection closed");
    }

    _onerror() {
        console.log("Error: ", err);
    }
}

module.exports = {
    Session
};
