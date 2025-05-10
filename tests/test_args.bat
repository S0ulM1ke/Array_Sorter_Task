@echo off
setlocal EnableDelayedExpansion

rem Simple test to check if the arguments are passed correctly.

set TARGET=ArraySorterTask
set TARGET_EXECUTABLE=%TARGET%.exe

echo Running program arguments test for %TARGET%.

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

echo Testing -help argument
%TARGET_EXECUTABLE% -help > %TEST_OUTPUT%\test_help.txt
if !ERRORLEVEL! NEQ 0 (
    echo Failed to run %TARGET%.exe with -help argument.
    popd
    goto Error
)

fc /b "%TEST_OUTPUT%\test_help.txt" "%EXPECTED_OUTPUT%\expected_help.txt" >nul
if !ERRORLEVEL! NEQ 0 (
    echo Help output does not match expected.
    goto Error
)

echo Testing -print argument
%TARGET_EXECUTABLE% -target %INPUT_FILE% -print > %TEST_OUTPUT%\test_print.txt
if !ERRORLEVEL! NEQ 0 (
    echo Failed to run %TARGET_EXECUTABLE% with -print argument.
    popd
    goto Error
)

echo Testing -sort argument
%TARGET_EXECUTABLE% -target %INPUT_FILE%  -sort > %TEST_OUTPUT%\test_sort.txt
if !ERRORLEVEL! NEQ 0 (
    echo Failed to run %TARGET_EXECUTABLE% with -sort argument.
    popd
    goto Error
)

echo Testing -intersect argument
%TARGET_EXECUTABLE% -target %INPUT_FILE%  -intersect > %TEST_OUTPUT%\test_intersect.txt
if !ERRORLEVEL! NEQ 0 (
    echo Failed to run %TARGET_EXECUTABLE% with -intersect argument.
    popd
    goto Error
)

echo Testing -unique-rev argument
%TARGET_EXECUTABLE% -target %INPUT_FILE%  -unique-rev > %TEST_OUTPUT%\test_unique_rev.txt
if !ERRORLEVEL! NEQ 0 (
    echo Failed to run %TARGET_EXECUTABLE% with -unique-rev argument.
    popd
    goto Error
)


popd

echo All tests passed successfully.
echo Test output saved to %TEST_OUTPUT% directory.
exit /b 0

:Error
echo Test failed!
exit /b !ERRORLEVEL!