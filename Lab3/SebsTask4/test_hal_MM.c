#include "hal_MM.h"

/*------------------------------------------------------------------
 * main
 *------------------------------------------------------------------*/
int main(int argc, char* argv[]) {
    uint8_t* mp[10];

    hal_MM_Init();
    hal_MM_PrintByteMap();

    mp[0] = hal_MM_GetSegment(106);
    hal_MM_PrintByteMap();
    printf("main:FreeBlocks[%u]\n---\n", bsl_MM_GetNumberOfFreeBlocks());
    mp[1] = hal_MM_GetSegment(143);
    hal_MM_PrintByteMap();
    printf("main:FreeBlocks[%u]\n---\n", bsl_MM_GetNumberOfFreeBlocks());
    mp[2] = hal_MM_GetSegment( 34);
    hal_MM_PrintByteMap();
    printf("main:FreeBlocks[%u]\n---\n", bsl_MM_GetNumberOfFreeBlocks());
    mp[3] = hal_MM_GetSegment(213);
    hal_MM_PrintByteMap();
    printf("main:FreeBlocks[%u]\n---\n", bsl_MM_GetNumberOfFreeBlocks());
    mp[4] = hal_MM_GetSegment( 42);
    hal_MM_PrintByteMap();
    printf("main:FreeBlocks[%u]\n---\n", bsl_MM_GetNumberOfFreeBlocks());
    mp[5] = hal_MM_GetSegment(215);
    hal_MM_PrintByteMap();
    printf("main:FreeBlocks[%u]\n---\n", bsl_MM_GetNumberOfFreeBlocks());
    mp[6] = hal_MM_GetSegment(15);
    hal_MM_PrintByteMap();
    printf("main:FreeBlocks[%u]\n---\n", bsl_MM_GetNumberOfFreeBlocks());

    printf("main:** Start freeing segments and defragmentation\n");
    for (int n = 0; n < 7; n++) {
        printf("\nmain:** Free segment #%d\n", n);
        hal_MM_FreeSegment(mp[n]);
        hal_MM_PrintByteMap();
        printf("main: Before defrag - FreeBlocks[%u]\n", bsl_MM_GetNumberOfFreeBlocks());
        hal_MM_Defrag();
        hal_MM_PrintByteMap();
        printf("main: After  defrag - FreeBlocks[%u]\n", bsl_MM_GetNumberOfFreeBlocks());
    }
    printf("\nmain: Exit - FreeBlocks[%u]\n", bsl_MM_GetNumberOfFreeBlocks());
    return 0;
}

/* Output:

C:\>cl /EHsc hal_MM.c bsl_MM.c /DMM_DebugOn /DMM_DefragOn /link /out:TestMM.exe
Microsoft (R) C/C++ Optimizing Compiler Version 19.26.28806 for x64
Copyright (C) Microsoft Corporation.  All rights reserved.

hal_MM.c
bsl_MM.c
Generating Code...
Microsoft (R) Incremental Linker Version 14.26.28806.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:hal_MM.exe
/out:TestMM.exe
hal_MM.obj
bsl_MM.obj

C:\>TestMM.exe
byteMap:16 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
106->128[2]@0000
byteMap:-2 0 14 0 0 0 0 0 0 0 0 0 0 0 0 0
main:FreeBlocks[14]
---
143->192[3]@0080
byteMap:-2 0 -3 0 0 11 0 0 0 0 0 0 0 0 0 0
main:FreeBlocks[11]
---
034->064[1]@0140
byteMap:-2 0 -3 0 0 -1 10 0 0 0 0 0 0 0 0 0
main:FreeBlocks[10]
---
213->256[4]@0180
byteMap:-2 0 -3 0 0 -1 -4 0 0 0 6 0 0 0 0 0
main:FreeBlocks[6]
---
042->064[1]@0280
byteMap:-2 0 -3 0 0 -1 -4 0 0 0 -1 5 0 0 0 0
main:FreeBlocks[5]
---
215->256[4]@02c0
byteMap:-2 0 -3 0 0 -1 -4 0 0 0 -1 -4 0 0 0 1
main:FreeBlocks[1]
---
015->064[1]@03c0
byteMap:-2 0 -3 0 0 -1 -4 0 0 0 -1 -4 0 0 0 -1
main:FreeBlocks[16]
---
main:** Start freeing segments and defragmentation

main:** Free segment #0
byteMap:2 0 -3 0 0 -1 -4 0 0 0 -1 -4 0 0 0 -1
main: Before defrag - FreeBlocks[2]
byteMap:2 0 -3 0 0 -1 -4 0 0 0 -1 -4 0 0 0 -1
main: After  defrag - FreeBlocks[2]

main:** Free segment #1
byteMap:2 0 3 0 0 -1 -4 0 0 0 -1 -4 0 0 0 -1
main: Before defrag - FreeBlocks[5]
byteMap:5 0 0 0 0 -1 -4 0 0 0 -1 -4 0 0 0 -1
main: After  defrag - FreeBlocks[5]

main:** Free segment #2
byteMap:5 0 0 0 0 1 -4 0 0 0 -1 -4 0 0 0 -1
main: Before defrag - FreeBlocks[6]
byteMap:6 0 0 0 0 0 -4 0 0 0 -1 -4 0 0 0 -1
main: After  defrag - FreeBlocks[6]

main:** Free segment #3
byteMap:6 0 0 0 0 0 4 0 0 0 -1 -4 0 0 0 -1
main: Before defrag - FreeBlocks[10]
byteMap:10 0 0 0 0 0 0 0 0 0 -1 -4 0 0 0 -1
main: After  defrag - FreeBlocks[10]

main:** Free segment #4
byteMap:10 0 0 0 0 0 0 0 0 0 1 -4 0 0 0 -1
main: Before defrag - FreeBlocks[11]
byteMap:11 0 0 0 0 0 0 0 0 0 0 -4 0 0 0 -1
main: After  defrag - FreeBlocks[11]

main:** Free segment #5
byteMap:11 0 0 0 0 0 0 0 0 0 0 4 0 0 0 -1
main: Before defrag - FreeBlocks[15]
byteMap:15 0 0 0 0 0 0 0 0 0 0 0 0 0 0 -1
main: After  defrag - FreeBlocks[15]

main:** Free segment #6
byteMap:15 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
main: Before defrag - FreeBlocks[16]
byteMap:16 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
main: After  defrag - FreeBlocks[16]

main: Exit - FreeBlocks[16]

*/