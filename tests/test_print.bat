@echo off
setlocal EnableDelayedExpansion

rem Test reading input from a file and printing it to the console.

set TARGET=ArraySorterTask
set TARGET_EXECUTABLE=%TARGET%.exe

echo Running program print test for %TARGET%.

set BUILD_ROOT=%cd%\build
set INPUT_FILE=%cd%\input\input.txt

rem Check if the build directory exists
if not exist %BUILD_ROOT% (
    echo Build directory does not exist. Please run the build script first.
    goto Error
)

pushd %BUILD_ROOT%

if not exist %TARGET_EXECUTABLE% (
    echo %TARGET_EXECUTABLE% not found. Please build the project first.
    popd
    goto Error
)

echo Testing -print argument
%TARGET_EXECUTABLE% -target %INPUT_FILE%  -print
if !ERRORLEVEL! NEQ 0 (
    echo Failed to run %TARGET_EXECUTABLE% with -print argument.
    popd
    goto Error
)

echo Print test passed successfully.
exit /b 0

:Error
echo Test failed!
exit /b !ERRORLEVEL!