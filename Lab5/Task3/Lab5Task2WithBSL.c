#include <avr/io.h>
#include <avr/interrupt.h> // For disable/enable interrupts.
#include "bsl_Usart.h" // Share the same interface (polling vs interrupts).
#include <stdint.h>
#include <stdbool.h>
int main() {
    // ---- Configure the onboard LED.
    // ---- Configure UART by interrupts
    
    cli();
    DDRB |= (1 << 5);
    bsl_Uart_Init();
    sei();
    while (true) {
        char dataReceived = bsl_Uart_RxChar();
        if(dataReceived == '1'){
            PORTB |= (1 << 5);
        } 
        else if (dataReceived == '0'){
            PORTB &= ~(1 << 5);
        }
    }
}
