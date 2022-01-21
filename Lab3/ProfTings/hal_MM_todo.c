// hal_MM_todo.c - Memory Manager for segments of blocks
// (c) 1993-2021 Michel de Champlain

#if defined(MM_DebugOn)
#include <stdio.h>
#include "bsl_MM.h" // bsl_MM_GetNumberOfFreeBlocks()
#endif

#include "hal_MM.h"
#include <stdbool.h>

//moved to bsl_MM.h  #define ByteMapSize   16 // blocks

#define BlockSize     64 // bytes
#define HeapSize     (BlockSize * ByteMapSize)

#define RoundToNextBlock(nBytes) ( ((BlockSize-1) + (uint16_t)(nBytes)) & (~(BlockSize-1)) )
#define TruncToNextBlock(nBytes) ( (                (uint16_t)(nBytes)) & (~(BlockSize-1)) )

/*static*/ int8_t    byteMap[ByteMapSize];
static     uint8_t   heap[HeapSize];
static     uint16_t  nextp;

void hal_MM_Init(void) {
    // your code...
}


#if defined(MM_DefragOn)
void hal_MM_Defrag(void) {
    // your code...
}
#endif

void hal_MM_FreeSegment(void* ap) {
    // your code...
}

void hal_MM_PrintByteMap(void); /* called by getSegment */

void* hal_MM_GetSegment(uint16_t nBytes) {
    // your code...

#if defined(MM_DefragOn)
    bool  defrag = false;
#endif

    if ( nBytes > HeapSize ) return 0;

#if defined(MM_DefragOn)
retryAfterDefrag:
#endif

    // your code...

#if defined(MM_DebugOn)
    printf("%03d->%03d[%d]@%04x\n", nBytes, segmentSize, nBlocks, (uint16_t)(segment-heap));
#endif

#if defined(MM_DefragOn)
    if (segment == 0  &&  !defrag) {
#if defined(MM_DebugOn)
        printf("No more memory... calling Defrag\n");
#endif
        hal_MM_Defrag();
        defrag = true;
#if defined(MM_DebugOn)
        printf("ByteMap:\n");
        hal_MM_PrintByteMap();
#endif
        goto retryAfterDefrag;
    }
#endif
    return segment;
}

#if defined(MM_DebugOn)

void hal_MM_PrintByteMap(void) {
    uint16_t n;

    printf("byteMap:");
    for ( n = 0; n < ByteMapSize; n++)
        printf("%d ", byteMap[n]);
    printf("\n");
}

uint8_t* mp[10];

/*------------------------------------------------------------------
 * main
 *------------------------------------------------------------------*/
int main(int argc, char* argv[]) {
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
#endif

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
