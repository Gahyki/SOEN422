#ifndef TASK6_HPP
#define TASK6_HPP
#include "Task5.h" // Queue ADT


class QueueS {
public:
    QueueS(FILE* fp) { q = Queue_New(fp); } // Constructor
    ~QueueS() { Queue_Delete(q); } // Destructor

    void Add(int value) { Queue_Add(q, value); } // Method to add new element
    int Remove() { return Queue_Remove(q); } // Method to remove first element
    int IsEmpty() { return Queue_IsEmpty(q); } // Method to check if queue list is empty

    void Print() { return Queue_Print(q); }

private:
    Queue q;
};

#endif // TASK6_HPP