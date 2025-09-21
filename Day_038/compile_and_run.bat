@echo off
REM Compilation and execution script for C++ Pointers Learning Guide
REM Author: C++ Pointers Learning Guide
REM 
REM This script compiles and runs all the C++ pointer demonstration files
REM Usage: compile_and_run.bat [file_number] or compile_and_run.bat all

echo =========================================
echo   C++ POINTERS LEARNING GUIDE
echo   Compilation and Execution Script
echo =========================================

if "%1"=="" (
    echo Usage: compile_and_run.bat [option]
    echo Options:
    echo   1  - Basic Pointers
    echo   2  - Pointer Arithmetic  
    echo   3  - Pointers and Arrays
    echo   4  - Pointers and Functions
    echo   5  - Dynamic Memory Management
    echo   6  - Advanced Pointers
    echo   7  - Smart Pointers
    echo   8  - Practical Exercises
    echo   9  - Main Demo
    echo   all - Compile all files
    echo   runall - Compile and run all files sequentially
    echo   clean - Remove all executables
    goto :end
)

set COMPILER=g++
set FLAGS=-std=c++17 -Wall -Wextra -O2
set DEBUG_FLAGS=-std=c++17 -Wall -Wextra -g -fsanitize=address

if "%1"=="clean" (
    echo Cleaning up executables...
    del /Q *.exe 2>nul
    echo Done!
    goto :end
)

if "%1"=="all" (
    echo Compiling all files...
    
    echo [1/9] Compiling Basic Pointers...
    %COMPILER% %FLAGS% -o 01_basic_pointers.exe 01_basic_pointers.cpp
    
    echo [2/9] Compiling Pointer Arithmetic...
    %COMPILER% %FLAGS% -o 02_pointer_arithmetic.exe 02_pointer_arithmetic.cpp
    
    echo [3/9] Compiling Pointers and Arrays...
    %COMPILER% %FLAGS% -o 03_pointers_arrays.exe 03_pointers_arrays.cpp
    
    echo [4/9] Compiling Pointers and Functions...
    %COMPILER% %FLAGS% -o 04_pointers_functions.exe 04_pointers_functions.cpp
    
    echo [5/9] Compiling Dynamic Memory...
    %COMPILER% %FLAGS% -o 05_dynamic_memory.exe 05_dynamic_memory.cpp
    
    echo [6/9] Compiling Advanced Pointers...
    %COMPILER% %FLAGS% -o 06_advanced_pointers.exe 06_advanced_pointers.cpp
    
    echo [7/9] Compiling Smart Pointers...
    %COMPILER% %FLAGS% -o 07_smart_pointers.exe 07_smart_pointers.cpp
    
    echo [8/9] Compiling Practical Exercises...
    %COMPILER% %FLAGS% -o 08_practical_exercises.exe 08_practical_exercises.cpp
    
    echo [9/9] Compiling Main Demo...
    %COMPILER% %FLAGS% -o 09_main_demo.exe 09_main_demo.cpp
    
    echo All files compiled successfully!
    echo Run individual executables or use specific numbers with this script.
    goto :end
)

if "%1"=="runall" (
    echo Compiling and running all files sequentially...
    echo =============================================
    
    echo.
    echo [1/9] BASIC POINTERS
    echo ====================
    %COMPILER% %FLAGS% -o 01_basic_pointers.exe 01_basic_pointers.cpp
    if %ERRORLEVEL%==0 01_basic_pointers.exe
    echo.
    pause
    
    echo.
    echo [2/9] POINTER ARITHMETIC
    echo ========================
    %COMPILER% %FLAGS% -o 02_pointer_arithmetic.exe 02_pointer_arithmetic.cpp
    if %ERRORLEVEL%==0 02_pointer_arithmetic.exe
    echo.
    pause
    
    echo.
    echo [3/9] POINTERS AND ARRAYS
    echo =========================
    %COMPILER% %FLAGS% -o 03_pointers_arrays.exe 03_pointers_arrays.cpp
    if %ERRORLEVEL%==0 03_pointers_arrays.exe
    echo.
    pause
    
    echo.
    echo [4/9] POINTERS AND FUNCTIONS
    echo ============================
    %COMPILER% %FLAGS% -o 04_pointers_functions.exe 04_pointers_functions.cpp
    if %ERRORLEVEL%==0 04_pointers_functions.exe
    echo.
    pause
    
    echo.
    echo [5/9] DYNAMIC MEMORY MANAGEMENT
    echo ===============================
    %COMPILER% %FLAGS% -o 05_dynamic_memory.exe 05_dynamic_memory.cpp
    if %ERRORLEVEL%==0 05_dynamic_memory.exe
    echo.
    pause
    
    echo.
    echo [6/9] ADVANCED POINTERS
    echo =======================
    %COMPILER% %FLAGS% -o 06_advanced_pointers.exe 06_advanced_pointers.cpp
    if %ERRORLEVEL%==0 06_advanced_pointers.exe
    echo.
    pause
    
    echo.
    echo [7/9] SMART POINTERS
    echo ====================
    %COMPILER% %FLAGS% -o 07_smart_pointers.exe 07_smart_pointers.cpp
    if %ERRORLEVEL%==0 07_smart_pointers.exe
    echo.
    pause
    
    echo.
    echo [8/9] PRACTICAL EXERCISES
    echo =========================
    %COMPILER% %FLAGS% -o 08_practical_exercises.exe 08_practical_exercises.cpp
    if %ERRORLEVEL%==0 08_practical_exercises.exe
    echo.
    pause
    
    echo.
    echo [9/9] MAIN DEMO
    echo ===============
    %COMPILER% %FLAGS% -o 09_main_demo.exe 09_main_demo.cpp
    if %ERRORLEVEL%==0 09_main_demo.exe
    
    echo.
    echo =============================================
    echo All demonstrations completed successfully!
    echo =============================================
    goto :end
)

if "%1"=="1" (
    echo Compiling and running Basic Pointers...
    %COMPILER% %FLAGS% -o 01_basic_pointers.exe 01_basic_pointers.cpp
    if %ERRORLEVEL%==0 (
        echo.
        01_basic_pointers.exe
    )
    goto :end
)

if "%1"=="2" (
    echo Compiling and running Pointer Arithmetic...
    %COMPILER% %FLAGS% -o 02_pointer_arithmetic.exe 02_pointer_arithmetic.cpp
    if %ERRORLEVEL%==0 (
        echo.
        02_pointer_arithmetic.exe
    )
    goto :end
)

if "%1"=="3" (
    echo Compiling and running Pointers and Arrays...
    %COMPILER% %FLAGS% -o 03_pointers_arrays.exe 03_pointers_arrays.cpp
    if %ERRORLEVEL%==0 (
        echo.
        03_pointers_arrays.exe
    )
    goto :end
)

if "%1"=="4" (
    echo Compiling and running Pointers and Functions...
    %COMPILER% %FLAGS% -o 04_pointers_functions.exe 04_pointers_functions.cpp
    if %ERRORLEVEL%==0 (
        echo.
        04_pointers_functions.exe
    )
    goto :end
)

if "%1"=="5" (
    echo Compiling and running Dynamic Memory Management...
    %COMPILER% %FLAGS% -o 05_dynamic_memory.exe 05_dynamic_memory.cpp
    if %ERRORLEVEL%==0 (
        echo.
        05_dynamic_memory.exe
    )
    goto :end
)

if "%1"=="6" (
    echo Compiling and running Advanced Pointers...
    %COMPILER% %FLAGS% -o 06_advanced_pointers.exe 06_advanced_pointers.cpp
    if %ERRORLEVEL%==0 (
        echo.
        06_advanced_pointers.exe
    )
    goto :end
)

if "%1"=="7" (
    echo Compiling and running Smart Pointers...
    %COMPILER% %FLAGS% -o 07_smart_pointers.exe 07_smart_pointers.cpp
    if %ERRORLEVEL%==0 (
        echo.
        07_smart_pointers.exe
    )
    goto :end
)

if "%1"=="8" (
    echo Compiling and running Practical Exercises...
    %COMPILER% %FLAGS% -o 08_practical_exercises.exe 08_practical_exercises.cpp
    if %ERRORLEVEL%==0 (
        echo.
        08_practical_exercises.exe
    )
    goto :end
)

if "%1"=="9" (
    echo Compiling and running Main Demo...
    %COMPILER% %FLAGS% -o 09_main_demo.exe 09_main_demo.cpp
    if %ERRORLEVEL%==0 (
        echo.
        09_main_demo.exe
    )
    goto :end
)

if "%1"=="debug" (
    echo Debug compilation mode enabled
    echo Choose file to compile with debug flags:
    echo Enter file number (1-9):
    set /p choice=
    
    if "!choice!"=="1" (
        %COMPILER% %DEBUG_FLAGS% -o 01_basic_pointers_debug.exe 01_basic_pointers.cpp
        01_basic_pointers_debug.exe
    )
    REM Add other debug options as needed
    goto :end
)

echo Invalid option: %1
echo Use compile_and_run.bat without arguments to see usage.

:end
echo.
echo Script completed.
pause
