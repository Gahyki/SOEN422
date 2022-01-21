#ifndef __bsl_Bargraph_h
#define __bsl_Bargraph_h

#include <avr/io.h>
#include <util/delay.h>

#define LedDirection DDRB // Variable to reference DDRB register
#define LedRegister PORTB // Variable to reference PORTB register
#define LedOne (1 << 0) // Variable to reference digitalpin8 register
#define LedTwo (1 << 1) // Variable to reference digitalpin9 register
#define LedThree (1 << 2) // Variable to reference digitalpin10 register
#define LedFour (1 << 3) // Variable to reference digitalpin11 register
#define LedInput (~(0 << 4)) // Variable to reference digitalpin12 register

#endif // __bsl_Bargraph_h