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
    (2, "send_fut_order"),
    (2, "send_fut_order_gdt"),
    (3, "cancel_first_order"),
    (2, "send_opt_order"),
    (2, "send_opt_order_for_replace"),
    (2, "replace_opt_order"),
    (2, "mass_cancel_fut"),
    (2, "mass_cancel_opt"),
    (5, "retransmit"),
    (5, "terminate"),
]

active_orders = []

client_order_id = 100
client_order_link_id = 100


def get_next_client_orderid():

    global client_order_id
    next_id = int(time.time()*100)
    if client_order_id >= next_id:
        client_order_id += 1
    else:
        client_order_id = next_id

    return client_order_id


def get_next_client_order_linkid():
    global client_order_link_id
    client_order_link_id += 1
    return client_order_link_id


def generate_cancel_order_by_ordreid(order_id):
    cancel = OrderCancelRequest()
    cancel.OrderID = order_id
    cancel.ClOrdID = get_next_client_orderid()
    cancel.Account = config['account']
    return cancel


def generate_simple_order():
    order = NewOrderSingle()
    order.ClOrdID = get_next_client_orderid()
    order.Price = 63000
    order.SecurityID = 626346  # Si-12.19
    order.ClOrdLinkID = get_next_client_order_linkid()
    order.OrderQty = 5
    order.Side = 1
    order.TimeInForce = 0
    order.Account = config['account']
    return order  # should encode


def generate_simple_gdt_order():
    order = NewOrderSingle()
    order.ClOrdID = get_next_client_orderid()
    order.Price = 63000
    order.SecurityID = 626346  # Si-12.19
    order.ClOrdLinkID = get_next_client_order_linkid()
    order.OrderQty = 6
    order.Side = 1
    order.TimeInForce = 6
    order.Account = config['account']
    return order  # should encode


def generate_simple_opt_order():
    # 626677 moex_opt@RTS-12.19M191219CA137500
    order = NewOrderSingle()
    order.ClOrdID = get_next_client_orderid()
    order.Price = 3000
    order.SecurityID = 626677
    order.ClOrdLinkID = get_next_client_order_linkid()
    order.OrderQty = 1
    order.Side = 1
    order.TimeInForce = 0
    order.Account = config['account']
    return order


replace_cl_order_link_id = 0
replace_orderid = 0


def generate_opt_order_for_replace():
    global replace_cl_order_link_id
    order = NewOrderSingle()
    order.ClOrdID = get_next_client_orderid()
    order.Price = 2950
    order.SecurityID = 626677
    order.ClOrdLinkID = get_next_client_order_linkid()
    replace_cl_order_link_id = order.ClOrdLinkID
    order.OrderQty = 10
    order.Side = 1
    order.TimeInForce = 0
    order.Account = config['account']
    return order


def generate_opt_order_replace():
    global replace_orderid
    order = OrderReplaceRequest()
    order.ClOrdID = get_next_client_orderid()
    order.OrderID = replace_orderid
    order.Price = 2900
    order.ClOrdLinkID = get_next_client_order_linkid()
    order.Account = config['account']
    return order


def generate_mass_cancel_fut():
    order = OrderMassCancelRequest()
    order.ClOrdID = get_next_client_orderid()
    order.ClOrdLinkID = 0
    order.SecurityType = 0
    order.Account = config['account']
    order.Side = 89
    order.SecurityGroup = "%"
    return order


def generate_mass_cancel_opt():
    order = OrderMassCancelRequest()
    order.ClOrdID = get_next_client_orderid()
    order.ClOrdLinkID = 0
    order.SecurityType = 1
    order.Account = config['account']
    order.Side = 89
    order.SecurityGroup = "%"
    return order


def session_callback(message):
    #value = datetime.fromtimestamp(time.time())
    #str_time = value.strftime('%Y-%m-%d %H:%M:%S.%f')
    #print(f"[{str_time}] INFO SESSION_LEVEL     {sess_message}")
    print(message)


def app_callback(message):
    global replace_cl_order_link_id
    global replace_orderid
    if message.template_id == NEW_ORDER_SINGLE_RESPONSE:
        if message.ClOrdLinkID == replace_cl_order_link_id:
            replace_orderid = message.OrderID
        active_orders.append(message.OrderID)
        #print("active_orders", active_orders)
    #value = datetime.fromtimestamp(time.time())
    #str_time = value.strftime('%Y-%m-%d %H:%M:%S.%f')
    #print(f"[{str_time}] INFO APPLICATION_LEVEL {c2m[template_id]} {app_message}")
    print(message)


def run_twime_session(session):
    session.run(session_callback, app_callback)


def run_forever_twime_session(session):
    session.run_forever(session_callback, app_callback)


def test():
    global active_orders
    session = Session(config['twime-session'])
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
        elif action == "send_fut_order":
            fut_order = generate_simple_order()
            print(fut_order)
            session.send(fut_order.encode())
        elif action == "send_fut_order_gdt":
            fut_order_gdt = generate_simple_gdt_order()
            print(fut_order_gdt)
            session.send(fut_order_gdt.encode())
        elif action == "cancel_first_order":
            order_id = active_orders.pop(0)
            cancel = generate_cancel_order_by_ordreid(order_id)
            print(cancel)
            session.send(cancel.encode())
            # for order_id in active_orders:
            #    cancel = generate_cancel_order_by_ordreid(order_id)
            #    print(cancel)
            #    session.send(cancel.encode())
            #active_orders = []
        elif action == "send_opt_order":
            opt_order = generate_simple_opt_order()
            print(opt_order)
            session.send(opt_order.encode())
        elif action == "send_opt_order_for_replace":
            opt_order_for_replace = generate_opt_order_for_replace()
            print(opt_order_for_replace)
            session.send(opt_order_for_replace.encode())
        elif action == "replace_opt_order":
            opt_order_replace = generate_opt_order_replace()
            print(opt_order_replace)
            session.send(opt_order_replace.encode())
            # pass
        elif action == "mass_cancel_fut":
            mass_cancel_fut = generate_mass_cancel_fut()
            print(mass_cancel_fut)
            session.send(mass_cancel_fut.encode())
        elif action == "mass_cancel_opt":
            mass_cancel_opt = generate_mass_cancel_opt()
            print(mass_cancel_opt)
            session.send(mass_cancel_opt.encode())
        elif action == "retransmit":
            from_seq_no = session.next_seq_no - 5
            session.retransmit(from_seq_no, 5)
        elif action == "terminate":
            session.terminate()
            # cancel_order(order_id)

    if run_session is not None:
        run_session.join()


test()
