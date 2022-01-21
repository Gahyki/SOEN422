
#include "bsl_MM.h"

uint8_t bsl_MM_GetNumberOfFreeBlocks(void){
    int8_t  nFreeBlocks;

    for (uint16_t n = 0; n < ByteMapSize; n++ ) {
        if ( byteMap[n] > 0 ) {          /* free block? */
            nFreeBlocks = 0;
            while ( byteMap[n] > 0 ) {   /* collect all contiguous free blocks */
                nFreeBlocks += byteMap[n];
                n += byteMap[n];
            }
        }
    }

    return nFreeBlocks;
}
