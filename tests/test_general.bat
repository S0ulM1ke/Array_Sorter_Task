@echo off
setlocal EnableDelayedExpansion

rem General test script for the ArraySorterTask program.

set TARGET=ArraySorterTask
set TARGET_EXECUTABLE=%TARGET%.exe

echo Running general test for %TARGET%.

set BUILD_ROOT=%cd%\build
set INPUT_FILE=%cd%\input\input.txt
set TEST_OUTPUT=%cd%\tests\output
set EXPECTED_OUTPUT=%cd%\tests\expected_output

if exist %TEST_OUTPUT%\ (
    echo Cleaning up previous test output
    rmdir /s /q %TEST_OUTPUT%\
)
mkdir %TEST_OUTPUT%

rem Check if the build directory exists
if not exist %BUILD_ROOT% (
    echo Build directory does not exist. Please run the build script first.
    goto Error
)

rem Enter the build directory
pushd %BUILD_ROOT%
if !ERRORLEVEL! NEQ 0 (
    echo Failed to enter build directory.
    goto Error
)

if not exist %TARGET_EXECUTABLE% (
    echo %TARGET_EXECUTABLE% not found. Please build the project first.
    popd
    goto Error
)

echo Executing %TARGET_EXECUTABLE% with arguments -target %INPUT_FILE%

%TARGET_EXECUTABLE% -target %INPUT_FILE% > %TEST_OUTPUT%\general_test_output.txt
if !ERRORLEVEL! NEQ 0 (
    echo Failed to run %TARGET_EXECUTABLE% with -target argument.
    popd
    goto Error
)

popd

echo General test passed successfully.
exit /b 0

:Error
echo Test failed!
exit /b !ERRORLEVEL!