gcc -D MM_DebugOn -D MM_DefragOn bsl_MM.c hal_MM.c test_hal_MM.c -o test_hal_MM.exe
rem pause
test_hal_MM.exe > test_hal_MM.txt 2>&1
type               test_hal_MM.txt
