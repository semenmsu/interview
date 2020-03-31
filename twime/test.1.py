from twime.session import Session
import threading
import socket
from datetime import datetime
from config import config
import time

actions = [
    (0, "connect"),
    (60, "terminate"),
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
    session = Session(config['twime-session'])
    run_session = None
    while len(actions):
        next_action = actions.pop(0)
        [timeout, action] = next_action
        time.sleep(timeout)
        if action == "connect":
            run_session = threading.Thread(
                target=run_forever_twime_session, args=(session,))
            run_session.daemon = True
            run_session.start()
        elif action == "terminate":
            session.terminate()

    if session.is_active:
        run_session.join()


test()
