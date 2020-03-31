import struct


message_decoders={}

c2m={}#code2message_name

ESTABLISH = 5000
ESTABLISHMENT_ACK = 5001
ESTABLISHMENT_REJECT = 5002
TERMINATE = 5003
RETRANSMIT_REQUEST = 5004
RETRANSMISSION = 5005
SEQUENCE = 5006
FLOOD_REJECT = 5007
SESSION_REJECT = 5008
NEW_ORDER_SINGLE = 6000
NEW_ORDER_MULTILEG = 6001
ORDER_CANCEL_REQUEST = 6002
ORDER_REPLACE_REQUEST = 6003
ORDER_MASS_CANCEL_REQUEST = 6004
ORDER_MASS_CANCEL_BY_B_F_LIMIT_REQUEST = 6005
NEW_ORDER_SINGLE_RESPONSE = 7000
NEW_ORDER_MULTILEG_RESPONSE = 7001
NEW_ORDER_REJECT = 7002
ORDER_CANCEL_RESPONSE = 7003
ORDER_CANCEL_REJECT = 7004
ORDER_REPLACE_RESPONSE = 7005
ORDER_REPLACE_REJECT = 7006
ORDER_MASS_CANCEL_RESPONSE = 7007
ORDER_MASS_CANCEL_BY_B_F_LIMIT_RESPONSE = 7012
EXECUTION_SINGLE_REPORT = 7008
EXECUTION_MULTILEG_REPORT = 7009
EMPTY_BOOK = 7010
SYSTEM_EVENT = 7011

c2m[5000]='ESTABLISH'
c2m[5001]='ESTABLISHMENT_ACK'
c2m[5002]='ESTABLISHMENT_REJECT'
c2m[5003]='TERMINATE'
c2m[5004]='RETRANSMIT_REQUEST'
c2m[5005]='RETRANSMISSION'
c2m[5006]='SEQUENCE'
c2m[5007]='FLOOD_REJECT'
c2m[5008]='SESSION_REJECT'
c2m[6000]='NEW_ORDER_SINGLE'
c2m[6001]='NEW_ORDER_MULTILEG'
c2m[6002]='ORDER_CANCEL_REQUEST'
c2m[6003]='ORDER_REPLACE_REQUEST'
c2m[6004]='ORDER_MASS_CANCEL_REQUEST'
c2m[6005]='ORDER_MASS_CANCEL_BY_B_F_LIMIT_REQUEST'
c2m[7000]='NEW_ORDER_SINGLE_RESPONSE'
c2m[7001]='NEW_ORDER_MULTILEG_RESPONSE'
c2m[7002]='NEW_ORDER_REJECT'
c2m[7003]='ORDER_CANCEL_RESPONSE'
c2m[7004]='ORDER_CANCEL_REJECT'
c2m[7005]='ORDER_REPLACE_RESPONSE'
c2m[7006]='ORDER_REPLACE_REJECT'
c2m[7007]='ORDER_MASS_CANCEL_RESPONSE'
c2m[7012]='ORDER_MASS_CANCEL_BY_B_F_LIMIT_RESPONSE'
c2m[7008]='EXECUTION_SINGLE_REPORT'
c2m[7009]='EXECUTION_MULTILEG_REPORT'
c2m[7010]='EMPTY_BOOK'
c2m[7011]='SYSTEM_EVENT'

class Header:
    def __init__(self):
        self.BodyLength=0 
        self.TemplateId=0 
        self.SchemaId=19781
        self.Version = 2


    def encode(self):
        return struct.pack('=HHHH',self.BodyLength, self.TemplateId, self.SchemaId, self.Version)
    
    def __repr__(self):
        return f"BodyLength={self.BodyLength} TemplateId={self.TemplateId} SchemaId={self.SchemaId} Version={self.Version}"

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=HHHH", buffer, 0)
        header = Header()
        header.BodyLength=decoded[0]
        header.TemplateId=decoded[1]
        header.SchemaId=decoded[2]
        header.Version=decoded[3]
        return header



class Establish:
    body_length=32
    template_id=5000
    schema_id=19781
    version=2

    def __init__(self):
        self.Timestamp=18446744073709551615 #type, primitive_type=uint64
        self.KeepaliveInterval=0 #type, primitive_type=uint32
        self.Credentials='' #type, primitive_type=char


    def encode(self):
        return struct.pack('=HHHHQI20s',32, 5000, 19781, 2, self.Timestamp, self.KeepaliveInterval, bytes(self.Credentials,encoding='ascii'))


    def __repr__(self):
        return f"Establish (blockLength=32, templateId=5000, schemaId=19781, version=2, Timestamp={self.Timestamp}, KeepaliveInterval={self.KeepaliveInterval}, Credentials={self.Credentials})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QI20s", buffer, offset=8)
        twime_message = Establish()
        twime_message.Timestamp=decoded[0]
        twime_message.KeepaliveInterval=decoded[1]
        twime_message.Credentials=decoded[2]
        return twime_message


#5000 Establish
message_decoders[5000] = Establish.decode_from

class EstablishmentAck:
    body_length=24
    template_id=5001
    schema_id=19781
    version=2

    def __init__(self):
        self.RequestTimestamp=18446744073709551615 #type, primitive_type=uint64
        self.KeepaliveInterval=0 #type, primitive_type=uint32
        self.NextSeqNo=18446744073709551615 #type, primitive_type=uint64


    def encode(self):
        return struct.pack('=HHHHQIQ',24, 5001, 19781, 2, self.RequestTimestamp, self.KeepaliveInterval, self.NextSeqNo)


    def __repr__(self):
        return f"EstablishmentAck (blockLength=24, templateId=5001, schemaId=19781, version=2, RequestTimestamp={self.RequestTimestamp}, KeepaliveInterval={self.KeepaliveInterval}, NextSeqNo={self.NextSeqNo})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QIQ", buffer, offset=8)
        twime_message = EstablishmentAck()
        twime_message.RequestTimestamp=decoded[0]
        twime_message.KeepaliveInterval=decoded[1]
        twime_message.NextSeqNo=decoded[2]
        return twime_message


#5001 EstablishmentAck
message_decoders[5001] = EstablishmentAck.decode_from

class EstablishmentReject:
    body_length=9
    template_id=5002
    schema_id=19781
    version=2

    def __init__(self):
        self.RequestTimestamp=18446744073709551615 #type, primitive_type=uint64
        self.EstablishmentRejectCode=0 #enum, encoding_type=uint8


    def encode(self):
        return struct.pack('=HHHHQB',9, 5002, 19781, 2, self.RequestTimestamp, self.EstablishmentRejectCode)


    def __repr__(self):
        return f"EstablishmentReject (blockLength=9, templateId=5002, schemaId=19781, version=2, RequestTimestamp={self.RequestTimestamp}, EstablishmentRejectCode={self.EstablishmentRejectCode})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QB", buffer, offset=8)
        twime_message = EstablishmentReject()
        twime_message.RequestTimestamp=decoded[0]
        twime_message.EstablishmentRejectCode=decoded[1]
        return twime_message


#5002 EstablishmentReject
message_decoders[5002] = EstablishmentReject.decode_from

class Terminate:
    body_length=1
    template_id=5003
    schema_id=19781
    version=2

    def __init__(self):
        self.TerminationCode=0 #enum, encoding_type=uint8


    def encode(self):
        return struct.pack('=HHHHB',1, 5003, 19781, 2, self.TerminationCode)


    def __repr__(self):
        return f"Terminate (blockLength=1, templateId=5003, schemaId=19781, version=2, TerminationCode={self.TerminationCode})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=B", buffer, offset=8)
        twime_message = Terminate()
        twime_message.TerminationCode=decoded[0]
        return twime_message


#5003 Terminate
message_decoders[5003] = Terminate.decode_from

class RetransmitRequest:
    body_length=20
    template_id=5004
    schema_id=19781
    version=2

    def __init__(self):
        self.Timestamp=18446744073709551615 #type, primitive_type=uint64
        self.FromSeqNo=18446744073709551615 #type, primitive_type=uint64
        self.Count=4294967295 #type, primitive_type=uint32


    def encode(self):
        return struct.pack('=HHHHQQI',20, 5004, 19781, 2, self.Timestamp, self.FromSeqNo, self.Count)


    def __repr__(self):
        return f"RetransmitRequest (blockLength=20, templateId=5004, schemaId=19781, version=2, Timestamp={self.Timestamp}, FromSeqNo={self.FromSeqNo}, Count={self.Count})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QQI", buffer, offset=8)
        twime_message = RetransmitRequest()
        twime_message.Timestamp=decoded[0]
        twime_message.FromSeqNo=decoded[1]
        twime_message.Count=decoded[2]
        return twime_message


#5004 RetransmitRequest
message_decoders[5004] = RetransmitRequest.decode_from

class Retransmission:
    body_length=20
    template_id=5005
    schema_id=19781
    version=2

    def __init__(self):
        self.NextSeqNo=18446744073709551615 #type, primitive_type=uint64
        self.RequestTimestamp=18446744073709551615 #type, primitive_type=uint64
        self.Count=4294967295 #type, primitive_type=uint32


    def encode(self):
        return struct.pack('=HHHHQQI',20, 5005, 19781, 2, self.NextSeqNo, self.RequestTimestamp, self.Count)


    def __repr__(self):
        return f"Retransmission (blockLength=20, templateId=5005, schemaId=19781, version=2, NextSeqNo={self.NextSeqNo}, RequestTimestamp={self.RequestTimestamp}, Count={self.Count})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QQI", buffer, offset=8)
        twime_message = Retransmission()
        twime_message.NextSeqNo=decoded[0]
        twime_message.RequestTimestamp=decoded[1]
        twime_message.Count=decoded[2]
        return twime_message


#5005 Retransmission
message_decoders[5005] = Retransmission.decode_from

class Sequence:
    body_length=8
    template_id=5006
    schema_id=19781
    version=2

    def __init__(self):
        self.NextSeqNo=18446744073709551615 #type, primitive_type=uint64


    def encode(self):
        return struct.pack('=HHHHQ',8, 5006, 19781, 2, self.NextSeqNo)


    def __repr__(self):
        return f"Sequence (blockLength=8, templateId=5006, schemaId=19781, version=2, NextSeqNo={self.NextSeqNo})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=Q", buffer, offset=8)
        twime_message = Sequence()
        twime_message.NextSeqNo=decoded[0]
        return twime_message


#5006 Sequence
message_decoders[5006] = Sequence.decode_from

class FloodReject:
    body_length=16
    template_id=5007
    schema_id=19781
    version=2

    def __init__(self):
        self.ClOrdID=18446744073709551615 #type, primitive_type=uint64
        self.QueueSize=4294967295 #type, primitive_type=uint32
        self.PenaltyRemain=4294967295 #type, primitive_type=uint32


    def encode(self):
        return struct.pack('=HHHHQII',16, 5007, 19781, 2, self.ClOrdID, self.QueueSize, self.PenaltyRemain)


    def __repr__(self):
        return f"FloodReject (blockLength=16, templateId=5007, schemaId=19781, version=2, ClOrdID={self.ClOrdID}, QueueSize={self.QueueSize}, PenaltyRemain={self.PenaltyRemain})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QII", buffer, offset=8)
        twime_message = FloodReject()
        twime_message.ClOrdID=decoded[0]
        twime_message.QueueSize=decoded[1]
        twime_message.PenaltyRemain=decoded[2]
        return twime_message


#5007 FloodReject
message_decoders[5007] = FloodReject.decode_from

class SessionReject:
    body_length=13
    template_id=5008
    schema_id=19781
    version=2

    def __init__(self):
        self.ClOrdID=18446744073709551615 #type, primitive_type=uint64
        self.RefTagID=4294967295 #type, primitive_type=uint32
        self.SessionRejectReason=0 #enum, encoding_type=uint8


    def encode(self):
        return struct.pack('=HHHHQIB',13, 5008, 19781, 2, self.ClOrdID, self.RefTagID, self.SessionRejectReason)


    def __repr__(self):
        return f"SessionReject (blockLength=13, templateId=5008, schemaId=19781, version=2, ClOrdID={self.ClOrdID}, RefTagID={self.RefTagID}, SessionRejectReason={self.SessionRejectReason})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QIB", buffer, offset=8)
        twime_message = SessionReject()
        twime_message.ClOrdID=decoded[0]
        twime_message.RefTagID=decoded[1]
        twime_message.SessionRejectReason=decoded[2]
        return twime_message


#5008 SessionReject
message_decoders[5008] = SessionReject.decode_from

class NewOrderSingle:
    body_length=46
    template_id=6000
    schema_id=19781
    version=2

    def __init__(self):
        self.ClOrdID=18446744073709551615 #type, primitive_type=uint64
        self.ExpireDate=18446744073709551615 #type, primitive_type=uint64
        self.Price=0 #Decimal
        self.SecurityID=2147483647 #type, primitive_type=int32
        self.ClOrdLinkID=2147483647 #type, primitive_type=int32
        self.OrderQty=4294967295 #type, primitive_type=uint32
        self.TimeInForce=0 #enum, encoding_type=uint8
        self.Side=0 #enum, encoding_type=uint8
        self.ClientFlags=0 #set, encoding_type=uint8
        self.Account='' #type, primitive_type=char


    def encode(self):
        return struct.pack('=HHHHQQqiiIBBB7s',46, 6000, 19781, 2, self.ClOrdID, self.ExpireDate, self.Price*100000, self.SecurityID, self.ClOrdLinkID, self.OrderQty, self.TimeInForce, self.Side, self.ClientFlags, bytes(self.Account,encoding='ascii'))


    def __repr__(self):
        return f"NewOrderSingle (blockLength=46, templateId=6000, schemaId=19781, version=2, ClOrdID={self.ClOrdID}, ExpireDate={self.ExpireDate}, Price={self.Price}, SecurityID={self.SecurityID}, ClOrdLinkID={self.ClOrdLinkID}, OrderQty={self.OrderQty}, TimeInForce={self.TimeInForce}, Side={self.Side}, ClientFlags={self.ClientFlags}, Account={self.Account})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QQqiiIBBB7s", buffer, offset=8)
        twime_message = NewOrderSingle()
        twime_message.ClOrdID=decoded[0]
        twime_message.ExpireDate=decoded[1]
        twime_message.Price=decoded[2]
        twime_message.SecurityID=decoded[3]
        twime_message.ClOrdLinkID=decoded[4]
        twime_message.OrderQty=decoded[5]
        twime_message.TimeInForce=decoded[6]
        twime_message.Side=decoded[7]
        twime_message.ClientFlags=decoded[8]
        twime_message.Account=decoded[9]
        return twime_message


#6000 NewOrderSingle
message_decoders[6000] = NewOrderSingle.decode_from

class NewOrderMultileg:
    body_length=46
    template_id=6001
    schema_id=19781
    version=2

    def __init__(self):
        self.ClOrdID=18446744073709551615 #type, primitive_type=uint64
        self.ExpireDate=18446744073709551615 #type, primitive_type=uint64
        self.Price=0 #Decimal
        self.SecurityID=2147483647 #type, primitive_type=int32
        self.ClOrdLinkID=2147483647 #type, primitive_type=int32
        self.OrderQty=4294967295 #type, primitive_type=uint32
        self.TimeInForce=0 #enum, encoding_type=uint8
        self.Side=0 #enum, encoding_type=uint8
        self.ClientFlags=0 #set, encoding_type=uint8
        self.Account='' #type, primitive_type=char


    def encode(self):
        return struct.pack('=HHHHQQqiiIBBB7s',46, 6001, 19781, 2, self.ClOrdID, self.ExpireDate, self.Price*100000, self.SecurityID, self.ClOrdLinkID, self.OrderQty, self.TimeInForce, self.Side, self.ClientFlags, bytes(self.Account,encoding='ascii'))


    def __repr__(self):
        return f"NewOrderMultileg (blockLength=46, templateId=6001, schemaId=19781, version=2, ClOrdID={self.ClOrdID}, ExpireDate={self.ExpireDate}, Price={self.Price}, SecurityID={self.SecurityID}, ClOrdLinkID={self.ClOrdLinkID}, OrderQty={self.OrderQty}, TimeInForce={self.TimeInForce}, Side={self.Side}, ClientFlags={self.ClientFlags}, Account={self.Account})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QQqiiIBBB7s", buffer, offset=8)
        twime_message = NewOrderMultileg()
        twime_message.ClOrdID=decoded[0]
        twime_message.ExpireDate=decoded[1]
        twime_message.Price=decoded[2]
        twime_message.SecurityID=decoded[3]
        twime_message.ClOrdLinkID=decoded[4]
        twime_message.OrderQty=decoded[5]
        twime_message.TimeInForce=decoded[6]
        twime_message.Side=decoded[7]
        twime_message.ClientFlags=decoded[8]
        twime_message.Account=decoded[9]
        return twime_message


#6001 NewOrderMultileg
message_decoders[6001] = NewOrderMultileg.decode_from

class OrderCancelRequest:
    body_length=24
    template_id=6002
    schema_id=19781
    version=2

    def __init__(self):
        self.ClOrdID=18446744073709551615 #type, primitive_type=uint64
        self.OrderID=9223372036854775807 #type, primitive_type=int64
        self.ClientFlags=0 #set, encoding_type=uint8
        self.Account='' #type, primitive_type=char


    def encode(self):
        return struct.pack('=HHHHQqB7s',24, 6002, 19781, 2, self.ClOrdID, self.OrderID, self.ClientFlags, bytes(self.Account,encoding='ascii'))


    def __repr__(self):
        return f"OrderCancelRequest (blockLength=24, templateId=6002, schemaId=19781, version=2, ClOrdID={self.ClOrdID}, OrderID={self.OrderID}, ClientFlags={self.ClientFlags}, Account={self.Account})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QqB7s", buffer, offset=8)
        twime_message = OrderCancelRequest()
        twime_message.ClOrdID=decoded[0]
        twime_message.OrderID=decoded[1]
        twime_message.ClientFlags=decoded[2]
        twime_message.Account=decoded[3]
        return twime_message


#6002 OrderCancelRequest
message_decoders[6002] = OrderCancelRequest.decode_from

class OrderReplaceRequest:
    body_length=41
    template_id=6003
    schema_id=19781
    version=2

    def __init__(self):
        self.ClOrdID=18446744073709551615 #type, primitive_type=uint64
        self.OrderID=9223372036854775807 #type, primitive_type=int64
        self.Price=0 #Decimal
        self.OrderQty=4294967295 #type, primitive_type=uint32
        self.ClOrdLinkID=2147483647 #type, primitive_type=int32
        self.Mode=0 #enum, encoding_type=uint8
        self.ClientFlags=0 #set, encoding_type=uint8
        self.Account='' #type, primitive_type=char


    def encode(self):
        return struct.pack('=HHHHQqqIiBB7s',41, 6003, 19781, 2, self.ClOrdID, self.OrderID, self.Price*100000, self.OrderQty, self.ClOrdLinkID, self.Mode, self.ClientFlags, bytes(self.Account,encoding='ascii'))


    def __repr__(self):
        return f"OrderReplaceRequest (blockLength=41, templateId=6003, schemaId=19781, version=2, ClOrdID={self.ClOrdID}, OrderID={self.OrderID}, Price={self.Price}, OrderQty={self.OrderQty}, ClOrdLinkID={self.ClOrdLinkID}, Mode={self.Mode}, ClientFlags={self.ClientFlags}, Account={self.Account})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QqqIiBB7s", buffer, offset=8)
        twime_message = OrderReplaceRequest()
        twime_message.ClOrdID=decoded[0]
        twime_message.OrderID=decoded[1]
        twime_message.Price=decoded[2]
        twime_message.OrderQty=decoded[3]
        twime_message.ClOrdLinkID=decoded[4]
        twime_message.Mode=decoded[5]
        twime_message.ClientFlags=decoded[6]
        twime_message.Account=decoded[7]
        return twime_message


#6003 OrderReplaceRequest
message_decoders[6003] = OrderReplaceRequest.decode_from

class OrderMassCancelRequest:
    body_length=50
    template_id=6004
    schema_id=19781
    version=2

    def __init__(self):
        self.ClOrdID=18446744073709551615 #type, primitive_type=uint64
        self.ClOrdLinkID=2147483647 #type, primitive_type=int32
        self.SecurityID=2147483647 #type, primitive_type=int32
        self.SecurityType=0 #enum, encoding_type=uint8
        self.Side=0 #enum, encoding_type=uint8
        self.Account='' #type, primitive_type=char
        self.SecurityGroup='' #type, primitive_type=char


    def encode(self):
        return struct.pack('=HHHHQiiBB7s25s',50, 6004, 19781, 2, self.ClOrdID, self.ClOrdLinkID, self.SecurityID, self.SecurityType, self.Side, bytes(self.Account,encoding='ascii'), bytes(self.SecurityGroup,encoding='ascii'))


    def __repr__(self):
        return f"OrderMassCancelRequest (blockLength=50, templateId=6004, schemaId=19781, version=2, ClOrdID={self.ClOrdID}, ClOrdLinkID={self.ClOrdLinkID}, SecurityID={self.SecurityID}, SecurityType={self.SecurityType}, Side={self.Side}, Account={self.Account}, SecurityGroup={self.SecurityGroup})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QiiBB7s25s", buffer, offset=8)
        twime_message = OrderMassCancelRequest()
        twime_message.ClOrdID=decoded[0]
        twime_message.ClOrdLinkID=decoded[1]
        twime_message.SecurityID=decoded[2]
        twime_message.SecurityType=decoded[3]
        twime_message.Side=decoded[4]
        twime_message.Account=decoded[5]
        twime_message.SecurityGroup=decoded[6]
        return twime_message


#6004 OrderMassCancelRequest
message_decoders[6004] = OrderMassCancelRequest.decode_from

class OrderMassCancelByBFLimitRequest:
    body_length=15
    template_id=6005
    schema_id=19781
    version=2

    def __init__(self):
        self.ClOrdID=18446744073709551615 #type, primitive_type=uint64
        self.Account='' #type, primitive_type=char


    def encode(self):
        return struct.pack('=HHHHQ7s',15, 6005, 19781, 2, self.ClOrdID, bytes(self.Account,encoding='ascii'))


    def __repr__(self):
        return f"OrderMassCancelByBFLimitRequest (blockLength=15, templateId=6005, schemaId=19781, version=2, ClOrdID={self.ClOrdID}, Account={self.Account})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=Q7s", buffer, offset=8)
        twime_message = OrderMassCancelByBFLimitRequest()
        twime_message.ClOrdID=decoded[0]
        twime_message.Account=decoded[1]
        return twime_message


#6005 OrderMassCancelByBFLimitRequest
message_decoders[6005] = OrderMassCancelByBFLimitRequest.decode_from

class NewOrderSingleResponse:
    body_length=65
    template_id=7000
    schema_id=19781
    version=2

    def __init__(self):
        self.ClOrdID=18446744073709551615 #type, primitive_type=uint64
        self.Timestamp=18446744073709551615 #type, primitive_type=uint64
        self.ExpireDate=18446744073709551615 #type, primitive_type=uint64
        self.OrderID=9223372036854775807 #type, primitive_type=int64
        self.Flags=0 #set, encoding_type=uint64
        self.Price=0 #Decimal
        self.SecurityID=2147483647 #type, primitive_type=int32
        self.OrderQty=4294967295 #type, primitive_type=uint32
        self.TradingSessionID=2147483647 #type, primitive_type=int32
        self.ClOrdLinkID=2147483647 #type, primitive_type=int32
        self.Side=0 #enum, encoding_type=uint8


    def encode(self):
        return struct.pack('=HHHHQQQqQqiIiiB',65, 7000, 19781, 2, self.ClOrdID, self.Timestamp, self.ExpireDate, self.OrderID, self.Flags, self.Price*100000, self.SecurityID, self.OrderQty, self.TradingSessionID, self.ClOrdLinkID, self.Side)


    def __repr__(self):
        return f"NewOrderSingleResponse (blockLength=65, templateId=7000, schemaId=19781, version=2, ClOrdID={self.ClOrdID}, Timestamp={self.Timestamp}, ExpireDate={self.ExpireDate}, OrderID={self.OrderID}, Flags={self.Flags}, Price={self.Price}, SecurityID={self.SecurityID}, OrderQty={self.OrderQty}, TradingSessionID={self.TradingSessionID}, ClOrdLinkID={self.ClOrdLinkID}, Side={self.Side})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QQQqQqiIiiB", buffer, offset=8)
        twime_message = NewOrderSingleResponse()
        twime_message.ClOrdID=decoded[0]
        twime_message.Timestamp=decoded[1]
        twime_message.ExpireDate=decoded[2]
        twime_message.OrderID=decoded[3]
        twime_message.Flags=decoded[4]
        twime_message.Price=decoded[5]
        twime_message.SecurityID=decoded[6]
        twime_message.OrderQty=decoded[7]
        twime_message.TradingSessionID=decoded[8]
        twime_message.ClOrdLinkID=decoded[9]
        twime_message.Side=decoded[10]
        return twime_message


#7000 NewOrderSingleResponse
message_decoders[7000] = NewOrderSingleResponse.decode_from

class NewOrderMultilegResponse:
    body_length=65
    template_id=7001
    schema_id=19781
    version=2

    def __init__(self):
        self.ClOrdID=18446744073709551615 #type, primitive_type=uint64
        self.Timestamp=18446744073709551615 #type, primitive_type=uint64
        self.ExpireDate=18446744073709551615 #type, primitive_type=uint64
        self.OrderID=9223372036854775807 #type, primitive_type=int64
        self.Flags=0 #set, encoding_type=uint64
        self.Price=0 #Decimal
        self.SecurityID=2147483647 #type, primitive_type=int32
        self.OrderQty=4294967295 #type, primitive_type=uint32
        self.TradingSessionID=2147483647 #type, primitive_type=int32
        self.ClOrdLinkID=2147483647 #type, primitive_type=int32
        self.Side=0 #enum, encoding_type=uint8


    def encode(self):
        return struct.pack('=HHHHQQQqQqiIiiB',65, 7001, 19781, 2, self.ClOrdID, self.Timestamp, self.ExpireDate, self.OrderID, self.Flags, self.Price*100000, self.SecurityID, self.OrderQty, self.TradingSessionID, self.ClOrdLinkID, self.Side)


    def __repr__(self):
        return f"NewOrderMultilegResponse (blockLength=65, templateId=7001, schemaId=19781, version=2, ClOrdID={self.ClOrdID}, Timestamp={self.Timestamp}, ExpireDate={self.ExpireDate}, OrderID={self.OrderID}, Flags={self.Flags}, Price={self.Price}, SecurityID={self.SecurityID}, OrderQty={self.OrderQty}, TradingSessionID={self.TradingSessionID}, ClOrdLinkID={self.ClOrdLinkID}, Side={self.Side})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QQQqQqiIiiB", buffer, offset=8)
        twime_message = NewOrderMultilegResponse()
        twime_message.ClOrdID=decoded[0]
        twime_message.Timestamp=decoded[1]
        twime_message.ExpireDate=decoded[2]
        twime_message.OrderID=decoded[3]
        twime_message.Flags=decoded[4]
        twime_message.Price=decoded[5]
        twime_message.SecurityID=decoded[6]
        twime_message.OrderQty=decoded[7]
        twime_message.TradingSessionID=decoded[8]
        twime_message.ClOrdLinkID=decoded[9]
        twime_message.Side=decoded[10]
        return twime_message


#7001 NewOrderMultilegResponse
message_decoders[7001] = NewOrderMultilegResponse.decode_from

class NewOrderReject:
    body_length=20
    template_id=7002
    schema_id=19781
    version=2

    def __init__(self):
        self.ClOrdID=18446744073709551615 #type, primitive_type=uint64
        self.Timestamp=18446744073709551615 #type, primitive_type=uint64
        self.OrdRejReason=2147483647 #type, primitive_type=int32


    def encode(self):
        return struct.pack('=HHHHQQi',20, 7002, 19781, 2, self.ClOrdID, self.Timestamp, self.OrdRejReason)


    def __repr__(self):
        return f"NewOrderReject (blockLength=20, templateId=7002, schemaId=19781, version=2, ClOrdID={self.ClOrdID}, Timestamp={self.Timestamp}, OrdRejReason={self.OrdRejReason})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QQi", buffer, offset=8)
        twime_message = NewOrderReject()
        twime_message.ClOrdID=decoded[0]
        twime_message.Timestamp=decoded[1]
        twime_message.OrdRejReason=decoded[2]
        return twime_message


#7002 NewOrderReject
message_decoders[7002] = NewOrderReject.decode_from

class OrderCancelResponse:
    body_length=44
    template_id=7003
    schema_id=19781
    version=2

    def __init__(self):
        self.ClOrdID=18446744073709551615 #type, primitive_type=uint64
        self.Timestamp=18446744073709551615 #type, primitive_type=uint64
        self.OrderID=9223372036854775807 #type, primitive_type=int64
        self.Flags=0 #set, encoding_type=uint64
        self.OrderQty=4294967295 #type, primitive_type=uint32
        self.TradingSessionID=2147483647 #type, primitive_type=int32
        self.ClOrdLinkID=2147483647 #type, primitive_type=int32


    def encode(self):
        return struct.pack('=HHHHQQqQIii',44, 7003, 19781, 2, self.ClOrdID, self.Timestamp, self.OrderID, self.Flags, self.OrderQty, self.TradingSessionID, self.ClOrdLinkID)


    def __repr__(self):
        return f"OrderCancelResponse (blockLength=44, templateId=7003, schemaId=19781, version=2, ClOrdID={self.ClOrdID}, Timestamp={self.Timestamp}, OrderID={self.OrderID}, Flags={self.Flags}, OrderQty={self.OrderQty}, TradingSessionID={self.TradingSessionID}, ClOrdLinkID={self.ClOrdLinkID})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QQqQIii", buffer, offset=8)
        twime_message = OrderCancelResponse()
        twime_message.ClOrdID=decoded[0]
        twime_message.Timestamp=decoded[1]
        twime_message.OrderID=decoded[2]
        twime_message.Flags=decoded[3]
        twime_message.OrderQty=decoded[4]
        twime_message.TradingSessionID=decoded[5]
        twime_message.ClOrdLinkID=decoded[6]
        return twime_message


#7003 OrderCancelResponse
message_decoders[7003] = OrderCancelResponse.decode_from

class OrderCancelReject:
    body_length=20
    template_id=7004
    schema_id=19781
    version=2

    def __init__(self):
        self.ClOrdID=18446744073709551615 #type, primitive_type=uint64
        self.Timestamp=18446744073709551615 #type, primitive_type=uint64
        self.OrdRejReason=2147483647 #type, primitive_type=int32


    def encode(self):
        return struct.pack('=HHHHQQi',20, 7004, 19781, 2, self.ClOrdID, self.Timestamp, self.OrdRejReason)


    def __repr__(self):
        return f"OrderCancelReject (blockLength=20, templateId=7004, schemaId=19781, version=2, ClOrdID={self.ClOrdID}, Timestamp={self.Timestamp}, OrdRejReason={self.OrdRejReason})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QQi", buffer, offset=8)
        twime_message = OrderCancelReject()
        twime_message.ClOrdID=decoded[0]
        twime_message.Timestamp=decoded[1]
        twime_message.OrdRejReason=decoded[2]
        return twime_message


#7004 OrderCancelReject
message_decoders[7004] = OrderCancelReject.decode_from

class OrderReplaceResponse:
    body_length=60
    template_id=7005
    schema_id=19781
    version=2

    def __init__(self):
        self.ClOrdID=18446744073709551615 #type, primitive_type=uint64
        self.Timestamp=18446744073709551615 #type, primitive_type=uint64
        self.OrderID=9223372036854775807 #type, primitive_type=int64
        self.PrevOrderID=9223372036854775807 #type, primitive_type=int64
        self.Flags=0 #set, encoding_type=uint64
        self.Price=0 #Decimal
        self.OrderQty=4294967295 #type, primitive_type=uint32
        self.TradingSessionID=2147483647 #type, primitive_type=int32
        self.ClOrdLinkID=2147483647 #type, primitive_type=int32


    def encode(self):
        return struct.pack('=HHHHQQqqQqIii',60, 7005, 19781, 2, self.ClOrdID, self.Timestamp, self.OrderID, self.PrevOrderID, self.Flags, self.Price*100000, self.OrderQty, self.TradingSessionID, self.ClOrdLinkID)


    def __repr__(self):
        return f"OrderReplaceResponse (blockLength=60, templateId=7005, schemaId=19781, version=2, ClOrdID={self.ClOrdID}, Timestamp={self.Timestamp}, OrderID={self.OrderID}, PrevOrderID={self.PrevOrderID}, Flags={self.Flags}, Price={self.Price}, OrderQty={self.OrderQty}, TradingSessionID={self.TradingSessionID}, ClOrdLinkID={self.ClOrdLinkID})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QQqqQqIii", buffer, offset=8)
        twime_message = OrderReplaceResponse()
        twime_message.ClOrdID=decoded[0]
        twime_message.Timestamp=decoded[1]
        twime_message.OrderID=decoded[2]
        twime_message.PrevOrderID=decoded[3]
        twime_message.Flags=decoded[4]
        twime_message.Price=decoded[5]
        twime_message.OrderQty=decoded[6]
        twime_message.TradingSessionID=decoded[7]
        twime_message.ClOrdLinkID=decoded[8]
        return twime_message


#7005 OrderReplaceResponse
message_decoders[7005] = OrderReplaceResponse.decode_from

class OrderReplaceReject:
    body_length=20
    template_id=7006
    schema_id=19781
    version=2

    def __init__(self):
        self.ClOrdID=18446744073709551615 #type, primitive_type=uint64
        self.Timestamp=18446744073709551615 #type, primitive_type=uint64
        self.OrdRejReason=2147483647 #type, primitive_type=int32


    def encode(self):
        return struct.pack('=HHHHQQi',20, 7006, 19781, 2, self.ClOrdID, self.Timestamp, self.OrdRejReason)


    def __repr__(self):
        return f"OrderReplaceReject (blockLength=20, templateId=7006, schemaId=19781, version=2, ClOrdID={self.ClOrdID}, Timestamp={self.Timestamp}, OrdRejReason={self.OrdRejReason})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QQi", buffer, offset=8)
        twime_message = OrderReplaceReject()
        twime_message.ClOrdID=decoded[0]
        twime_message.Timestamp=decoded[1]
        twime_message.OrdRejReason=decoded[2]
        return twime_message


#7006 OrderReplaceReject
message_decoders[7006] = OrderReplaceReject.decode_from

class OrderMassCancelResponse:
    body_length=24
    template_id=7007
    schema_id=19781
    version=2

    def __init__(self):
        self.ClOrdID=18446744073709551615 #type, primitive_type=uint64
        self.Timestamp=18446744073709551615 #type, primitive_type=uint64
        self.TotalAffectedOrders=2147483647 #type, primitive_type=int32
        self.OrdRejReason=2147483647 #type, primitive_type=int32


    def encode(self):
        return struct.pack('=HHHHQQii',24, 7007, 19781, 2, self.ClOrdID, self.Timestamp, self.TotalAffectedOrders, self.OrdRejReason)


    def __repr__(self):
        return f"OrderMassCancelResponse (blockLength=24, templateId=7007, schemaId=19781, version=2, ClOrdID={self.ClOrdID}, Timestamp={self.Timestamp}, TotalAffectedOrders={self.TotalAffectedOrders}, OrdRejReason={self.OrdRejReason})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QQii", buffer, offset=8)
        twime_message = OrderMassCancelResponse()
        twime_message.ClOrdID=decoded[0]
        twime_message.Timestamp=decoded[1]
        twime_message.TotalAffectedOrders=decoded[2]
        twime_message.OrdRejReason=decoded[3]
        return twime_message


#7007 OrderMassCancelResponse
message_decoders[7007] = OrderMassCancelResponse.decode_from

class OrderMassCancelByBFLimitResponse:
    body_length=24
    template_id=7012
    schema_id=19781
    version=2

    def __init__(self):
        self.ClOrdID=18446744073709551615 #type, primitive_type=uint64
        self.Timestamp=18446744073709551615 #type, primitive_type=uint64
        self.TotalAffectedOrders=2147483647 #type, primitive_type=int32
        self.OrdRejReason=2147483647 #type, primitive_type=int32


    def encode(self):
        return struct.pack('=HHHHQQii',24, 7012, 19781, 2, self.ClOrdID, self.Timestamp, self.TotalAffectedOrders, self.OrdRejReason)


    def __repr__(self):
        return f"OrderMassCancelByBFLimitResponse (blockLength=24, templateId=7012, schemaId=19781, version=2, ClOrdID={self.ClOrdID}, Timestamp={self.Timestamp}, TotalAffectedOrders={self.TotalAffectedOrders}, OrdRejReason={self.OrdRejReason})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QQii", buffer, offset=8)
        twime_message = OrderMassCancelByBFLimitResponse()
        twime_message.ClOrdID=decoded[0]
        twime_message.Timestamp=decoded[1]
        twime_message.TotalAffectedOrders=decoded[2]
        twime_message.OrdRejReason=decoded[3]
        return twime_message


#7012 OrderMassCancelByBFLimitResponse
message_decoders[7012] = OrderMassCancelByBFLimitResponse.decode_from

class ExecutionSingleReport:
    body_length=69
    template_id=7008
    schema_id=19781
    version=2

    def __init__(self):
        self.ClOrdID=18446744073709551615 #type, primitive_type=uint64
        self.Timestamp=18446744073709551615 #type, primitive_type=uint64
        self.OrderID=9223372036854775807 #type, primitive_type=int64
        self.TrdMatchID=9223372036854775807 #type, primitive_type=int64
        self.Flags=0 #set, encoding_type=uint64
        self.LastPx=0 #Decimal
        self.LastQty=4294967295 #type, primitive_type=uint32
        self.OrderQty=4294967295 #type, primitive_type=uint32
        self.TradingSessionID=2147483647 #type, primitive_type=int32
        self.ClOrdLinkID=2147483647 #type, primitive_type=int32
        self.SecurityID=2147483647 #type, primitive_type=int32
        self.Side=0 #enum, encoding_type=uint8


    def encode(self):
        return struct.pack('=HHHHQQqqQqIIiiiB',69, 7008, 19781, 2, self.ClOrdID, self.Timestamp, self.OrderID, self.TrdMatchID, self.Flags, self.LastPx*100000, self.LastQty, self.OrderQty, self.TradingSessionID, self.ClOrdLinkID, self.SecurityID, self.Side)


    def __repr__(self):
        return f"ExecutionSingleReport (blockLength=69, templateId=7008, schemaId=19781, version=2, ClOrdID={self.ClOrdID}, Timestamp={self.Timestamp}, OrderID={self.OrderID}, TrdMatchID={self.TrdMatchID}, Flags={self.Flags}, LastPx={self.LastPx}, LastQty={self.LastQty}, OrderQty={self.OrderQty}, TradingSessionID={self.TradingSessionID}, ClOrdLinkID={self.ClOrdLinkID}, SecurityID={self.SecurityID}, Side={self.Side})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QQqqQqIIiiiB", buffer, offset=8)
        twime_message = ExecutionSingleReport()
        twime_message.ClOrdID=decoded[0]
        twime_message.Timestamp=decoded[1]
        twime_message.OrderID=decoded[2]
        twime_message.TrdMatchID=decoded[3]
        twime_message.Flags=decoded[4]
        twime_message.LastPx=decoded[5]
        twime_message.LastQty=decoded[6]
        twime_message.OrderQty=decoded[7]
        twime_message.TradingSessionID=decoded[8]
        twime_message.ClOrdLinkID=decoded[9]
        twime_message.SecurityID=decoded[10]
        twime_message.Side=decoded[11]
        return twime_message


#7008 ExecutionSingleReport
message_decoders[7008] = ExecutionSingleReport.decode_from

class ExecutionMultilegReport:
    body_length=77
    template_id=7009
    schema_id=19781
    version=2

    def __init__(self):
        self.ClOrdID=18446744073709551615 #type, primitive_type=uint64
        self.Timestamp=18446744073709551615 #type, primitive_type=uint64
        self.OrderID=9223372036854775807 #type, primitive_type=int64
        self.TrdMatchID=9223372036854775807 #type, primitive_type=int64
        self.Flags=0 #set, encoding_type=uint64
        self.LastPx=0 #Decimal
        self.LegPrice=0 #Decimal
        self.LastQty=4294967295 #type, primitive_type=uint32
        self.OrderQty=4294967295 #type, primitive_type=uint32
        self.TradingSessionID=2147483647 #type, primitive_type=int32
        self.ClOrdLinkID=2147483647 #type, primitive_type=int32
        self.SecurityID=2147483647 #type, primitive_type=int32
        self.Side=0 #enum, encoding_type=uint8


    def encode(self):
        return struct.pack('=HHHHQQqqQqqIIiiiB',77, 7009, 19781, 2, self.ClOrdID, self.Timestamp, self.OrderID, self.TrdMatchID, self.Flags, self.LastPx*100000, self.LegPrice*100000, self.LastQty, self.OrderQty, self.TradingSessionID, self.ClOrdLinkID, self.SecurityID, self.Side)


    def __repr__(self):
        return f"ExecutionMultilegReport (blockLength=77, templateId=7009, schemaId=19781, version=2, ClOrdID={self.ClOrdID}, Timestamp={self.Timestamp}, OrderID={self.OrderID}, TrdMatchID={self.TrdMatchID}, Flags={self.Flags}, LastPx={self.LastPx}, LegPrice={self.LegPrice}, LastQty={self.LastQty}, OrderQty={self.OrderQty}, TradingSessionID={self.TradingSessionID}, ClOrdLinkID={self.ClOrdLinkID}, SecurityID={self.SecurityID}, Side={self.Side})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QQqqQqqIIiiiB", buffer, offset=8)
        twime_message = ExecutionMultilegReport()
        twime_message.ClOrdID=decoded[0]
        twime_message.Timestamp=decoded[1]
        twime_message.OrderID=decoded[2]
        twime_message.TrdMatchID=decoded[3]
        twime_message.Flags=decoded[4]
        twime_message.LastPx=decoded[5]
        twime_message.LegPrice=decoded[6]
        twime_message.LastQty=decoded[7]
        twime_message.OrderQty=decoded[8]
        twime_message.TradingSessionID=decoded[9]
        twime_message.ClOrdLinkID=decoded[10]
        twime_message.SecurityID=decoded[11]
        twime_message.Side=decoded[12]
        return twime_message


#7009 ExecutionMultilegReport
message_decoders[7009] = ExecutionMultilegReport.decode_from

class EmptyBook:
    body_length=12
    template_id=7010
    schema_id=19781
    version=2

    def __init__(self):
        self.Timestamp=18446744073709551615 #type, primitive_type=uint64
        self.TradingSessionID=2147483647 #type, primitive_type=int32


    def encode(self):
        return struct.pack('=HHHHQi',12, 7010, 19781, 2, self.Timestamp, self.TradingSessionID)


    def __repr__(self):
        return f"EmptyBook (blockLength=12, templateId=7010, schemaId=19781, version=2, Timestamp={self.Timestamp}, TradingSessionID={self.TradingSessionID})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=Qi", buffer, offset=8)
        twime_message = EmptyBook()
        twime_message.Timestamp=decoded[0]
        twime_message.TradingSessionID=decoded[1]
        return twime_message


#7010 EmptyBook
message_decoders[7010] = EmptyBook.decode_from

class SystemEvent:
    body_length=13
    template_id=7011
    schema_id=19781
    version=2

    def __init__(self):
        self.Timestamp=18446744073709551615 #type, primitive_type=uint64
        self.TradingSessionID=2147483647 #type, primitive_type=int32
        self.TradSesEvent=0 #enum, encoding_type=uint8


    def encode(self):
        return struct.pack('=HHHHQiB',13, 7011, 19781, 2, self.Timestamp, self.TradingSessionID, self.TradSesEvent)


    def __repr__(self):
        return f"SystemEvent (blockLength=13, templateId=7011, schemaId=19781, version=2, Timestamp={self.Timestamp}, TradingSessionID={self.TradingSessionID}, TradSesEvent={self.TradSesEvent})"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("=QiB", buffer, offset=8)
        twime_message = SystemEvent()
        twime_message.Timestamp=decoded[0]
        twime_message.TradingSessionID=decoded[1]
        twime_message.TradSesEvent=decoded[2]
        return twime_message


#7011 SystemEvent
message_decoders[7011] = SystemEvent.decode_from
