#include "bsl_Usart.h" // Share the same interface (polling vs interrupts).

#include <avr/io.h>

#define BaudRate9600 ((uint16_t)(103))

static bool initialized;

//------------------------------------------------------------------------
// Receive a character from UART.
//------------------------------------------------------------------------
char bsl_Uart_RxChar(void) {
    /* Wait for data to be received */
    while ( !(UCSR0A & (1<<RXC0)) );
    /* Get and return received data from buffer */
    return UDR0;
}

//------------------------------------------------------------------------
// Transmit a character to UART.
//------------------------------------------------------------------------
void bsl_Uart_TxChar(char c) {
    // Not required for this task.
    /* Wait for empty transmit buffer */
    while ( !( UCSR0A & (1<<UDRE0)) );
    /* Put data into buffer, sends the data */
    UDR0 = c;
}

//------------------------------------------------------------------------
// Initialize UART for polling.
//------------------------------------------------------------------------
void bsl_Uart_Init(void) {
    if (!initialized) { // To make sure it will be done only once.
        UBRR0 = BaudRate9600;
        /*Set baud rate */
        UBRR0H = (unsigned char)(BaudRate9600>>8);
        UBRR0L = (unsigned char)BaudRate9600;
        /* Enable receiver and transmitter */
        UCSR0B = (1<<RXEN0)|(1<<TXEN0);
        /* Set frame format: 8data, 2stop bit */
        UCSR0C = (1<<USBS0)|(3<<UCSZ00);
        initialized = true;
    }
}
