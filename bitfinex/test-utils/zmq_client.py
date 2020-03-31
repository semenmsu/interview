import zmq
import json
import time

symbol = b'bitfinex@'

while True:
    try:
        context = zmq.Context()
        receiver = context.socket(zmq.SUB)
        receiver.connect("tcp://127.0.0.1:15562")
        receiver.subscribe(symbol)
        while True:
            print("wait message ...")
            msg = receiver.recv_multipart()
            print(msg)
    except Exception as err:
        print("Excption", err)
    finally:
        del context
        del receiver
    print("[data stream] wait time for reconnecting")
    time.sleep(5)
