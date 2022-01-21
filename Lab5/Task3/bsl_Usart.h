#ifndef __bsl_Usart_h
#define __bsl_Usart_h
// Note: These #includes are inappropriate and should be moved/hidden
// in the implementation. HAL or Users should not know if
// the Uart is used by polling or by interrupts.
// #include <avr/io.h>
// #include <avr/interrupt.h>
#include <stdint.h>
#include <stdbool.h>
// Note: All the configuration details are moved/hidden in this version.
// #define BaudRate9600 ((uint16_t)(103))
void bsl_Uart_Init(void);
char bsl_Uart_RxChar(void);
void bsl_Uart_TxChar(char c);
#endif
