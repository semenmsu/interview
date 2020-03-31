class Session {
    constructor() {
        this.interval = setInterval(() => {
            this.onopen();
        }, 1000);
    }

    onopen() {
        console.log("onopen");
    }
}

session = new Session();
session.onopen = () => {
    console.log("test");
};
