#ifndef Queue_h
#define Queue_h
#include <stdbool.h>

#ifdef __cplusplus // Had to implement this to make the file compatible for compiling in C++
extern "C"{
#endif

struct QueueDesc; // Forward ref
typedef struct QueueDesc* Queue; // Opaque type

Queue Queue_New(FILE* file); // Constructor
void Queue_Add(Queue q, int value); // Method to add new element (value) to the queue list
int Queue_Remove(Queue q); // Method to remove the first element of the list
int Queue_IsEmpty(Queue q); // Method to check if the queue is empty
void Queue_Delete(Queue q); // Destructor
void Queue_Print(Queue q); // Print method

#ifdef __cplusplus // Had to implement this to make the file compatible for compiling in C++
};
#endif

#endif /* Queue_h */