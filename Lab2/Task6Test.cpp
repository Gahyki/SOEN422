#include <stdio.h>
#include "Task6.hpp"

int main(void){
	FILE* fp = fopen("Task6Output.txt", "w"); // File output
	QueueS queue(fp);

	fprintf(fp, "Test Queue C++ class\n");
	fprintf(fp, "The queue has the elements: [ 5 10 15 20 ]\t"
           "The queue has the elements: [ 15 20 ]\t"
           "The queue is not empty.\t"
           "The queue is empty.\t\n"); // Expected output

	// Add test
	queue.Add(5);
	queue.Add(10);
	queue.Add(15);
	queue.Add(20);
	queue.Print();

	// Remove test
	queue.Remove();
	queue.Remove();
	queue.Print();

	// IsEmpty test
	queue.IsEmpty();
	queue.Remove();
	queue.Remove();
	queue.IsEmpty();
	queue.~QueueS();

	fclose(fp); // Close file output

	return 0;
}