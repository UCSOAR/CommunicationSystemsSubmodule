::
:: FILE: GenerateProto.bat
:: BRIEF: Generate C++ and Python code from .proto files in a protocol folder.
:: AUTHOR: Christopher Chan (cjchanx)
::
@echo off
setlocal EnableExtensions

set "SCRIPT_DIR=%~dp0"
set "PROTO_GROUP="
set "PROTO_FILE="
set "PROTO_INPUT=%~1"
set "PROTO_INPUT=%PROTO_INPUT:/=\%"
set "GENERATE_ALL=0"

if "%~1"=="" goto Usage

if not "%~2"=="" (
    set "PROTO_GROUP=%~1"
    set "PROTO_FILE=%~2"
) else (
    if "%PROTO_INPUT:\=%"=="%PROTO_INPUT%" (
        set "PROTO_GROUP=%PROTO_INPUT%"
        set "GENERATE_ALL=1"
    ) else (
        for /F "tokens=1* delims=\" %%I in ("%PROTO_INPUT%") do (
            set "PROTO_GROUP=%%I"
            set "PROTO_FILE=%%J"
        )
    )
)

set "PROTO_GROUP=%PROTO_GROUP:/=\%"
if "%PROTO_GROUP:~-1%"=="\" set "PROTO_GROUP=%PROTO_GROUP:~0,-1%"

set "PROTO_DIR=%SCRIPT_DIR%%PROTO_GROUP%"
set "CPP_OUT=%PROTO_DIR%\_C++"
set "PY_OUT=%PROTO_DIR%\_Python"

if not exist "%PROTO_DIR%\" goto MissingFolder

if "%GENERATE_ALL%"=="1" goto BuildAllTargets
goto BuildSingleTarget

:BuildAllTargets
if not exist "%PROTO_DIR%\*.proto" goto MissingProtoFiles
set "PROTO_TARGETS="
pushd "%PROTO_DIR%" >nul
for %%F in (*.proto) do call set "PROTO_TARGETS=%%PROTO_TARGETS%% %%F"
popd >nul
set "SOURCE_LABEL=%PROTO_GROUP%\*.proto"
goto Generate

:BuildSingleTarget
if /I not "%PROTO_FILE:~-6%"==".proto" set "PROTO_FILE=%PROTO_FILE%.proto"
for %%F in ("%PROTO_FILE%") do set "PROTO_BASE=%%~nF"

set "PROTO_PATH=%PROTO_DIR%\%PROTO_FILE%"
set "PROTO_TARGETS=%PROTO_FILE%"

if not exist "%PROTO_PATH%" goto MissingFile
if /I not "%PROTO_BASE%"=="CoreProto" if exist "%PROTO_DIR%\CoreProto.proto" set "PROTO_TARGETS=CoreProto.proto %PROTO_FILE%"
set "SOURCE_LABEL=%PROTO_GROUP%\%PROTO_FILE%"
goto Generate

:Generate
if not exist "%CPP_OUT%" mkdir "%CPP_OUT%"
if not exist "%PY_OUT%" mkdir "%PY_OUT%"

echo ** Generating Protocol Buffers **
echo Source: %SOURCE_LABEL%
echo C++:    %PROTO_GROUP%\_C++
echo Python: %PROTO_GROUP%\_Python

pushd "%PROTO_DIR%" >nul
protoc --plugin=protoc-gen-eams=..\protoc-gen-eams.bat --proto_path=. --eams_out="_C++" %PROTO_TARGETS%
if errorlevel 1 goto ProtocFailed

protoc --proto_path=. --pyi_out="_Python" --python_out="_Python" %PROTO_TARGETS%
if errorlevel 1 goto ProtocFailed

popd >nul

echo ** C++ File Cleanup **
pushd "%CPP_OUT%" >nul
for %%H in (*.h) do (
    if /I not "%%~nxH"=="CoreProto.h" (
        del "%%~nH.hpp" >nul 2>nul
        ren "%%~nxH" "%%~nH.hpp"
    )
)
popd >nul

echo.
echo       ** Done! **
exit /b 0

:ProtocFailed
popd >nul
echo.
echo ERROR: protoc failed.
exit /b 1

:MissingFolder
echo ERROR: "%PROTO_GROUP%" is not a folder under SoarProto.
exit /b 1

:MissingFile
echo ERROR: "%PROTO_GROUP%\%PROTO_FILE%" was not found.
exit /b 1

:MissingProtoFiles
echo ERROR: No .proto files were found in "%PROTO_GROUP%".
exit /b 1

:Usage
echo Usage:
echo   GenerateProto.bat ^<ProtoFolder^>
echo   GenerateProto.bat ^<ProtoFolder^> ^<FileName.proto^>
echo   GenerateProto.bat ^<ProtoFolder\FileName.proto^>
echo.
echo Examples:
echo   GenerateProto.bat Aegis
echo   GenerateProto.bat Jad
echo   GenerateProto.bat Aegis CommandMessage.proto
echo   GenerateProto.bat Ouroboros\TelemetryMessage.proto
exit /b 1
