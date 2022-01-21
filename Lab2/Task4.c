#include <stdlib.h> // malloc, free
#include <avr/io.h>
#include <util/delay.h>
#include "Task4.h"

typedef struct LedDesc {

} LedDesc, *Led;

Led led;

void Led_Init(Led self) {
    DDRB |= (1 << 5); // Modify the pinMode to Output mode
}

void Led_TurnOff(Led self) {
    PORTB &= ~(1 << 5); // Clear the bit to turn it off
    _delay_ms(1000); // Delay one second
}

void Led_TurnOn(Led self) {
    PORTB |= (1 << 5); // Modify the bit to turn it on
    _delay_ms(1000); // Delay one second
}

Led Led_New(void) {
    Led led = (Led) malloc(sizeof(LedDesc)); // Allocating the appropriate amount of memory
    Led_Init(led); // Initialize LED
    return led;
}

void Led_Delete(Led self) {
    free(led); // Free up memory space
}