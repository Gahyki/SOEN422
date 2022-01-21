#include "WalkingBargraphHAL.h"

int main(){

    // Setting the digitalpin12 to input mode
    LedDirection &= ~LedInput;
    LedRegister |= LedInput;

    Bargraph b = hal_Bargraph_New(3); // setup Bargraph    

    while(true){
        // Reading the input status
        int8_t status = (LedPin & LedInput);
        if(!status){
            for(int i = 0; i < 10; i++){ // 333ms * 3 = 1s -> 10 iterations * 1s = 10 s
                Walk(b);
            }
            _delay_ms(333);
            for(int i = 0; i < 5; i++){ // 500ms * 2 = 1s -> 5 iterations * 1s = 5 s
                Flash(b);
            }
        }
    }
    return 0;
}