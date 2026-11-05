@echo off
echo ===================================================
echo             Running Assignment 1 Programs
echo ===================================================

echo.
echo Compiling t6.c...
gcc -std=c11 -Wall -Wextra t6.c -o t6.exe
if %ERRORLEVEL% EQU 0 (
    echo [OK] Compilation successful. Running t6.exe:
    t6.exe
) else (
    echo [ERROR] Failed to compile t6.c
)

echo.
echo Compiling t7.c...
gcc -std=c11 -Wall -Wextra t7.c -o t7.exe
if %ERRORLEVEL% EQU 0 (
    echo [OK] Compilation successful. Running t7.exe:
    t7.exe
) else (
    echo [ERROR] Failed to compile t7.c
)

echo.
echo ===================================================
echo             Assignment 1 Finished
echo ===================================================
