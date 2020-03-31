import re
import struct
from lxml import etree
from io import StringIO
import xml.etree.ElementTree as ET
import argparse


primitive_type_map = {
    'char': ('s', 1),
    'int': ('i', 4),
    'int8': ('b', 1),
    'int16': ('h', 2),
    'int32': ('i', 4),
    'int64': ('q', 8),
    'uint8': ('B', 1),
    'uint16': ('H', 2),
    'uint32': ('I', 4),
    'uint64': ('Q', 8),
    'float': ('f', 4),
    'double': ('d', 8),
}


def get_python_encoding_symbol(primitive_type):
    return primitive_type_map[primitive_type][0]


class TwimeType:

    def __init__(self, **kwargs):
        self.primitive_type = ''
        self.nullable = None
        self.presence = None
        self.minValue = None
        self.maxValue = None
        self.nullValue = None
        self.length = None
        self.name = None
        self.value = None
        self.name = kwargs['name']
        self.primitive_type = kwargs['primitiveType']
        if self.primitive_type != 'char':
            self.nullable = True if 'nullValue' in kwargs else False
            if self.nullable:
                self.nullValue = kwargs['nullValue']
            if 'minValue' in kwargs:
                self.minValue = kwargs['minValue']
            if 'maxValue' in kwargs:
                self.maxValue = kwargs['maxValue']
            if 'presence' in kwargs:
                self.presence = kwargs['presence']
        else:
            self.length = kwargs['length']

    def get_python_encoding_symbol(self):
        if self.primitive_type == 'char':
            return self.length+'s'
        else:
            return primitive_type_map[self.primitive_type][0]

    def __repr__(self):
        if self.primitive_type == 'char':
            return f"[{self.get_python_encoding_symbol()}]{self.name} {self.primitive_type} {self.length}"
        else:
            return f"[{self.get_python_encoding_symbol()}]{self.name} {self.primitive_type} {self.minValue} {self.maxValue} Nullable={self.nullable} {self.presence}"


class TwimeEnum:
    def __init__(self, **kwargs):
        self.name = kwargs['name']
        self.encoding_type = kwargs['encodingType']
        self.python_encoding_symbol = get_python_encoding_symbol(
            self.encoding_type)
        self.valid_values = set()
        self.valid_values_map = {}

    def add_valid_value(self, value, **kwargs):
        # print('add_valid_value', value)
        self.valid_values.add(value)
        self.valid_values_map[int(value)] = kwargs['name']


class TwimeSetOption:
    def __init__(self, value, name, description):
        self.value = value
        self.name = name
        self.description = description
        self.flag = 1 << int(value)


class TwimeSet:
    def __init__(self, **kwargs):
        self.name = kwargs['name']
        self.encoding_type = kwargs['encodingType']
        self.python_encoding_symbol = get_python_encoding_symbol(
            self.encoding_type)
        self.options_map = {}

    def add_choice(self, value, **kwargs):
        # print( print(value, kwargs)
        option = TwimeSetOption(value, kwargs['name'], kwargs['description'])
        self.options_map[int(value)] = option


class TwimeComposit:
    def __init__(self, **kwargs):
        self.name = kwargs['name']
        self.description = kwargs['description']
        self.type = None
        self.fields = []
        self.fields_map = {}
        if self.name.startswith('Decimal'):
            pattern = re.compile("^Decimal(\d+)")
            match = pattern.match(self.name)
            self.type = 'decimal'
            self.decimal_type = int(match.group(1))

    def add_type(self, **kwargs):
        twime_type = TwimeType(**kwargs)
        self.fields.append(twime_type)
        self.fields_map[twime_type.name] = self.fields[-1]
        # if twime_type.presence == 'constant':
        #    print('constant')


class TwimeField:
    # field_meta {('type',TwimeType), ('enum',TwimeEnum), ('set',TwimeSet), ('composit',TwimeComposit)}
    def __init__(self, field_meta, **kwargs):
        self.name = kwargs['name']
        self.id = kwargs['id']
        self.type = kwargs['type']  # == field_meta
        self.base_type = field_meta[0]  # type, enum, set, composit
        self.meta = field_meta[1]

    def __repr__(self):
        return f"{self.base_type} {self.type} {self.name} {self.id}"


class TwimeMessage:
    def __init__(self, **kwargs):
        self.name = kwargs['name']
        self.id = kwargs['id']
        self.fields = []

    # field_meta -info about field, kwargs - name id type, field_meta = types[type]
    def add_field(self, field_meta, **kwargs):
        field = TwimeField(field_meta, **kwargs)
        self.fields.append(field)

    def generate_python_code(self):
        # generate class
        template = '''
class __class_name__:
    body_length=__body_length__
    template_id=__template_id__
    schema_id=__schema_id__
    version=__version__

    def __init__(self):
__class_fields__

    def encode(self):
        __encode_into__


    def __repr__(self):
        return f"__class_name__ (blockLength=__body_length__, templateId=__template_id__, schemaId=__schema_id__, version=__version__, __repr_string__)"
    

    @staticmethod
    def decode_from(buffer):
        decoded = struct.unpack_from("__decode_from_string__", buffer, offset=8)
        twime_message = __class_name__()
__decode_from_fields___

'''
        class_fields = ''
        for field in self.fields:
            if field.base_type == 'type':
                field_value = '0'
                if field.meta.nullValue:
                    field_value = field.meta.nullValue
                if field.meta.primitive_type == 'char':
                    field_value = "\'\'"
                class_fields += "        self."+field.name + \
                    f"={field_value} #{field.base_type}, primitive_type={field.meta.primitive_type}\n"
            elif field.base_type == 'enum':
                field_value = '0'
                if field.meta.encoding_type == 'char':
                    field_value = "\'\'"
                class_fields += "        self."+field.name + \
                    f"={field_value} #{field.base_type}, encoding_type={field.meta.encoding_type}\n"
            elif field.base_type == 'set':
                field_value = '0'
                if field.meta.encoding_type == 'char':
                    field_value = "\'\'"
                class_fields += "        self."+field.name + \
                    f"={field_value} #{field.base_type}, encoding_type={field.meta.encoding_type}\n"
            elif field.base_type == 'composite':
                if field.meta.name.startswith('Decimal'):
                    class_fields += "        self."+field.name+f"=0 #Decimal\n"
                else:
                    class_fields += "        self."+field.name + \
                        f"={field_value} #{field.base_type}\n"

        # encode_into
        # struct.pack_into(
        # "=HHHH", buffer, 0, size, 6000, schemaId, version)

        python_encode_string = ''
        python_encode_values = ''
        field_num = 0
        python_decode_values = ""
        repr_string = ""
        for field in self.fields:
            if field.base_type == 'type':

                if field.meta.primitive_type == 'char':
                    python_encode_string += field.meta.length+get_python_encoding_symbol(
                        field.meta.primitive_type)
                    python_encode_values += f", bytes(self.{field.name},encoding=\'ascii\')"
                else:
                    python_encode_string += get_python_encoding_symbol(
                        field.meta.primitive_type)
                    python_encode_values += f", self.{field.name}"

                python_decode_values += f"        twime_message.{field.name}=decoded[{field_num}]\n"
                repr_string += f"{field.name}={{self.{field.name}}}, "
                field_num += 1
            elif field.base_type == 'enum':
                if field.meta.encoding_type == 'char':
                    python_encode_string += field.meta.length+get_python_encoding_symbol(
                        field.meta.encoding_type)
                    python_encode_values += f", bytes(self.{field.name},encoding=\'ascii\')"
                else:
                    python_encode_string += get_python_encoding_symbol(
                        field.meta.encoding_type)
                    python_encode_values += f", self.{field.name}"
                python_decode_values += f"        twime_message.{field.name}=decoded[{field_num}]\n"
                repr_string += f"{field.name}={{self.{field.name}}}, "
                field_num += 1
            elif field.base_type == 'set':
                if field.meta.encoding_type == 'char':
                    python_encode_string += field.meta.length+get_python_encoding_symbol(
                        field.meta.encoding_type)
                    python_encode_values += f", bytes(self.{field.name},encoding=\'ascii\')"
                else:
                    python_encode_string += get_python_encoding_symbol(
                        field.meta.encoding_type)
                    python_encode_values += f", self.{field.name}"
                python_decode_values += f"        twime_message.{field.name}=decoded[{field_num}]\n"
                repr_string += f"{field.name}={{self.{field.name}}}, "
                field_num += 1
            elif field.base_type == 'composite':
                #print("should encode composite!!!!!!!!!!!!!!!!!!!!!!")
                #print(field.name, field.meta.name)

                if field.meta.type and field.meta.type == 'decimal':
                    #print('XXXXXXXXXXXXXXXXXX', field.meta.decimal_type)
                    python_encode_string += get_python_encoding_symbol(
                        field.meta.fields[0].primitive_type)
                    python_encode_values += f", self.{field.name}*{10**field.meta.decimal_type}"
                    # input()
                    #python_decode_values += f"        twime_message.{field.name}=decoded[{field_num}]/{10**field.meta.decimal_type}\n"
                    python_decode_values += f"        twime_message.{field.name}=decoded[{field_num}]\n"
                    repr_string += f"{field.name}={{self.{field.name}}}, "
                    field_num += 1
                else:
                    raise Exception("not implemented", field)
                    # class_fields += "        self."+field.name + \
                    #    f"={field_value} #{field.base_type}\n"
                # input()
        repr_string = repr_string[:-2]
        python_decode_values += "        return twime_message"
        body_length = f"{struct.calcsize(python_encode_string)}"
        template_id = f"{self.id}"
        schema_id = f"{19781}"
        schema = 19781
        version = f"{2}"
        _version = 2
        header_encode_values = f",{struct.calcsize(python_encode_string)}, {self.id}, {schema}, {_version}"
        encode_into = f'return struct.pack(\'=HHHH{python_encode_string}\'{header_encode_values}{python_encode_values})'
        code = template.replace('__class_name__', self.name).replace('__class_fields__', class_fields).replace(
            '__encode_into__', encode_into).replace('__body_length__', body_length).replace('__template_id__', template_id)
        code = code.replace('__schema_id__', schema_id).replace(
            '__version__', version)
        code = code.replace('__decode_from_string__',
                            f"={python_encode_string}")
        code = code.replace('__decode_from_fields___', python_decode_values)
        code = code.replace('__repr_string__', repr_string)
        print(code)


def parse_xml(file_name):
    xml = ""
    with open(file_name) as f:
        xml = f.read()
    it = ET.iterparse(StringIO(xml))
    for _, el in it:
        prefix, has_namespace, postfix = el.tag.partition('}')
        if has_namespace:
            el.tag = postfix
            # print(postfix)
    root = it.root
    types = root.findall("types")[0]

    # handle types
    # <type name="Int8"           primitiveType="int8"    minValue="-128"                 maxValue="126"          nullValue="127"                 presence="optional" />
    _types = types.findall('type')
    _enums = types.findall('enum')
    _sets = types.findall('set')
    _composits = types.findall('composite')
    twime_types = {}

    for _type in _types:
        twime_type = TwimeType(**_type.attrib)
        twime_types[twime_type.name] = ('type', twime_type)
        # print(twime_type)

    for _enum in _enums:
        # print(_enum.attrib['name'], _enum.attrib['encodingType'])
        twime_enum = TwimeEnum(**_enum.attrib)
        valid_values = _enum.findall('validValue')
        for valid_value in valid_values:
            twime_enum.add_valid_value(valid_value.text, **valid_value.attrib)
        twime_types[twime_enum.name] = ('enum', twime_enum)

    for _set in _sets:
        twime_set = TwimeSet(**_set.attrib)
        choices = _set.findall('choice')
        for choice in choices:
            twime_set.add_choice(choice.text, **choice.attrib)
        twime_types[twime_set.name] = ('set', twime_set)

    for _composit in _composits:
        twime_composit = TwimeComposit(**_composit.attrib)
        twime_composit_types = _composit.findall('type')
        for _type in twime_composit_types:
            twime_composit.add_type(**_type.attrib)
        twime_types[twime_composit.name] = ('composite', twime_composit)

    generate_python_code(root, twime_types)
    return


def generate_python_code(root, twime_types):
    print("import struct")
    messages = root.findall("message")
    print("\n\nmessage_decoders={}\n")
    print("c2m={}#code2message_name\n")

    for message in messages:
        twime_message = TwimeMessage(**message.attrib)
        words = re.findall('[A-Z][^A-Z]*', twime_message.name)
        words = [word.upper() for word in words]
        template_define = f"{'_'.join(words)} = {twime_message.id}"
        print(template_define)
    print()

    for message in messages:
        twime_message = TwimeMessage(**message.attrib)
        words = re.findall('[A-Z][^A-Z]*', twime_message.name)
        words = [word.upper() for word in words]
        code_to_template_name = f"c2m[{twime_message.id}]=\'{'_'.join(words)}\'"
        print(code_to_template_name)

    header = '''
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

'''
    print(header)
    for message in messages:
        fields = message.findall("field")
        twime_message = TwimeMessage(**message.attrib)

        for field in fields:
            _type = field.attrib['type']
            field_meta = twime_types[_type]
            twime_message.add_field(twime_types[_type], **field.attrib)
        twime_message.generate_python_code()
        print(f"#{twime_message.id} {twime_message.name}")
        print(
            f"message_decoders[{twime_message.id}] = {twime_message.name}.decode_from")


parser = argparse.ArgumentParser(
    description="generate twime moex struct from xml file")
parser.add_argument("file_name", help="xml file for twime moex protocol")

args = parser.parse_args()

parse_xml(args.file_name)
