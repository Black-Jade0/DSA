@echo off
setlocal enabledelayedexpansion

:: Number of test cases to run
set TEST_CASES=100

:: Compile the solutions
echo Compiling solutions...
g++ -o optimized_solution.exe optimized_solution.cpp -O2
if %ERRORLEVEL% neq 0 (
    echo Failed to compile optimized solution
    exit /b 1
)

g++ -o brute_force_solution.exe brute_force_solution.cpp -O2
if %ERRORLEVEL% neq 0 (
    echo Failed to compile brute force solution
    exit /b 1
)

g++ -o generate_input.exe generate_input.cpp -O2
if %ERRORLEVEL% neq 0 (
    echo Failed to compile input generator
    exit /b 1
)

:: Start stress testing
set FAILED_CASE=

for /l %%i in (1, 1, %TEST_CASES%) do (
    echo Running Test Case #%%i

    :: Generate random input
    generate_input.exe > input.txt
    if %ERRORLEVEL% neq 0 (
        echo Failed to generate input
        exit /b 1
    )

    :: Run both solutions
    optimized_solution.exe < input.txt > output_optimized.txt
    if %ERRORLEVEL% neq 0 (
        echo Optimized solution crashed
        exit /b 1
    )

    brute_force_solution.exe < input.txt > output_brute.txt
    if %ERRORLEVEL% neq 0 (
        echo Brute force solution crashed
        exit /b 1
    )

    :: Compare outputs using a more robust method
    call :compare_files output_optimized.txt output_brute.txt
    if !ERRORLEVEL! neq 0 (
        echo Test Case #%%i Failed!
        set FAILED_CASE=%%i

        :: Save the failed input/output
        copy input.txt failed_input.txt > nul
        copy output_optimized.txt failed_output_optimized.txt > nul
        copy output_brute.txt failed_output_brute.txt > nul
        goto :failed
    )

    echo Test Case #%%i Passed.
)

:: Clean up temporary files if all tests passed
echo All test cases passed successfully!
echo Cleaning up temporary files...
if exist input.txt del input.txt
if exist output_optimized.txt del output_optimized.txt
if exist output_brute.txt del output_brute.txt
exit /b 0

:failed
echo.
echo --------------------------------------
echo Test Case #%FAILED_CASE% Failed!
echo --------------------------------------
echo Input (failed_input.txt):
type failed_input.txt
echo --------------------------------------
echo Output (Optimized - failed_output_optimized.txt):
type failed_output_optimized.txt
echo --------------------------------------
echo Output (Brute Force - failed_output_brute.txt):
type failed_output_brute.txt
echo --------------------------------------
echo Temporary files have been preserved for debugging.
exit /b 1

:compare_files
:: Robust file comparison subroutine
fc %1 %2 > nul
if %ERRORLEVEL% neq 0 (
    :: If direct comparison fails, use more lenient comparison
    findstr /v /r /c:"^[ \t]*$" %1 > %1_cleaned.txt
    findstr /v /r /c:"^[ \t]*$" %2 > %2_cleaned.txt
    
    fc %1_cleaned.txt %2_cleaned.txt > nul
    set COMPARE_RESULT=%ERRORLEVEL%
    
    del %1_cleaned.txt %2_cleaned.txt
    exit /b !COMPARE_RESULT!
)
exit /b 0