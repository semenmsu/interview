const WebSocket = require("ws");
const bunyan = require("bunyan");
const fs = require("fs");
const createAuthMessage = require("../auth/createAuthMessage");
const ws = new WebSocket("wss://api.bitfinex.com/ws/2");

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

ws.once("open", () => {
    const authMessage = createAuthMessage();
    console.log(authMessage);
    ws.send(authMessage);
});

ws.on("message", message => {
    console.log("message", message);
    message = JSON.parse(message);
    logger.info(message);
});

/*const auth = require('../auth').AuthMessage
const Order = require('../lib/order')
const WebSocket = require('ws')
const fs = require('fs')
const {orderNewNotification, orderNewResponse, latency} = require("../actions")

const ws = new WebSocket('wss://api.bitfinex.com/ws/2');
const bunyan = require('bunyan')

const fileName = './command/logs.txt'
const stream = fs.createWriteStream(fileName)
var log = bunyan.createLogger({name:'bitfinex-orders',
    streams: [{
        level: 'info',
        stream: stream,
    },
    ]})


let userId = 0
let chanId = 0
let status = ""
let auth_id = ""

const orders = new Map()

ws.once('open', () => {
        ws.send(auth)
})

ws.on('message', (message) => {
    console.log('message')
    log.info(message)
    const data = JSON.parse(message)
    if (data.event) {
        ws.emit(data.event, data)
    }
    if (data instanceof Array){
        const CHANNEL_ID = data[0]
        if (CHANNEL_ID == chanId) {
            const CHANNEL_NAME = data[1]

            if (CHANNEL_NAME == 'n' && data[2] instanceof Array) {
                //notification
                if (data[2][1] == 'on-req' && data[2][4] instanceof Array) {
                    const orderNotification=orderNewNotification(data[2][0], data[2][4])
                    ws.emit('n-on-req', orderNotification)
                }
            } else if (CHANNEL_NAME == 'on' && data[2] instanceof Array) {
               //this.dispatch(orderNewResponse(data[2]))
               const orderResponse = orderNewResponse(data[2])
               ws.emit('on', orderResponse)

            } else if (CHANNEL_NAME == 'oc') {
                //this.dispatch(orderCancelResponse(data[2]))
            } else if (CHANNEL_NAME == 'tu') {
                //this.dispatch(tradeExecutionResponse(data[2]))
            }
        }
    }
    //console.log(data)
})

ws.on('n-on-req', (orderNotification) => {

    const {cid} = orderNotification.response

    if (orders.has(cid)) {
        console.log("LATENCY_NEW_NOTIFICATION ",latency(orderNotification))
        console.log(orderNotification)
        orders.get(cid).history.push(orderNotification)
    }
})

ws.on('on', (orderResponse) => {

    const {cid} = orderResponse.response

    if (orders.has(cid)) {
        console.log("LATENCY_NEW_RESPONSE ",latency(orderResponse))
        console.log(orderResponse)
        orders.get(cid).history.push(orderResponse)
     
    }

    //cancel this order
})

ws.on('auth', (message) => {
    status = message.status
    chanId = message.chanId
    userId = message.userId
    auth_id = message.auth_id
    ws.emit('place_order')
})

ws.on('place_order', () => {
    setTimeout(()=> {
        const order = Order.createLimit('tZECBTC', "0.02900", "-0.06")
        //const order2 = Order.createLimit('tZECBTC', "0.02930", "0.06")
        const orderTracker = {
            order,
            history: []
        }

        //orderTracker.on('n-on-req',()=>{})
        //orderTracker.on('on',()=>{})
        log.info(order)
        ws.send(JSON.stringify(order))
        //ws.send(JSON.stringify(order2))

        
        orders.set(order[3].cid, orderTracker)
        //orders.set(order2[3].cid, orderTracker2)
    },2000)
   
})*/
