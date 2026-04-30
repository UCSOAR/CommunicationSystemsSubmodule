import CoreProto_pb2 as _CoreProto_pb2
from google.protobuf.internal import enum_type_wrapper as _enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from typing import ClassVar as _ClassVar, Mapping as _Mapping, Optional as _Optional, Union as _Union

DESCRIPTOR: _descriptor.FileDescriptor

class CommandMessage(_message.Message):
    __slots__ = ["fcb_command", "pbb_command", "fsb_command", "lrb_command", "source", "source_sequence_num", "target"]
    FCB_COMMAND_FIELD_NUMBER: _ClassVar[int]
    PBB_COMMAND_FIELD_NUMBER: _ClassVar[int]
    FSB_COMMAND_FIELD_NUMBER: _ClassVar[int]
    LRB_COMMAND_FIELD_NUMBER: _ClassVar[int]
    SOURCE_FIELD_NUMBER: _ClassVar[int]
    SOURCE_SEQUENCE_NUM_FIELD_NUMBER: _ClassVar[int]
    TARGET_FIELD_NUMBER: _ClassVar[int]
    fcb_command: FcbCommand
    pbb_command: PbbCommand
    fsb_command: FsbCommand
    lrb_command: LrbCommand
    source: _CoreProto_pb2.Node
    source_sequence_num: int
    target: _CoreProto_pb2.Node
    def __init__(self, source: _Optional[_Union[_CoreProto_pb2.Node, str]] = ..., target: _Optional[_Union[_CoreProto_pb2.Node, str]] = ..., source_sequence_num: _Optional[int] = ..., fcb_command: _Optional[_Union[FcbCommand, _Mapping]] = ..., pbb_command: _Optional[_Union[PbbCommand, _Mapping]] = ..., fsb_command: _Optional[_Union[FsbCommand, _Mapping]] = ..., lrb_command: _Optional[_Union[LrbCommand, _Mapping]] = ...) -> None: ...

class FcbCommand(_message.Message):
    __slots__ = ["command_enum"]
    class Command(int, metaclass=_enum_type_wrapper.EnumTypeWrapper):
        __slots__ = []
    COMMAND_ENUM_FIELD_NUMBER: _ClassVar[int]
    RSC_ANY_TO_ABORT: FcbCommand.Command
    RSC_ARM_CONFIRM_1: FcbCommand.Command
    RSC_ARM_CONFIRM_2: FcbCommand.Command
    RSC_BURN_TO_COAST: FcbCommand.Command
    RSC_CLOSE_DRAIN: FcbCommand.Command
    RSC_CLOSE_VENT: FcbCommand.Command
    RSC_COAST_TO_DESCENT: FcbCommand.Command
    RSC_DESCENT_TO_RECOVERY: FcbCommand.Command
    RSC_FIRST_INVALID: FcbCommand.Command
    RSC_GOTO_ARM: FcbCommand.Command
    RSC_GOTO_FILL: FcbCommand.Command
    RSC_GOTO_IGNITION: FcbCommand.Command
    RSC_GOTO_PRELAUNCH: FcbCommand.Command
    RSC_GOTO_TEST: FcbCommand.Command
    RSC_IGNITION_TO_LAUNCH: FcbCommand.Command
    RSC_LAUNCH_TO_BURN: FcbCommand.Command
    RSC_MEV_CLOSE: FcbCommand.Command
    RSC_NONE: FcbCommand.Command
    RSC_OPEN_DRAIN: FcbCommand.Command
    RSC_OPEN_VENT: FcbCommand.Command
    RSC_POWER_TRANSITION_EXTERNAL: FcbCommand.Command
    RSC_POWER_TRANSITION_ONBOARD: FcbCommand.Command
    RSC_TEST_MEV_DISABLE: FcbCommand.Command
    RSC_TEST_MEV_ENABLE: FcbCommand.Command
    RSC_TEST_MEV_OPEN: FcbCommand.Command
    command_enum: FcbCommand.Command
    def __init__(self, command_enum: _Optional[_Union[FcbCommand.Command, str]] = ...) -> None: ...

class PbbCommand(_message.Message):
    __slots__ = ["command_enum"]
    class Command(int, metaclass=_enum_type_wrapper.EnumTypeWrapper):
        __slots__ = []
    COMMAND_ENUM_FIELD_NUMBER: _ClassVar[int]
    PBB_CLOSE_MEV: PbbCommand.Command
    PBB_NONE: PbbCommand.Command
    PBB_OPEN_MEV: PbbCommand.Command
    PMB_LAST: PbbCommand.Command
    command_enum: PbbCommand.Command
    def __init__(self, command_enum: _Optional[_Union[PbbCommand.Command, str]] = ...) -> None: ...

class FsbCommand(_message.Message):
    __slots__ = ["command_enum", "command_param"]
    class Command(int, metaclass=_enum_type_wrapper.EnumTypeWrapper):
        __slots__ = []
    COMMAND_ENUM_FIELD_NUMBER: _ClassVar[int]
    COMMAND_PARAM_FIELD_NUMBER: _ClassVar[int]
    RCU_CALIBRATE_NOS1_LOAD_CELL: FsbCommand.Command
    RCU_CALIBRATE_NOS2_LOAD_CELL: FsbCommand.Command
    RCU_CLOSE_AC1: FsbCommand.Command
    RCU_CLOSE_AC2: FsbCommand.Command
    RCU_CLOSE_PBV1: FsbCommand.Command
    RCU_CLOSE_PBV2: FsbCommand.Command
    RCU_CLOSE_PBV3: FsbCommand.Command
    RCU_CLOSE_PBV4: FsbCommand.Command
    RCU_CLOSE_SOL5: FsbCommand.Command
    RCU_CLOSE_SOL6: FsbCommand.Command
    RCU_CLOSE_SOL7: FsbCommand.Command
    RCU_CLOSE_SOL8A: FsbCommand.Command
    RCU_CLOSE_SOL8B: FsbCommand.Command
    RCU_IGNITE_PAD_BOX1: FsbCommand.Command
    RCU_IGNITE_PAD_BOX2: FsbCommand.Command
    RCU_KILL_PAD_BOX1: FsbCommand.Command
    RCU_KILL_PAD_BOX2: FsbCommand.Command
    RCU_LAST: FsbCommand.Command
    RCU_NONE: FsbCommand.Command
    RCU_OPEN_AC1: FsbCommand.Command
    RCU_OPEN_AC2: FsbCommand.Command
    RCU_OPEN_PBV1: FsbCommand.Command
    RCU_OPEN_PBV2: FsbCommand.Command
    RCU_OPEN_PBV3: FsbCommand.Command
    RCU_OPEN_PBV4: FsbCommand.Command
    RCU_OPEN_SOL5: FsbCommand.Command
    RCU_OPEN_SOL6: FsbCommand.Command
    RCU_OPEN_SOL7: FsbCommand.Command
    RCU_OPEN_SOL8A: FsbCommand.Command
    RCU_OPEN_SOL8B: FsbCommand.Command
    RCU_TARE_NOS1_LOAD_CELL: FsbCommand.Command
    RCU_TARE_NOS2_LOAD_CELL: FsbCommand.Command
    command_enum: FsbCommand.Command
    command_param: int
    def __init__(self, command_enum: _Optional[_Union[FsbCommand.Command, str]] = ..., command_param: _Optional[int] = ...) -> None: ...

class LrbCommand(_message.Message):
    __slots__ = ["command_enum", "command_param"]
    class Command(int, metaclass=_enum_type_wrapper.EnumTypeWrapper):
        __slots__ = []
    COMMAND_ENUM_FIELD_NUMBER: _ClassVar[int]
    COMMAND_PARAM_FIELD_NUMBER: _ClassVar[int]
    SOB_CALIBRATE_LOAD_CELL: LrbCommand.Command
    SOB_FAST_SAMPLE_IR: LrbCommand.Command
    SOB_LAST: LrbCommand.Command
    SOB_NONE: LrbCommand.Command
    SOB_SLOW_SAMPLE_IR: LrbCommand.Command
    SOB_TARE_LOAD_CELL: LrbCommand.Command
    command_enum: LrbCommand.Command
    command_param: int
    def __init__(self, command_enum: _Optional[_Union[LrbCommand.Command, str]] = ..., command_param: _Optional[int] = ...) -> None: ...
