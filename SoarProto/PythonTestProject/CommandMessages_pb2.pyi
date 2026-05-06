from google.protobuf.internal import enum_type_wrapper as _enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from typing import ClassVar as _ClassVar, Mapping as _Mapping, Optional as _Optional, Union as _Union

DESCRIPTOR: _descriptor.FileDescriptor

class CommandMessages(_message.Message):
    __slots__ = ("source_sequence_num", "fsb_command")
    SOURCE_SEQUENCE_NUM_FIELD_NUMBER: _ClassVar[int]
    FSB_COMMAND_FIELD_NUMBER: _ClassVar[int]
    source_sequence_num: int
    fsb_command: FsbCommand
    def __init__(self, source_sequence_num: _Optional[int] = ..., fsb_command: _Optional[_Union[FsbCommand, _Mapping]] = ...) -> None: ...

class FsbCommand(_message.Message):
    __slots__ = ("fsb_message",)
    class Command(int, metaclass=_enum_type_wrapper.EnumTypeWrapper):
        __slots__ = ()
        START_LOGGING: _ClassVar[FsbCommand.Command]
        STOP_LOGGING: _ClassVar[FsbCommand.Command]
        SEND_FILES: _ClassVar[FsbCommand.Command]
    START_LOGGING: FsbCommand.Command
    STOP_LOGGING: FsbCommand.Command
    SEND_FILES: FsbCommand.Command
    FSB_MESSAGE_FIELD_NUMBER: _ClassVar[int]
    fsb_message: FsbCommand.Command
    def __init__(self, fsb_message: _Optional[_Union[FsbCommand.Command, str]] = ...) -> None: ...
