const dotenv = require("dotenv");
dotenv.config();
const MongoClient = require("mongodb");
const request = require("request");
const fs = require("fs");

const url = process.env.MONGODB_URL;
console.log(url);
const bitfinexUrl = "https://api.bitfinex.com/v1/symbols_details";

/*MongoClient.connect(url, function(err, db) {
    if (err) {
        console.log(err);
        return;
    }

    db.db("bitfinex")
        .collection("definitions")
        .insertOne({ test: "teset" });
});*/

async function connectToMongo() {
    let client = await MongoClient.connect(url, {
        useNewUrlParser: true,
        useUnifiedTopology: true
    });
    client.on("close", () => {
        console.log("-> lost connection");
    });

    client.on("reconnect", () => {
        console.log("-> reconnected");
    });
    let result = await client
        .db("bitfinex")
        .collection("definitions")
        .insertMany([{ test: "test" }, { test: "test2" }]);
    console.log(result);
    setTimeout(() => {
        client.close(true, function(err) {
            if (err) console.error(err);
            else console.log("close complete");
        });
        console.log("close");
    }, 2000);
}

async function saveManyToMongoDb(data) {
    let client = await MongoClient.connect(url, {
        useNewUrlParser: true,
        useUnifiedTopology: true
    });
    client.on("close", () => {
        console.log("-> lost connection");
    });

    client.on("reconnect", () => {
        console.log("-> reconnected");
    });
    let result = await client
        .db("bitfinex")
        .collection("definitions")
        .insertMany(data);
    console.log(result);
    setTimeout(() => {
        client.close(true, function(err) {
            if (err) console.error(err);
            else console.log("close complete");
        });
        console.log("close");
    }, 2000);
}

function getBitfinexInstrumentDefinitions() {
    request.get(bitfinexUrl, (err, response, body) => {
        //console.log(response);
        //console.log(body);
        console.log(typeof body);
        console.log(body.length);
        let json = JSON.parse(body);
        console.log(typeof json);
        console.log(json[0]);
    });
}

function getDefintionsAndSaveToMongoDb() {
    request.get(bitfinexUrl, async (err, response, body) => {
        let json = JSON.parse(body);
        await saveManyToMongoDb(json);
    });
}

function readFileCreateReadable() {
    //stream = fs.createReadStream("./utils/test.txt");
    /*stream.on("data", chunck => {
        console.log("chunck ", chunck.length);
    });
    stream.on("close", () => {
        console.log("close");
    });*/
    /*stream.on("readable", function() {
        console.log("readable");
        let data;
        while ((data = this.read())) {
            console.log(data.length);
        }
    });*/
}

function readFile() {
    data = fs.readFileSync("./utils/test.txt");
    json = JSON.parse(data);
    console.log(json);
}

//connectToMongo();
//getBitfinexInstrumentDefinitions();
//readFile();
getDefintionsAndSaveToMongoDb();
