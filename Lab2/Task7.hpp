#include <iostream>
using namespace std;

class Queue {
    private:
        std::ostream &stream;
        int qp;
        int *items;

    public:
        // Constructor Destructor
        Queue(std::ostream &output = std::cout);
        ~Queue();

        // Methods
        void Init();
        void Push(int item);
        int Pop();
        bool IsEmpty();
        void Print();
};