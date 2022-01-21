/* MemMan.c - Memory Manager for segments of blocks - 12 mars 2003 */

#if defined(DEBUG)
#include <stdio.h>
#endif

#include "MemMan.h"

#define BLOCK_SIZE      16 /* bytes */
#define BYTE_MAP_SIZE  127 /* blocks */
/* 127 is the max positive number of blocks possible (128 == -128) */

#define HEAP_SIZE      BLOCK_SIZE * BYTE_MAP_SIZE

#define roundToNextBlock(w) ( ((BLOCK_SIZE-1) + (ushort)(w)) & (~(BLOCK_SIZE-1)) )
#define truncToNextBlock(w) ( (                 (ushort)(w)) & (~(BLOCK_SIZE-1)) )

private sbyte  byteMap[BYTE_MAP_SIZE];
private byte   heap[HEAP_SIZE];
private ushort nextp;

public void MemoryManager_init(void) {
    ushort n;

    nextp = 0;
    byteMap[0] = BYTE_MAP_SIZE;
    for ( n = 1; n < BYTE_MAP_SIZE; n++ )
        byteMap[n] = 0;
}


#if defined(GC)
public void MemoryManager_gc(void) {
    ushort n, mark;
    sbyte  nFreeBlocks, nBlocks;

    for ( n = 0; n < BYTE_MAP_SIZE; n++ ) {
        if ( byteMap[n] > 0 ) {          /* free block? */
            nFreeBlocks = 0;
            mark = n;                    /* mark the first free block */
            while ( byteMap[n] > 0 ) {   /* collect all contiguous free blocks */
                nBlocks = byteMap[n];
                nFreeBlocks += nBlocks;
                byteMap[n] = 0;
                n += nBlocks;
            }
            byteMap[mark] = nFreeBlocks;
        }
    }
}
#endif

public void MemoryManager_freeSegment(void* ap) {
    ushort n = ((byte*)ap - heap)/BLOCK_SIZE; /* starting at byteMap[n] */

    byteMap[n] = -byteMap[n];
}

private void MemoryManager_printByteMap(void); /* called by getSegment */

public void* MemoryManager_getSegment(ushort nBytes) {
    ushort segmentSize, n;
    sbyte  bm, nBlocks;
    byte*  segment = 0;

#if defined(GC)
    bool  gc = false;
#endif

    if ( nBytes > HEAP_SIZE ) return 0;

#if defined(GC)
  retryAfterGC:
#endif

    segmentSize = roundToNextBlock(nBytes);
    nBlocks = segmentSize/BLOCK_SIZE;
    for ( n = 0; n < BYTE_MAP_SIZE; n++, nextp = (nextp + 1) % BYTE_MAP_SIZE )
        if ( (bm = byteMap[nextp]) > 0 )           /* free block? */
            if ( bm >= nBlocks ) {                 /* big enough? */
                segment = &heap[nextp*BLOCK_SIZE];
                byteMap[nextp + nBlocks] = bm - nBlocks;
                byteMap[nextp] = -nBlocks;
                nextp += nBlocks;
                break;
            }
#if defined(DEBUG)
printf("MemoryManager_getSegment: segmentSize = %04d  =>  %d block(s) at address = %04x\n",
                      segmentSize, nBlocks, segment);
#endif

#if defined(GC)
    if (segment == 0  &&  !gc) {
        printf("No more memory... calling GC\n");
        MemoryManager_gc();
        gc = true;
        printf("ByteMap:\n");
        MemoryManager_printByteMap();
        goto retryAfterGC;
    }
#endif
    return segment;
}

#if defined(DEBUG)
#include <stdlib.h> /* for srand, rand, atol, exit */

private void MemoryManager_printByteMap(void) {
    ushort n;

    for ( n = 0; n < BYTE_MAP_SIZE; n++)
        printf("%d ", byteMap[n] );
    printf("\n");
}

private byte* mp[10];

private void MemoryManager_freeAllSegmentsRandomly(void) {
    ushort n;
    bool   allFreed = false;

    while ( !allFreed ) {
         n = (ushort)(rand() % 10);
         if ( mp[n] ) {
             printf("MemoryManager_freeAllSegmentsRandomly: segment #%d at %04x\n", n, mp[n]);
             MemoryManager_freeSegment(mp[n]);
             mp[n] = 0;
         }
         for ( allFreed = true, n = 0; n < 10; n++ )
             if ( mp[n] )
                 allFreed = false;
    }
}
private void MemoryManager_requestAtRandom(ushort maxSize, bool withGC) {
    ushort n, size;

    srand(maxSize);
    for ( n = 0; n < 10; ) {
        size = (ushort)(rand() % maxSize);
        if (size) {
            printf("MemoryManager_requestAtRandom: %d bytes\n", size);
            mp[n] = MemoryManager_getSegment(size);
            MemoryManager_printByteMap();
            n++;
        } else {
            printf("MemoryManager_requestAtRandom: no request if %d bytes\n", size);
        }
    }
    MemoryManager_freeAllSegmentsRandomly();
    MemoryManager_printByteMap();
#if defined(GC)
    if ( withGC ) {
        MemoryManager_gc();
        MemoryManager_printByteMap();
    }
#endif
}
/*------------------------------------------------------------------
 * main
 *------------------------------------------------------------------*/
void main(int argc, char* argv[]) {
    if (argc == 4) {
        MemoryManager_init();

#if defined(GC)
        /* with GC */
        MemoryManager_requestAtRandom( (ushort)atoi(argv[1]), true );
        MemoryManager_requestAtRandom( (ushort)atoi(argv[2]), true );
        MemoryManager_requestAtRandom( (ushort)atoi(argv[3]), true );
#endif

        /* without GC */
        MemoryManager_requestAtRandom( (ushort)atoi(argv[1]), false );
        MemoryManager_requestAtRandom( (ushort)atoi(argv[2]), false );
        MemoryManager_requestAtRandom( (ushort)atoi(argv[3]), false );

#if defined(GC)
        MemoryManager_gc();
#endif
        MemoryManager_printByteMap();
    } else {
        printf("Usage: MemMan <smallSize> <mediumSize> <largeSize>\n");
    }
}
#endif
