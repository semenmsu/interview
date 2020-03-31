from twime.session import Session
import threading
import socket
from datetime import datetime
from config import config
from twime.generated_structs import *
import time
from twime import logger

actions = [
    (0, "connect"),
    (15, "retransmit"),
    (5, "terminate"),
]


def session_callback(message):
    print(message)


def app_callback(message):
    print(message)


def run_twime_session(session):
    session.run(session_callback, app_callback)


def run_forever_twime_session(session):
    session.run_forever(session_callback, app_callback)


def test():
    global active_orders
    session = Session(config['twime-recovery-session'])
    run_session = None
    while len(actions):
        next_action = actions.pop(0)
        [timeout, action] = next_action
        time.sleep(timeout)
        if action == "connect":
            run_session = threading.Thread(
                target=run_twime_session, args=(session,))
            run_session.daemon = True
            run_session.start()
        elif action == "retransmit":
            from_seq_no = session.next_seq_no - 10
            session.retransmit(1, 10)
        elif action == "terminate":
            session.terminate()
            # cancel_order(order_id)

    if run_session is not None:
        run_session.join()


test()
