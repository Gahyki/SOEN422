#ifndef __ADT_h
#define __ADT_h

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

struct ObjectDesc; // Forward reference
typedef struct ObjectDesc* Object; // Opaque type

Object Object_New(); // Constructor method
void Object_Set(Object _this, uint8_t value); // Setter method
void Object_Clear(Object _this, uint8_t value); // Clear method
uint8_t Object_Get(Object _this); // Getter method
void Object_Delete(Object _this); // Destructor method

#endif /* __hal_LedAdt_h */
