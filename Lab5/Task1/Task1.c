// Lab5Task1.c - version with a BSL implementation by polling.
#include <avr/io.h>
#include "bsl_Usart.h" // Share the same interface (polling and interrupts).
#include <stdint.h>
#include <stdbool.h>
volatile char dataReceived;
int main() {
    // ---- Configure the onboard LED.
    DDRB |= (1 << 5);

    // ---- Configure UART by polling
    // No need to disable/enable interrupts

    bsl_Uart_Init();

    while (true) {
        dataReceived = bsl_Uart_RxChar();
        bsl_Uart_TxChar(dataReceived);
        if(dataReceived == 'H'){
            PORTB |= (1 << 5);
        } 
        else if (dataReceived == 'L'){
            PORTB &= ~(1 << 5);
        }
    }
}