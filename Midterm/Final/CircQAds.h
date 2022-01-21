#ifndef __CircQAds_h
#define __CircQAds_h
#include <stdbool.h>
#include <stdint.h>
void    CircQ_Init(void);
bool    CircQ_IsEmpty(void);
bool    CircQ_IsFull(void);
void    CircQ_Add(uint8_t item);
uint8_t CircQ_Remove(void);

#endif