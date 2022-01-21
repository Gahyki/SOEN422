#include <stdio.h>
#include "Task5.h"

void main(void) {
    FILE *fp;
    fp = fopen("Task5Output.txt", "w");

    fprintf(fp, "Test Queue implemented as an ADT\n");
    fprintf(fp, "The queue has the elements: [ 5 10 15 20 ]\t"
           "The queue has the elements: [ 10 15 20 ]\t"
           "The queue is not empty.\t"
           "The queue is empty.\t\n"); // Expected output

    Queue q = Queue_New(fp); // setup()

    // Add test
    Queue_Add(q, 5);
    Queue_Add(q, 10);
    Queue_Add(q, 15);
    Queue_Add(q, 20);
    Queue_Print(q);

    // Remove test
    Queue_Remove(q);
    Queue_Print(q);

    // IsEmpty when queue is not empty
    Queue_IsEmpty(q); 

    // IsEmpty when queue is empty
    Queue_Remove(q);
    Queue_Remove(q);
    Queue_Remove(q);
    Queue_IsEmpty(q);

    // Destructor
    Queue_Delete(q);

    fclose(fp);
}