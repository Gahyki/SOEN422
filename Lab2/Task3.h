#ifndef __LEDADS_h
#define __LEDADS_h

#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>


void Led_Init(); // Initialize the LED mode
void Led_TurnOn(); // Turn on LED
void Led_TurnOff(); // Turn off LED

#endif