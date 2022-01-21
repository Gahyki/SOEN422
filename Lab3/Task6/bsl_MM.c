#include "bsl_MM.h"


uint8_t bsl_MM_GetNumberOfFreeBlocks(void){
    uint32_t n;
    uint8_t nFreeBlocks = 0; // Counter for the nb of free blocks
    uint8_t nBlocks = 0;
    for(n = 0; n < ByteMapSize; n++){ // For each Byte in ByteMap
        if(byteMap[n] > 0){ // If the Byte is greater than 0
            nFreeBlocks = 0;
            while(byteMap[n] > 0){
                nBlocks = byteMap[n]; // Number of free blocks
                nFreeBlocks += nBlocks;
                n += nBlocks;
            }
        }
    }
    return nFreeBlocks;
}
