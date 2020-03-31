//vfs
const ws = require("ws");
const { GetChannelHandler, GetAuthChannelHandler } = require("../handlers");
const createAuthMessage = require("../auth/createAuthMessage");

class AuthSession {
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
        this.handlers = {};
        this.handlers["on"] = GetAuthChannelHandler("on");
        this.handlers["oc"] = GetAuthChannelHandler("oc");
        this.handlers["ou"] = GetAuthChannelHandler("ou");
        this.handlers["os"] = GetAuthChannelHandler("os");
        this.handlers["te"] = GetAuthChannelHandler("te");
        this.handlers["tu"] = GetAuthChannelHandler("tu");
        this.handlers["bu"] = GetAuthChannelHandler("bu");
        this.handlers["wu"] = GetAuthChannelHandler("wu");
        this.handlers["ws"] = GetAuthChannelHandler("ws");

        this.authenticated = false;
        this.channelId = undefined;
        this.status = undefined;
        this.userId = undefined;
        this.auth_id = undefined;
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

    _onmessage(message) {
        let msg = JSON.parse(message);
        let { event, chanId } = msg;
        //console.log(msg);
        if (event) {
            if (event === "auth") {
                let { userId, auth_id } = msg;
                this.authenticated = true;
                this.channelId = chanId;
                this.status = msg.status;
                this.userId = userId;
                this.auth_id = auth_id;
            }
        } else {
            if (this.channelId != undefined) {
                let [chanId, channelType, data] = msg;
                let handler = this.handlers[channelType];
                if (handler) {
                    handler(data);
                }
            }
        }
        //logger.info(message);
    }

    _onopen() {
        this.ws._socket.setKeepAlive(true); //resolve drop internet connection
        const authMessage = createAuthMessage();
        //console.log(authMessage);
        this.ws.send(authMessage);
    }

    _onclose() {
        console.log("connection closed");
    }

    _onerror() {
        console.log("Error: ", err);
    }
}

module.exports = {
    AuthSession
};
