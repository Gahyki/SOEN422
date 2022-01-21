#ifndef __bsl_Interrupt_h
#define __bsl_Interrupt_h

#include <avr/io.h>

#define Interrupt_Disable cli() // built in function the chip
#define Interrupt_Enable sei() // built in function the chip

#endif // __bsl_Interrupt_h