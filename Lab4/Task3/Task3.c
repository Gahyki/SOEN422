#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

volatile uint16_t v_counter = 0; // Volatile counter

int main(){
    // Onboard LED
    DDRB |= (1 << 5); // digital pin 13
    // Turn on onboard LED
    PORTB |= (1 << 5);

    // Timer/Counter control register -> turn on CTC mode
    TCCR0A |= (1 << 1);

    // TCCR0B -> prescaler selected here
    TCCR0B |= (1 << 2); // 256 (from prescaler)

    // OCR0A for the CTC
    // 16MHz / 256 = 62 500 Hz
    // 62 500 * 0.004 seconds = 250
    // 250 - 1;
    OCR0A = 249;

    // Enable timer compare interrupt
    TIMSK0 |= (1 << 1); // Compare match A

    sei();
    while(true){

    }
    return 0;
}

ISR(TIMER0_COMPA_vect){
    cli();
    if(v_counter == 125){ // 0.5 / 0.004 = 125 -> after 125 iterations
        // Toggle onboard LED
        PORTB ^= (1 << 5);
        v_counter = 0; // Resets the v_counter        
    }
    v_counter++;
    sei();
}
