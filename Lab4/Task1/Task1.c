#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

int main(){
    // Onboard LED
    DDRB |= (1 << 5);
    PORTB |= (1 << 5);

    // Input pin setup - DDRD no need because input by default
    PORTD |= (1 << 2);

    // Setup external interrupt
    EIMSK |= (1 << 0);

    // Logical change will trigger ISR
    EICRA |= (1 << 0);

    sei();
    while(true){
        PORTB |= (1 << 5);
        _delay_ms(5000);
    }
    return 0;
}

ISR(INT0_vect){
    cli(); // Disable interrupt
    PORTB &= ~(1 << 5); // Turn off LED (bitwise clear)
    sei(); // Enable interrupt
}