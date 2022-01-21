#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdbool.h>
#define BaudRate9600 ((uint16_t)(103))
volatile char dataReceived;

int main() {
    cli();

    DDRB |= (1 << 5);

    UBRR0 = BaudRate9600;
    
    // Enable receiver and enable receiver interrupt
    UCSR0B |= (1<<RXEN0)|(1<<RXCIE0);
    // 8 bit character size
    UCSR0C |= (1<<UCSZ00)|(1<<UCSZ01);

    sei();
    while (true) {
        if(dataReceived == '1'){
            PORTB |= (1 << 5);
        } 
        else if (dataReceived == '0'){
            PORTB &= ~(1 << 5);
        }
    }
}

ISR(USART_RX_vect) {
    cli(); // Disable interrupt
    dataReceived = UDR0;
    sei(); // Enable interrupt
}