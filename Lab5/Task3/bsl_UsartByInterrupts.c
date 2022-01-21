#include "bsl_Usart.h" // Share the same interface (polling vs interrupts).

#include <avr/io.h>
#include <avr/interrupt.h>

#define BaudRate9600 ((uint16_t)(103))

volatile char dataReceived;
static bool initialized;

//------------------------------------------------------------------------
// Receive a character from UART.
//------------------------------------------------------------------------
char bsl_Uart_RxChar(void) {
    return dataReceived;
}

//------------------------------------------------------------------------
// Transmit a character to UART.
//------------------------------------------------------------------------
void bsl_Uart_TxChar(char c) {
    // Not required for this task.
}

//------------------------------------------------------------------------
// Initialize UART for received interrupts.
//------------------------------------------------------------------------
void bsl_Uart_Init(void) {
    if (!initialized) { // To make sure it will be done only once.
        UBRR0 = BaudRate9600;
    
        // Enable receiver and enable receiver interrupt
        UCSR0B |= (1<<RXEN0)|(1<<RXCIE0)|(1<<TXEN0);
        // 8 bit character size
        UCSR0C |= (1<<UCSZ00)|(1<<UCSZ01);

        initialized = true;
    }
}

ISR(USART_RX_vect) {
    cli(); // Disable interrupt
    dataReceived = UDR0;
    sei(); // Enable interrupt
}
