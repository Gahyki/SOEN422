#include "Task3.h"

typedef struct{

} LED;

static LED l;

void Led_Init(){
    DDRB |= (1 << 5); // Modify the pinMode to Output mode
}

void Led_TurnOn(){
    PORTB |= (1 << 5); // Clear the bit to turn it off
    _delay_ms(1000);
}

void Led_TurnOff(){
    PORTB &= ~(1 << 5); // Modify the bit to turn it on
    _delay_ms(1000);
}