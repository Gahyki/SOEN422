#include "Task7.hpp"

Queue::Queue(std::ostream &output):stream(output){
    items = new int [10];
    Init();
}

Queue::~Queue(){
    delete[] items; // Deallocate the memory attributed to the items
}

void Queue::Init(){
    qp = -1; // Queue pointer with initial value
}

void Queue::Push(int item){
    items[++qp] = item; // Adding new item to queue list
}

int Queue::Pop(){
    int value = items[0]; // Value of the first item of the queue list
    int future_pointer = qp - 1; // Value of queue pointer to be changed into

    for(int i = 0; (i+1) <= qp; i++){
        items[i] = items[i+1]; // Shift value of each element in the list
    }
    qp = future_pointer; // Replace the value of the queue pointer to the new value

    return value;
}

bool Queue::IsEmpty(){
    for(int i = 0; i <= qp; i++){
        if(&(items[i]) != nullptr){ // Check if the current element of the list is null
            stream << "The queue is not empty.\t";
            return false;
        }
    }
    stream << "The queue is empty.\t";
    return true;
}

void Queue::Print(){
    stream << "The queue has the elements: [ ";
    for(int i = 0; i <= qp; i++){
        stream << items[i] << " ";
    }
    stream << "]\t  ";
}