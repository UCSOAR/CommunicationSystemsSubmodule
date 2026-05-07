@echo off

::
:: Copyright (C) 2020-2023 Embedded AMS B.V. - All Rights Reserved
::
:: This file is part of Embedded Proto.
::
:: Embedded Proto is open source software: you can redistribute it and/or 
:: modify it under the terms of the GNU General Public License as published 
:: by the Free Software Foundation, version 3 of the license.
::
:: Embedded Proto  is distributed in the hope that it will be useful,
:: but WITHOUT ANY WARRANTY; without even the implied warranty of
:: MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
:: GNU General Public License for more details.
::
:: You should have received a copy of the GNU General Public License
:: along with Embedded Proto. If not, see <https://www.gnu.org/licenses/>.
::
:: For commercial and closed source application please visit:
:: <https://EmbeddedProto.com/license/>.
::
:: Embedded AMS B.V.
:: Info:
::   info at EmbeddedProto dot com
::
:: Postal address:
::   Johan Huizingalaan 763a
::   1066 VH, Amsterdam
::   the Netherlands
::

:: This file is used to invoke protoc-gen-eams as a plugin to protoc on 
:: Windows. The reason this has to be used is that protoc expects a binary or
:: terminal script as plugin. Directly calling python scripts is not supported.

set "EmbeddedProtoDir=%~dp0EmbeddedProto"
set "EmbeddedProtoGeneratorDir=%EmbeddedProtoDir%\generator"
set "EmbeddedProtoVenvPlugin=%EmbeddedProtoDir%\venv\Scripts\protoc-gen-eams.exe"
set "EmbeddedProtoVenvPluginBat=%EmbeddedProtoDir%\venv\Scripts\protoc-gen-eams.bat"
set "EmbeddedProtoOptionsPy=%EmbeddedProtoGeneratorDir%\EmbeddedProto\embedded_proto_options_pb2.py"

if exist "%EmbeddedProtoVenvPlugin%" (
    call "%EmbeddedProtoVenvPlugin%"
    exit /b %ERRORLEVEL%
)

if exist "%EmbeddedProtoVenvPluginBat%" (
    call "%EmbeddedProtoVenvPluginBat%"
    exit /b %ERRORLEVEL%
)

if not exist "%EmbeddedProtoOptionsPy%" (
    pushd "%EmbeddedProtoGeneratorDir%" >nul
    protoc --proto_path=. --python_out=EmbeddedProto embedded_proto_options.proto
    if errorlevel 1 (
        popd >nul
        exit /b 1
    )
    popd >nul
)

set "PYTHONPATH=%EmbeddedProtoGeneratorDir%;%PYTHONPATH%"
python -c "import jinja2, google.protobuf, six, toposort" 1>nul 2>nul
if errorlevel 1 (
    echo ERROR: EmbeddedProto Python dependencies were not found. 1>&2
    echo Run QuickInstall.bat or run "python setup.py --ignore-version-diff" from the EmbeddedProto folder. 1>&2
    exit /b 1
)

python -m EmbeddedProto.main --protoc-plugin
exit /b %ERRORLEVEL%
