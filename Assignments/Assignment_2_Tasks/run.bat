@echo off
echo ===================================================
echo             Running Assignment 2 Programs
echo ===================================================

echo.
echo Compiling q2.c (Round Robin CPU Scheduling)...
gcc -std=c11 -Wall -Wextra q2.c -o q2.exe
if %ERRORLEVEL% EQU 0 (
    echo [OK] Compilation successful. Running q2.exe:
    q2.exe
) else (
    echo [ERROR] Failed to compile q2.c
)

echo.
echo Compiling q5.c (Bounded Buffer Producer-Consumer)...
gcc -std=c11 -Wall -Wextra -pthread q5.c -o q5.exe
if %ERRORLEVEL% EQU 0 (
    echo [OK] Compilation successful. Running q5.exe:
    q5.exe
) else (
    echo [ERROR] Failed to compile q5.c
)

echo.
echo Compiling q6.c (Banker's Algorithm)...
gcc -std=c11 -Wall -Wextra q6.c -o q6.exe
if %ERRORLEVEL% EQU 0 (
    echo [OK] Compilation successful. Running q6.exe:
    q6.exe
) else (
    echo [ERROR] Failed to compile q6.c
)

echo.
echo ===================================================
echo             Assignment 2 Finished
echo ===================================================
