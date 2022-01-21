#ifndef __hal_BargraphHAL_h
#define __hal_BargraphHAL_h

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BargraphBSL.h"

struct BargraphDesc; // Forward reference
typedef struct BargraphDesc* Bargraph; // Opaque type

Bargraph hal_Bargraph_New(uint8_t numberOfLeds); // Constructor method
void hal_Bargraph_Set(Bargraph _this, uint8_t ledID); // Setter method
void hal_Bargraph_Clear(Bargraph _this, uint8_t ledID); // Clear method
uint8_t hal_Bargraph_GetNumberOfLeds(Bargraph _this); // Getter method
void hal_Bargraph_Delete(Bargraph _this); // Destructor method

#endif /* __hal_LedAdt_h */
