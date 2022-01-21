#if defined(MM_DebugOn)
#include <stdio.h>
#include "bsl_MM.h" // bsl_MM_GetNumberOfFreeBlocks()
#endif

#include "hal_MM.h"
#include <stdbool.h>

#define BlockSize 64 // bytes
#define HeapSize (BlockSize * ByteMapSize)

#define RoundToNextBlock(nBytes) (((BlockSize - 1) + (uint16_t)(nBytes)) & (~(BlockSize - 1)))
#define TruncToNextBlock(nBytes) (((uint16_t)(nBytes)) & (~(BlockSize - 1)))

int8_t byteMap[ByteMapSize];
static uint8_t heap[HeapSize];
static uint16_t nextp;

void hal_MM_Init(void)
{
    uint16_t n;

    nextp = 0;
    byteMap[0] = ByteMapSize;
    for (n = 1; n < ByteMapSize; n++)
        byteMap[n] = 0;
}

#if defined(MM_DefragOn)
void hal_MM_Defrag(void)
{
    uint16_t n, mark;
    int8_t nFreeBlocks, nBlocks;

    for (n = 0; n < ByteMapSize; n++)
    {
        if (byteMap[n] > 0)
        { /* free block? */
            nFreeBlocks = 0;
            mark = n; /* mark the first free block */
            while (byteMap[n] > 0)
            { /* collect all contiguous free blocks */
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

void hal_MM_FreeSegment(void *ap)
{
    uint16_t n = ((uint8_t *)ap - heap) / BlockSize; /* starting at byteMap[n] */

    byteMap[n] = -byteMap[n];
}

void hal_MM_PrintByteMap(void); /* called by getSegment */

void *hal_MM_GetSegment(uint16_t nBytes)
{
    uint16_t segmentSize, n;
    int8_t bm, nBlocks;
    uint8_t *segment = 0;

#if defined(MM_DefragOn)
    bool defrag = false;
#endif

    if (nBytes > HeapSize)
        return 0;

#if defined(MM_DefragOn)
retryAfterDefrag:
#endif

    segmentSize = RoundToNextBlock(nBytes);
    nBlocks = segmentSize / BlockSize;
    for (n = 0; n < ByteMapSize; n++, nextp = (nextp + 1) % ByteMapSize)
        if ((bm = byteMap[nextp]) > 0) /* free block? */
            if (bm >= nBlocks)
            { /* big enough? */
                segment = &heap[nextp * BlockSize];
                byteMap[nextp + nBlocks] = bm - nBlocks;
                byteMap[nextp] = -nBlocks;
                nextp += nBlocks;
                break;
            }
#if defined(MM_DebugOn)
    printf("%03d->%03d[%d]@%04x\n", nBytes, segmentSize, nBlocks, (uint16_t)(segment - heap));
#endif

#if defined(MM_DefragOn)
    if (segment == 0 && !defrag)
    {
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

void hal_MM_PrintByteMap(void)
{
    uint16_t n;

    printf("byteMap:");
    for (n = 0; n < ByteMapSize; n++)
        printf("%d ", byteMap[n]);
    printf("\n");
}

#endif
