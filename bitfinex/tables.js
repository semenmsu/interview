class EventTable {
    constructor() {
        this.callbacks = new Set();
        this.subscribe = this.subscribe.bind(this);
        this.unsubscribe = this.unsubscribe.bind(this);
        this.update = this.update.bind(this);
    }

    update(message) {
        //console.log("event table ", message);
        for (let cb of this.callbacks) {
            //console.log("typeof callback ", typeof cb);
            cb(message);
        }
    }

    subscribe(f) {
        console.log(typeof f);
        if (!this.callbacks.has(f)) {
            this.callbacks.add(f);
        }
    }

    unsubscribe(f) {
        if (!this.callbacks.has(f)) {
            return;
        }
        this.callbacks.delete(f);
    }
}

module.exports = {
    EventTable
};
