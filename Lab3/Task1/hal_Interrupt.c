#include "hal_Interrupt.h"

void hal_Interrupt_Disable(void){
    // Disables the interrupt
    Interrupt_Disable;
};

void hal_Interrupt_Enable(void){
    // Enables the interrupt
    Interrupt_Enable;
};

uint32_t hal_Interrupt_SaveAndDisable(void){
    // Saves the register then disables the interrupt
    uint32_t x = SREG;
    hal_Interrupt_Disable();
    return x;
};

void hal_Interrupt_Restore(uint32_t flags){
    // restores the value of saved register to the status register
    SREG = flags;
};