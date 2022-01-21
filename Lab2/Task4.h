#ifndef LedAdt_h
#define LedAdt_h
#include <stdbool.h>

struct LedDesc; // Forward ref
typedef struct LedDesc* Led; // Opaque type

Led Led_New(void); // Constructor
void Led_TurnOff(Led self); // Turn off LED
void Led_TurnOn(Led self); // Turn on LED
void Led_Delete(Led self); // Destructor

#endif /* LedAdt_h */