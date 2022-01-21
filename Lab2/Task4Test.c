#include <stdio.h>
#include "Task4.h"

void main(void) {

    printf("Test blinking LED as an ADT"); // Test name

    Led led = Led_New(); // setup()
    while (true) { // loop()
        Led_TurnOn(led); // Turn on LED
        Led_TurnOff(led); // Turn off LED
    }
}