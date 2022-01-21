gcc -D MM_DebugOn -D MM_DefragOn bsl_MM.c hal_MM.c test_MM.c -o test_MM.exe
rem pause
test_MM.exe > test_MM.txt 2>&1
type               test_MM.txt 