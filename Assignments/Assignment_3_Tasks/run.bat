@echo off
echo ===================================================
echo             Running Assignment 3 Programs
echo ===================================================

echo.
echo Compiling and running Q1 (Bank and Crypto Linking)...
gcc -c crypto.c -o crypto.o
gcc -std=c11 -Wall -Wextra bank.c crypto.o -o bank.exe
if %ERRORLEVEL% EQU 0 (
    echo [OK] Compilation successful. Running bank.exe:
    bank.exe
) else (
    echo [ERROR] Failed to compile bank.c
)

echo.
echo Compiling and running Q2 (Paging Simulation)...
gcc -std=c11 -Wall -Wextra q2_paging.c -o q2_paging.exe
if %ERRORLEVEL% EQU 0 (
    echo [OK] Compilation successful. Running q2_paging.exe:
    q2_paging.exe
) else (
    echo [ERROR] Failed to compile q2_paging.c
)

echo.
echo Compiling and running Q3 (Segmentation Simulation)...
gcc -std=c11 -Wall -Wextra q3_segmentation.c -o q3_segmentation.exe
if %ERRORLEVEL% EQU 0 (
    echo [OK] Compilation successful. Running q3_segmentation.exe:
    q3_segmentation.exe
) else (
    echo [ERROR] Failed to compile q3_segmentation.c
)

echo.
echo Compiling and running Q5 (Page Replacement: FIFO, LRU, Optimal)...
gcc -std=c11 -Wall -Wextra q5_page_replacement.c -o q5_page_replacement.exe
if %ERRORLEVEL% EQU 0 (
    echo [OK] Compilation successful. Running q5_page_replacement.exe:
    q5_page_replacement.exe
) else (
    echo [ERROR] Failed to compile q5_page_replacement.c
)

echo.
echo ===================================================
echo             Assignment 3 Finished
echo ===================================================
