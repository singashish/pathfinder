@echo off

set BUILD_DIR=build

@REM rem Check if the build directory exists, and if so, delete it
@REM if exist %BUILD_DIR% (
@REM     rmdir /s /q %BUILD_DIR%
@REM )

rem Create the build directory
echo.
mkdir %BUILD_DIR%
cd %BUILD_DIR%
cmake -G "MinGW Makefiles" ..
echo.
cmake --build .
cd ..