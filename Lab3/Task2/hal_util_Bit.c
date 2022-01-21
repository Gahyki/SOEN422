#include "hal_util_Bit.h"

uint8_t hal_util_Bit_Read (uint8_t value, uint8_t bit){
    // Find the value at the bit position and read
    return (((value) >> (bit)) & 0x01);
}

uint8_t hal_util_Bit_Set (uint8_t value, uint8_t bit){
    // At a specific position in the register, replace a the bit with a new bit value
    return ((value) |= (1UL << (bit)));
}

uint8_t hal_util_Bit_Clear (uint8_t value, uint8_t bit){
    // At a specific position in the register, clear the bit
    return ((value) &= ~(1UL << (bit)));
}

uint8_t hal_util_Bit_Toggle(uint8_t value, uint8_t bit){
    // At a specific position in the register, toggle the bit
    return ((value) ^= (1UL << (bit)));
}

uint8_t hal_util_Bit_Write (uint8_t value, uint8_t bit, bool bitvalue){
    // At a specific position in the register, switch the bit value to make it write mode
    return ((value) ^= (1UL << (bit)));
}