#include <stdio.h>
#include <fstream>
#include "Task7.hpp"

int main(void){
	fstream fs;
	fs.open("Task7Output.txt", fstream::out); // File output
	Queue queue(fs);

	fs << "Test Queue C++ class" << endl;
	fs << "The queue has the elements: [ 5 10 15 20 ]\t"
           "The queue has the elements: [ 15 20 ]\t"
           "The queue is not empty.\t"
           "The queue is empty.\t" << endl; // Expected output

	// Push test
	queue.Push(5);
	queue.Push(10);
	queue.Push(15);
	queue.Push(20);
	queue.Print();

	// Remove test
	queue.Pop();
	queue.Pop();
	queue.Print();

	// IsEmpty test
	queue.IsEmpty();
	queue.Pop();
	queue.Pop();
	queue.IsEmpty();

	fs.close();

	return 0;
 }