#ifndef __bsl_MM_h
#define __bsl_MM_h

#include <stdint.h>

#define ByteMapSize   16         // blocks
extern  int8_t        byteMap[];

uint8_t bsl_MM_GetNumberOfFreeBlocks(void); // Returns the number of free blocks

#endif //__bsl_MM_h