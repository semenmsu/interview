from twime.session import Session
import threading
import socket
from datetime import datetime
from config import config


def session_callback(sess_message):
    print("session callback", sess_message)


def app_callback(template_id, app_message):
    value = datetime.fromtimestamp(time.time())
    str_time = value.strftime('%Y-%m-%d %H:%M:%S.%f')
    print(f"[{str_time}] INFO APPLICATION_LEVEL {c2m[template_id]} {app_message}")


def run_twime_session(session, app_callback):
    session.run(session_callback, app_callback)


def run():
    session = Session(config['twime-session'])
    run_twime = threading.Thread(
        target=run_twime_session, args=(session, app_callback))

    run_twime.daemon = True
    run_twime.start()
    run_twime.join()


run()
