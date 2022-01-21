/* MemMan.h - Memory Manager - Michel de Champlain - 12 mars 2003 */

#ifndef MemMan_h
#define MemMan_h

#include "cddef.h"

public void  MemoryManager_init(void);
public void* MemoryManager_getSegment(ushort nBytes);
public void  MemoryManager_freeSegment(void* segmentBaseAddress);

#if defined(GC)
public void  MemoryManager_gc(void);
#endif

#endif