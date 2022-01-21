#ifndef __hal_Interrupt_h
#define __hal_Interrupt_h

#include <stdint.h>
#include "bsl_Interrupt.h"

void hal_Interrupt_Disable(void); // Disable Interrupt
void hal_Interrupt_Enable(void); // Enable Interrupt
uint32_t hal_Interrupt_SaveAndDisable(void); // Save current state then disable interrupt
void hal_Interrupt_Restore(uint32_t flags); // Restore the state that was saved

#endif // __hal_Interrupt_h