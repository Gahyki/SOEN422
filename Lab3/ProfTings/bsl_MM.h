// bsl_MM.h - BSL Memory Manager (MM) to get the number of free blocks.
// (c) 2021 Michel de Champlain

#ifndef __bsl_MM_h
#define __bsl_MM_h

#include <stdint.h>

// ByteMapSize and byteMap are shared (included)
// in bsl_MM.c and hal.MM.c implementations:
#define ByteMapSize   16         // blocks
extern  int8_t        byteMap[];

uint8_t bsl_MM_GetNumberOfFreeBlocks(void);

#endif __bsl_MM_h
