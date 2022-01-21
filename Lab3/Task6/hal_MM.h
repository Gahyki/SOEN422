#ifndef __hal_MM_h
#define __hal_MM_h

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "bsl_MM.h"


void hal_MM_Init(void);
void* hal_MM_GetSegment(uint16_t nBytes);
void hal_MM_FreeSegment(void* segmentBaseAddress);

#if defined(MM_DefragOn)
void hal_MM_Defrag(void);
#endif

#endif //__hal_MM_h
