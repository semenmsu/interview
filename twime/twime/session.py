import time
import threading
import socket
from twime.generated_structs import *
#from twime.logger import log


class Session:
    def __init__(self, config=None):
        self.host = config['host']
        self.port = config['port']
        self.timeout = config['timeout']
        self.keep_alive_interval = 5000
        self.credentials = "twFZcm_FZ00FB3"
        self.sock = None
        self.is_active = False
        self.lock = threading.Lock()
        self.next_seq_no = 0
        self.last_received_seq_no = 0
        self.initial_next_seq_no = 0
        self.unresolved_input_messages = []
        self.input_message_storage = []
        self.output_message_storage = []
        self.flood_reject_timeout = 1000000  # 1sec in mks
        self.flood_reject_reset_time = 0
        self.await_flood_reject_timeout_reset = False
        self.last_sync_next_seq_no = 0
        self.user_send_message_last_time = 0
        self.sess_callback = None
        self.app_callback = None
        self.is_retransmit_regime = False
        self.retransmit_messages_left = 0
        self.retransmition_from_seq_no = 0

    def start(self, establish):
        if self.sock:
            self.sock.send(establish)

    def send(self, msg):
        if self.sock:
            if self.is_active:
                self.check_blocking()
                if not self.await_flood_reject_timeout_reset:
                    with self.lock:
                        self.sock.send(msg)
                    self.user_send_message_last_time = time.time()*1000
                else:
                    print("awaiting flood reject timeout reset")
            else:
                print("session is not active")
        else:
            print("socket doesn't exist, should connect to twime server")

    def increment_next_seq_no(self):
        self.next_seq_no += 1

    def flood_reject_deteced(self):
        self.flood_reject_reset_time = int(
            time.time()*1000000) + self.flood_reject_timeout
        self.await_flood_reject_timeout_reset = True

    def check_blocking(self):
        if self.await_flood_reject_timeout_reset:
            if (int(time.time()*1000000) - self.flood_reject_reset_time) > 0:
                self.await_flood_reject_timeout_reset = False

    def set_initial_next_seq_no(self, next_seq_no):
        self.next_seq_no = next_seq_no
        self.initial_next_seq_no = next_seq_no
        self.last_sync_next_seq_no = next_seq_no

    def sync_next_seq_no(self):
        self.last_sync_next_seq_no = self.next_seq_no

    def terminate(self):
        terminate_message = Terminate()
        #log(TERMINATE, "USER TERMINATE SESSION")
        self.sess_callback(terminate_message)
        self.send(terminate_message.encode())

    def retransmit(self, from_seq_no, count):
        retransmit_request = RetransmitRequest()
        retransmit_request.Timestamp = int(time.time()*1000_000_000)
        retransmit_request.FromSeqNo = from_seq_no
        retransmit_request.Count = count
        self.sess_callback(retransmit_request)
        self.send(retransmit_request.encode())

    def check_health(self):
        if self.is_active:
            current_time = int(time.time()*1000)
            if current_time - self.user_send_message_last_time > 4000:
                sequence = Sequence()
                self.send(sequence.encode())
                #log(SEQUENCE, "USER")
                #self.user_send_message_last_time = current_time
                self.sess_callback(sequence)

    def start_retransmit_regime(self, from_seq_no,  count):
        self.is_retransmit_regime = True
        self.retransmition_from_seq_no = from_seq_no
        self.retransmit_messages_left = count

    def stop_retransmit_regime(self):
        self.is_retransmit_regime = False

    def received_retransmitted_message(self, message):
        self.retransmit_messages_left -= 1
        #print("received retransmitted message ")

    def run(self, sess_callback=None, app_callback=None):
        self.sess_callback = sess_callback
        self.app_callback = app_callback

        self.sock = socket.socket()
        self.sock.connect((self.host, self.port))
        self.is_active = False
        establish = Establish()
        establish.Timestamp = int(time.time()*1000_000_000)
        establish.KeepaliveInterval = self.keep_alive_interval
        establish.Credentials = self.credentials
        self.sess_callback(establish)
        self.start(establish.encode())
        user_send_sequence_last_time = 0
        self.user_send_message_last_time = int(time.time()*1000)
        buffer = bytearray(2048)
        position = 0
        num_bytes = 0
        while True:
            try:
                #data = bytearray(2000)
                #nbytes, sender = sd.recvfrom_into(data, 1500)
                msg = self.sock.recv(2048)

                #print("@@@@@@@@@@@@@@@@@@@@@@@@@@@@", type(msg))
                if len(msg):
                    buffer[position:position+len(msg)] = msg
                    num_bytes = position+len(msg)
                    #print(f"position: {position} num_bytes: {num_bytes}")
                    while(num_bytes-position > 7):
                        #print("try parse")
                        # необходимо обработать несколько сообщений за раз
                        #header = Header.decode_from(msg)
                        header = Header.decode_from(buffer[position:])
                        templateId = header.TemplateId
                        if header.BodyLength > num_bytes - position:
                            print(
                                f"can't read whole message, only header, wait .... bodyLen{header.BodyLength} < {num_bytes - position}")
                            # ждем когда можно будет прочитать сообщение целиком
                            break

                        #position += 8
                        #log(templateId, header)
                        if templateId == ESTABLISHMENT_ACK:  # admin
                            establishment_ack = EstablishmentAck.decode_from(
                                buffer[position:])
                            self.sess_callback(establishment_ack)
                            #self.sess_callback({'type': 'established'})
                            #log(templateId, establishment_ack)
                            user_send_sequence_last_time = int(
                                time.time()*1000)

                            self.is_active = True
                            #session.next_seq_no = establishment_ack.NextSeqNo
                            self.set_initial_next_seq_no(
                                establishment_ack.NextSeqNo)
                        elif templateId == ESTABLISHMENT_REJECT:  # admin
                            establishment_reject = EstablishmentReject.decode_from(
                                buffer[position:])
                            #self.sess_callback({'type': 'establishment_reject'})
                            #log(templateId, establishment_reject)
                            self.sess_callback(establishment_reject)
                        elif templateId == TERMINATE:  # admin
                            terminate = Terminate.decode_from(
                                buffer[position:])
                            #self.sess_callback({'type': 'terminate'})
                            self.sess_callback(terminate)
                            self.is_active = False
                            #log(templateId, terminate)
                        elif templateId == RETRANSMIT_REQUEST:  # admin
                            retransmit_request = RetransmitRequest.decode_from(
                                buffer[position:])
                            #log(templateId, retransmit_request)
                            self.sess_callback(retransmit_request)
                        elif templateId == RETRANSMISSION:  # admin
                            retransmission = Retransmission.decode_from(
                                buffer[position:])
                            #log(templateId, retransmission)
                            self.start_retransmit_regime(
                                retransmission.NextSeqNo, retransmission.Count)
                            self.sess_callback(retransmission)
                        elif templateId == SEQUENCE:  # admin
                            sequence = Sequence.decode_from(buffer[position:])
                            self.sess_callback(sequence)
                            #log(templateId, sequence)
                            self.last_received_seq_no = sequence.NextSeqNo
                            if sequence.NextSeqNo != self.next_seq_no:
                                print(
                                    f" sequence.NextSeqNo({sequence.NextSeqNo}) != session.next_seq_no ({self.next_seq_no}), not implemented")

                        elif templateId == FLOOD_REJECT:  # admin
                            flood_reject = FloodReject.decode_from(
                                buffer[position:])
                            self.sess_callback(flood_reject)
                            #log(templateId, flood_reject)
                            #self.sess_callback({'type': 'flood_reject'})
                            self.flood_reject_deteced()
                        elif templateId == SESSION_REJECT:  # admin
                            session_reject = SessionReject.decode_from(
                                buffer[position:])
                            self.sess_callback(session_reject)
                            #self.sess_callback({'type': 'session_reject'})
                            self.is_active = False
                            #log(templateId, session_reject)
                        else:  # app
                            if self.is_retransmit_regime:
                                retransmitted_message = message_decoders[templateId](
                                    buffer[position:])
                                self.received_retransmitted_message(
                                    retransmitted_message)
                                if self.retransmit_messages_left == 0:
                                    #print("retransmission is end")
                                    self.stop_retransmit_regime()
                                if app_callback:
                                    app_callback(retransmitted_message)
                            else:
                                self.increment_next_seq_no()
                                app_message = message_decoders[templateId](
                                    buffer[position:])
                                #log(templateId, app_message)
                                if app_callback:
                                    app_callback(app_message)

                        position += header.BodyLength + 8
                        self.check_health()

                    # move rest bytes to bytearray begin
                    if position == num_bytes:
                        position = 0
                        num_bytes = 0
                    else:
                        buffer[0:num_bytes-position] = buffer[position:num_bytes]
                        position = 0
                        num_bytes = num_bytes - position

                else:
                    print("disconnect")
                    break
            except socket.timeout:
                self.check_health()

    def run_forever(self, sess_callback, app_callback):
        while True:
            self.run(sess_callback, app_callback)
            time.sleep(5)
