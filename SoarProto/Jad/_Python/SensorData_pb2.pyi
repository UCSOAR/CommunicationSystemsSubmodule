from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from typing import ClassVar as _ClassVar, Mapping as _Mapping, Optional as _Optional, Union as _Union

DESCRIPTOR: _descriptor.FileDescriptor

class SensorData(_message.Message):
    __slots__ = ("timestamp", "barometerMessage", "accelerometerMessage", "magnetometerMessage", "gyroscoperMessage", "thermocoupleMessage")
    TIMESTAMP_FIELD_NUMBER: _ClassVar[int]
    BAROMETERMESSAGE_FIELD_NUMBER: _ClassVar[int]
    ACCELEROMETERMESSAGE_FIELD_NUMBER: _ClassVar[int]
    MAGNETOMETERMESSAGE_FIELD_NUMBER: _ClassVar[int]
    GYROSCOPERMESSAGE_FIELD_NUMBER: _ClassVar[int]
    THERMOCOUPLEMESSAGE_FIELD_NUMBER: _ClassVar[int]
    timestamp: int
    barometerMessage: Barometer
    accelerometerMessage: Accelerometer
    magnetometerMessage: Magnetometer
    gyroscoperMessage: Gyroscope
    thermocoupleMessage: Thermocouple
    def __init__(self, timestamp: _Optional[int] = ..., barometerMessage: _Optional[_Union[Barometer, _Mapping]] = ..., accelerometerMessage: _Optional[_Union[Accelerometer, _Mapping]] = ..., magnetometerMessage: _Optional[_Union[Magnetometer, _Mapping]] = ..., gyroscoperMessage: _Optional[_Union[Gyroscope, _Mapping]] = ..., thermocoupleMessage: _Optional[_Union[Thermocouple, _Mapping]] = ...) -> None: ...

class Barometer(_message.Message):
    __slots__ = ("baro_pressure", "baro_temperature", "sensorLoggingRate", "LoggingIdx")
    BARO_PRESSURE_FIELD_NUMBER: _ClassVar[int]
    BARO_TEMPERATURE_FIELD_NUMBER: _ClassVar[int]
    SENSORLOGGINGRATE_FIELD_NUMBER: _ClassVar[int]
    LOGGINGIDX_FIELD_NUMBER: _ClassVar[int]
    baro_pressure: int
    baro_temperature: int
    sensorLoggingRate: SensorLoggingRate
    LoggingIdx: int
    def __init__(self, baro_pressure: _Optional[int] = ..., baro_temperature: _Optional[int] = ..., sensorLoggingRate: _Optional[_Union[SensorLoggingRate, _Mapping]] = ..., LoggingIdx: _Optional[int] = ...) -> None: ...

class Accelerometer(_message.Message):
    __slots__ = ("accel_x", "accel_y", "accel_z", "sensorLoggingRate", "LoggingIdx")
    ACCEL_X_FIELD_NUMBER: _ClassVar[int]
    ACCEL_Y_FIELD_NUMBER: _ClassVar[int]
    ACCEL_Z_FIELD_NUMBER: _ClassVar[int]
    SENSORLOGGINGRATE_FIELD_NUMBER: _ClassVar[int]
    LOGGINGIDX_FIELD_NUMBER: _ClassVar[int]
    accel_x: int
    accel_y: int
    accel_z: int
    sensorLoggingRate: SensorLoggingRate
    LoggingIdx: int
    def __init__(self, accel_x: _Optional[int] = ..., accel_y: _Optional[int] = ..., accel_z: _Optional[int] = ..., sensorLoggingRate: _Optional[_Union[SensorLoggingRate, _Mapping]] = ..., LoggingIdx: _Optional[int] = ...) -> None: ...

class Magnetometer(_message.Message):
    __slots__ = ("mag_x", "mag_y", "mag_z", "sensorLoggingRate", "LoggingIdx")
    MAG_X_FIELD_NUMBER: _ClassVar[int]
    MAG_Y_FIELD_NUMBER: _ClassVar[int]
    MAG_Z_FIELD_NUMBER: _ClassVar[int]
    SENSORLOGGINGRATE_FIELD_NUMBER: _ClassVar[int]
    LOGGINGIDX_FIELD_NUMBER: _ClassVar[int]
    mag_x: int
    mag_y: int
    mag_z: int
    sensorLoggingRate: SensorLoggingRate
    LoggingIdx: int
    def __init__(self, mag_x: _Optional[int] = ..., mag_y: _Optional[int] = ..., mag_z: _Optional[int] = ..., sensorLoggingRate: _Optional[_Union[SensorLoggingRate, _Mapping]] = ..., LoggingIdx: _Optional[int] = ...) -> None: ...

class Gyroscope(_message.Message):
    __slots__ = ("gyro_x", "gyro_y", "gyro_z", "sensorLoggingRate", "LoggingIdx")
    GYRO_X_FIELD_NUMBER: _ClassVar[int]
    GYRO_Y_FIELD_NUMBER: _ClassVar[int]
    GYRO_Z_FIELD_NUMBER: _ClassVar[int]
    SENSORLOGGINGRATE_FIELD_NUMBER: _ClassVar[int]
    LOGGINGIDX_FIELD_NUMBER: _ClassVar[int]
    gyro_x: int
    gyro_y: int
    gyro_z: int
    sensorLoggingRate: SensorLoggingRate
    LoggingIdx: int
    def __init__(self, gyro_x: _Optional[int] = ..., gyro_y: _Optional[int] = ..., gyro_z: _Optional[int] = ..., sensorLoggingRate: _Optional[_Union[SensorLoggingRate, _Mapping]] = ..., LoggingIdx: _Optional[int] = ...) -> None: ...

class Thermocouple(_message.Message):
    __slots__ = ("termo_temperature", "sensorLoggingRate", "LoggingIdx")
    TERMO_TEMPERATURE_FIELD_NUMBER: _ClassVar[int]
    SENSORLOGGINGRATE_FIELD_NUMBER: _ClassVar[int]
    LOGGINGIDX_FIELD_NUMBER: _ClassVar[int]
    termo_temperature: int
    sensorLoggingRate: SensorLoggingRate
    LoggingIdx: int
    def __init__(self, termo_temperature: _Optional[int] = ..., sensorLoggingRate: _Optional[_Union[SensorLoggingRate, _Mapping]] = ..., LoggingIdx: _Optional[int] = ...) -> None: ...

class SensorLoggingRate(_message.Message):
    __slots__ = ("changeLoggingRate", "newSensorLoggingRate")
    CHANGELOGGINGRATE_FIELD_NUMBER: _ClassVar[int]
    NEWSENSORLOGGINGRATE_FIELD_NUMBER: _ClassVar[int]
    changeLoggingRate: bool
    newSensorLoggingRate: int
    def __init__(self, changeLoggingRate: bool = ..., newSensorLoggingRate: _Optional[int] = ...) -> None: ...
