#include "hal_Interrupt.h"   // HAL Interrupt Management  (Ref. Lab 3 - Task 1)
#include "hal_MM.h"          // HAL Memory Management     (Ref. Lab 3 - Task 4)
#include "hal_COut.h"        // HAL Console Output (PutS) (Ref. Project - Task 3) 
#include "CircQAds.h"        // ADS Circular Queue        (Ref. to this question Part A)

volatile char dataReceived;

volatile bool receivedCircQueueOverflow = false;
volatile bool receivedCircQueueReady = false;

int main(){
    cli();

    hal_MM_Init();
    hal_COut_Init();
    CircQ queue = CircQ_Init();
    memoryBufferFromHalMM = hal_MM_GetSegment(memoryBufferMax);
    hal_COut_PutS("Test Command line from host using UART received ISR\n");
    uint8_t address = 0;

    sei();
    while (true) {
        if(receivedCircQueueOverflow){
            while(!CircQ_IsEmpty()){
                CircQ_Remove();
            }
            PutS("Too long command line. \n");
        } else {
            if(receivedCircQueueReady){
                while(!CircQ_IsEmpty()){
                    memoryBufferFromHalMM[address++] = CircQ_Remove();
                }
                receivedCircQueueReady = false;
            }
        }
        Dump_Memory(memoryBufferFromHalMM, memoryBufferMax);
    }
}
ISR(USART_RX_vect) 
{
    cli();
    
    dataReceived = UDR0;
    if(CircQ_IsFull()){
        receivedCircQueueOverflow = true;
    } else {
        if (dataReceived == '\n'){
            receivedCircQueueReady = true;
        }
        CircQ_Add(dataReceived);
    }

    sei();
}