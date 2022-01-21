#include "ADT.h"

typedef struct ObjectDesc{
    // Attributes

} ObjectDesc, *Object; // Opaque type

Object o;

Object Object_New(){
    // Constructor method
    Object o = (Object) malloc(sizeof(ObjectDesc)); // Allocate memory
    return o;
}



void Object_Delete(Object _this){
    // Destructor method
    free(_this);
}