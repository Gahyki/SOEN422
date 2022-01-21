#ifndef __hal_util_Bit_h
#define __hal_util_Bit_h

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>

uint8_t hal_util_Bit_Read (uint8_t value, uint8_t bit); // Read
uint8_t hal_util_Bit_Set (uint8_t value, uint8_t bit); // Set
uint8_t hal_util_Bit_Clear (uint8_t value, uint8_t bit); // Clear
uint8_t hal_util_Bit_Toggle(uint8_t value, uint8_t bit); // Toggle
uint8_t hal_util_Bit_Write (uint8_t value, uint8_t bit, bool bitvalue); // Write

#endif // __hal_util_Bit_h
