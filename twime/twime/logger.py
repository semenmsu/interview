from datetime import datetime
import time
from twime.generated_structs import c2m


def log(templateId, line, log_type="INFO"):
    value = datetime.fromtimestamp(time.time())
    str_time = value.strftime('%Y-%m-%d %H:%M:%S.%f')
    print(f"[{str_time}] {log_type} {c2m[templateId]} {line}")

def log_cert(message):
    template_id = message.template_id
    print
