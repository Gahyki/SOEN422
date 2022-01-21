#ifndef __hal_util_BitMacros_h
#define __hal_util_BitMacros_h

#define hal_util_Bit_Read(value,bit) (((value) >> (bit)) & 0x01); // Find the value at the bit position and read
#define hal_util_Bit_Set(value,bit) ((value) |= (1UL << (bit))); // At a specific position in the register, replace a the bit with a new bit value
#define hal_util_Bit_Clear(value,bit) ((value) &= ~(1UL << (bit))); // At a specific position in the register, clear the bit
#define hal_util_Bit_Toggle(value,bit) ((value) ^= (1UL << (bit))); // At a specific position in the register, toggle the bit
#define hal_util_Bit_Write(value,bit,bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit)); // At a specific position in the register, switch the bit value to make it write mode

#endif // __hal_util_BitMacros_h