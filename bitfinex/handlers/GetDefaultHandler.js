function GetDefaultHandler() {
    const defaultHandler = msg => {
        console.log("defaultHandler ", msg);
    };
    return defaultHandler;
}

module.exports = GetDefaultHandler;
