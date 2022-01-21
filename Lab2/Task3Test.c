#include "Task3.h"


void main() {

    printf("Test blinking LED as an ADS");

    Led_Init(); // setup()

    while (true) { // loop()
        Led_TurnOn(); // Turn on LED
        Led_TurnOff(); // Turn off LED
    }
}
