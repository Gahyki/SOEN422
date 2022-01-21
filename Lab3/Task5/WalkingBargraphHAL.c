#include "WalkingBargraphHAL.h"

typedef struct BargraphDesc{
    uint8_t nbLeds;
} BargraphDesc, *Bargraph; // Opaque type

Bargraph b;

Bargraph hal_Bargraph_New(uint8_t numberOfLeds){
    // Constructor method
    uint8_t nb = numberOfLeds-1; // This is due to the array like reference made when referencing the different digital pins
    if((0 <= nb) && (nb < 4)){
        Bargraph b = (Bargraph) malloc(sizeof(BargraphDesc)); // Allocate memory
        b->nbLeds = nb; // Setting the value of the attribute
        LedDirection |= LedOne;
        LedDirection |= LedTwo;
        LedDirection |= LedThree;
        LedDirection |= LedFour;

        return b;    
    }
    return NULL;
}

void hal_Bargraph_Set(Bargraph _this, uint8_t ledID){
    // Setter method
    if((0 <= ledID) && (ledID <= _this->nbLeds)){
        LedRegister |= (1 << ledID);
    }
    
}

void hal_Bargraph_Clear(Bargraph _this, uint8_t ledID){
    // Clear method
    if((0 <= ledID) && (ledID <= _this->nbLeds)){
        LedRegister &= ~(1 << ledID);
    }
}

uint8_t hal_Bargraph_GetNumberOfLeds(Bargraph _this){
    // Getter method
    return _this->nbLeds;
}

void hal_Bargraph_Delete (Bargraph _this){
    // Destructor method
    free(_this);
}

void Walk(Bargraph _this){
    // Walking animation for LEDs
    for(int i = 0; i <= hal_Bargraph_GetNumberOfLeds(_this); i++){
        hal_Bargraph_Set(_this, i); // Enabling the LED
        _delay_ms(333); // Delay for half a second
        hal_Bargraph_Clear(_this, i); // Disabling the LED
    }
    
}

void Flash(Bargraph _this){
    // Flashing LEDs
    for(int i = 0; i <= hal_Bargraph_GetNumberOfLeds(_this); i++){
        hal_Bargraph_Set(_this, i); // Enabling the LED
    }
    _delay_ms(500);
    for(int i = 0; i <= hal_Bargraph_GetNumberOfLeds(_this); i++){
        hal_Bargraph_Clear(_this, i); // Disabling the LED
    }
    _delay_ms(500);
}