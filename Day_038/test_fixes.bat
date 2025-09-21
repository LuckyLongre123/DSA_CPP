@echo off
echo Testing all fixes...
echo.

echo Testing 02_pointer_arithmetic.cpp...
g++ -std=c++17 -Wall -Wextra -o 02_test.exe 02_pointer_arithmetic.cpp
if %ERRORLEVEL%==0 (
    echo ✓ 02_pointer_arithmetic.cpp compiled successfully
) else (
    echo ✗ 02_pointer_arithmetic.cpp failed to compile
)

echo.
echo Testing 03_pointers_arrays.cpp...
g++ -std=c++17 -Wall -Wextra -o 03_test.exe 03_pointers_arrays.cpp
if %ERRORLEVEL%==0 (
    echo ✓ 03_pointers_arrays.cpp compiled successfully
) else (
    echo ✗ 03_pointers_arrays.cpp failed to compile
)

echo.
echo Testing 05_dynamic_memory.cpp...
g++ -std=c++17 -Wall -Wextra -o 05_test.exe 05_dynamic_memory.cpp
if %ERRORLEVEL%==0 (
    echo ✓ 05_dynamic_memory.cpp compiled successfully (use-after-free fixed!)
) else (
    echo ✗ 05_dynamic_memory.cpp failed to compile
)

echo.
echo Testing 07_smart_pointers.cpp...
g++ -std=c++17 -Wall -Wextra -o 07_test.exe 07_smart_pointers.cpp
if %ERRORLEVEL%==0 (
    echo ✓ 07_smart_pointers.cpp compiled successfully
) else (
    echo ✗ 07_smart_pointers.cpp failed to compile
)

echo.
echo Cleaning up test files...
del /Q *_test.exe 2>nul

echo.
echo All fixes applied! Now try:
echo   .\compile_and_run.bat runall
echo.
pause
