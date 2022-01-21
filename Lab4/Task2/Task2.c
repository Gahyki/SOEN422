#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

int main(){
    // Onboard LED
    DDRB |= (1 << 5);
    PORTB &= ~(1 << 5);
    
    // PB0 input
    DDRB &= ~(1 << 0);

    // DDRD output
    DDRD |= (1 << 2);

    PCMSK0 |= (1 << 0);
    PCICR |= (1 << 0);

    sei();
    while(true){
        PORTD ^= (1 << 2);
        _delay_ms(1000);
    }
    return 0;
}

ISR(PCINT0_vect){
    cli();
    // PORTB ^= 1 << 5; // can be a toggle instead of if condition
    if(PINB & (1 << 0)){
        PORTB |= (1 << 5);
    }
    else{
        PORTB &= ~(1 << 5);
    }
    sei();
}