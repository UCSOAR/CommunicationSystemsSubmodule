# SOAR Protocol

## Useful Info
#### Quick Generate
Run the [`GenerateProto.bat`](GenerateProto.bat) file with any protocol folder to update that folder's `_C++` and `_Python` files.

```
GenerateProto.bat Aegis
GenerateProto.bat Ouroboros
GenerateProto.bat Jad
```

You can also generate a specific proto by passing the filename or proto path:

```
GenerateProto.bat Aegis CommandMessage.proto
GenerateProto.bat Ouroboros TelemetryMessage.proto
GenerateProto.bat Aegis\CommandMessage.proto
GenerateProto.bat Ouroboros\TelemetryMessage.proto
```

Generated files are written beside the source proto:

- `<ProtoFolder>\_C++`
- `<ProtoFolder>\_Python`

When generating a specific non-`CoreProto.proto` file, the script also compiles that folder's `CoreProto.proto` so imports are available in the same generated output folders.

If generation fails with an EmbeddedProto dependency error, run [`QuickInstall.bat`](QuickInstall.bat) or run this from the `EmbeddedProto` folder:

```
python setup.py --ignore-version-diff
```

#### Manual Commands
 ```
 cd Aegis
 protoc --plugin=protoc-gen-eams=..\protoc-gen-eams.bat --proto_path=. --eams_out=_C++ CommandMessage.proto
 ```
 ```
 cd Aegis
 protoc --proto_path=. --pyi_out=_Python --python_out=_Python CommandMessage.proto
 ```

## Protocol Description
### Representation
- We use [ProtocolBuffers](https://developers.google.com/protocol-buffers) and the [EmbeddedProto](https://embeddedproto.com/) plugin for protobuf on our embedded systems to handle serialization.
### Transport
- We wrap Protobuf messages in the following format </br>
```
[MESSAGE_ID][PBUF_PAYLOAD][CHECKSUM]
```
```
[1_BYTE][ANY_LEN][2_BYTES]
``` 
- Then we proceed to wrap the message inside [`COBS`](cobs.h) which delimits the end of each message with a `0x00`
- The CHECKSUM is a <b>2-byte</b> CRC16 using the [CRC-16/XMODEM algorithm](https://crccalc.com/) - which is also represented as Crc16.CCITT when using the python [`crc`](https://pypi.org/project/crc/) package
- The message buffer max length can be adjusted as [PROTOCOL_RX_BUFFER_SZ_BYTES](https://github.com/StudentOrganisationForAerospaceResearch/SoarProto/blob/master/ProtocolTask.hpp) but should be kept to under <b>256 bytes</b>

## Installation (Windows)
### Auto Install
Run the [`QuickInstall.bat`](QuickInstall.bat) file with elevated privileges. </br>

### Manual Install
#### C++
 - The installation process can get quite involved in Windows, as we'll be using EmbeddedProto, we won't necessarily need protoc's regular C++ output.
 - Download or clone [EmbeddedProto](https://github.com/Embedded-AMS/EmbeddedProto) and run the script `setup.py` contained inside
 - Inside the respective C++ project, include the generated `_C++` folder for the protocol set you are using
 - Run this to compile the protocolbuffers files:
 ```
 GenerateProto.bat Aegis
 ```

<!--- Follow [this](https://github.com/protocolbuffers/protobuf/tree/main/python#installation). -->
#### Python 
 - Download [this](https://github.com/protocolbuffers/protobuf/releases/download/v21.12/protoc-21.12-win64.zip) and drag protoc.exe somewhere on PATH
 - Alternatively, run `choco install protoc` if you have Chocolatey package manager
 - Inside the respective Python project, include the generated `_Python` folder for the protocol set you are using.
 - Run this to compile the protocolbuffers files:
 ```
 GenerateProto.bat Aegis
 ```
    

## Recommendations
1. I recommend using VSCode to handle .proto files with the `vscode-proto3` extension

## Using SoarProto
### C++
SoarProto has 3 folders that must be included. The list is as follows:
- SoarProto folder [(`ProtocolTask.hpp`)](https://github.com/StudentOrganisationForAerospaceResearch/SoarProto/blob/master/ProtocolTask.hpp) (SoarProto Root Directory)
- The generated `_C++` folder under the protocol set you are using, such as `Aegis\_C++` or `Ouroboros\_C++`
- [`_EmbeddedProtoLib`](https://github.com/StudentOrganisationForAerospaceResearch/SoarProto/tree/master/_EmbeddedProtoLib) folder

ProtocolTask is designed to be a parent class which handles all of the logic for parsing / encoding / decoding protobuf messages. An example implementation can be found in [AvionicsSoftware](https://github.com/StudentOrganisationForAerospaceResearch/AvionicsSoftware) under Components/SoarProtocol where DMBProtocolTask.cpp/hpp are defined. Some changes may be required to the rest of the codebase to support it, such as in Utils.
An example commit hash of the implementation can be found here (TODO)

Other Notes
- You will likely have to <b>exclude</b> the EmbeddedProto folder from compilation

### Python
Encode/decode functionality is implemented inside PythonTestProject/Codec.py

