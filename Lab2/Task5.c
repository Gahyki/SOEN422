#include <stdlib.h> // malloc, free
#include <stdio.h>
#include "Task5.h"

#define SIZE 10 // static variable

typedef struct QueueDesc{
    int qp; // Queue pointer
    int items[SIZE]; // Queue list
    FILE* fp;
} QueueDesc, *Queue;

Queue q;

Queue Queue_New(FILE* file){
    Queue q = (Queue) malloc(sizeof(QueueDesc)); // Allocating memory for the queue
    q -> qp = -1; // Default value of queue pointer
    q -> fp = file;
    return q;
}

void Queue_Add(Queue q, int value){
    // incrementing queue pointer so that qp points to the next element and fills it with the input value 
    q -> items[++(q->qp)] = value; 
}

int Queue_Remove(Queue q){
    int value = q -> items[0]; // saving the first element of the queue
    int future_pointer = (q -> qp) - 1; // future queue pointer value

    for(int i = 0; (i+1) <= (q -> qp); i++){
        // take each item in the queue list and shift by one
        q -> items[i] = q -> items[i+1];
    }
    q -> qp = future_pointer; // replace queue pointer value to the new value

    return value;
}

int Queue_IsEmpty(Queue q){
    
    for(int i = 0; i <= (q->qp); i++){
        if(&(q->items[i]) != NULL){ // Check if the current item is null 
            fprintf(q -> fp, "The queue is not empty.\t");
            return 0;
        }
    }
    fprintf(q -> fp, "The queue is empty.\t");
    return 1;
}

void Queue_Delete(Queue q){
    free(q); // Deallocating memory which contains the queue object
}

void Queue_Print(Queue q){
    fprintf(q -> fp, "The queue has the elements: [ ");
    for(int i = 0; i <= (q -> qp); i++){
        fprintf(q -> fp, "%d ", q-> items[i]);
    }
    fprintf(q -> fp, "]\t");
}