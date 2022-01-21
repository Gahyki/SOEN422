#include "BargraphHAL.h"

int main(){
    
    uint8_t size = 3;

    Bargraph b = hal_Bargraph_New(size); // setup Bargraph    

    while(true){
        // Valid case for LEDs
        for(int i = 0; i <= hal_Bargraph_GetNumberOfLeds(b); i++){
            hal_Bargraph_Set(b, i); // Enabling the LED
            _delay_ms(500); // Delay for half a second
            hal_Bargraph_Clear(b, i); // Disabling the LED
            _delay_ms(500); // Delay for half a second
        }
    }
    return 0;
}