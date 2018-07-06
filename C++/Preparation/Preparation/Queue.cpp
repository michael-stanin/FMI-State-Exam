#include "Queue.h"
#include <iostream>

Queue::Queue()
{ 
	front = rear = -1;
}

Queue::~Queue() = default;

bool Queue::isEmpty() const
{
	return (front == -1 && rear == -1);
}

bool Queue::isFull() const
{
	return (rear + 1) % MAX == front ? true : false;
}

void Queue::enqueue(const int& value)
{
	std::cout << "Enqueueing " << value << std::endl;
	if (isFull()) {
		std::cout << "Queue Overflow" << std::endl;
		return;
	}
	if (isEmpty()) {
		front = rear = 0;
	}
	else {
		rear = (rear + 1) % MAX;
	}

	data[rear] = value;
}

void Queue::dequeue()
{
	std::cout << "Dequeueing" << std::endl;
	if (isEmpty()) {
		std::cout << "Queue Underflow" << std::endl;
		return;
	}
	else if (front == rear) {
		rear = front = -1;
	}
	else {
		front = (front + 1) % MAX;
	}
}

int Queue::Front()
{
	if (front == -1) {
		std::cout << "Emtpy queue" << std::endl;
		return -1;
	}
	return data[front];
}

void Queue::print()
{
	int count = (rear + MAX - front) % MAX + 1;
	std::cout << "Queue      :";
	for (int i = 0; i < count; i++) {
		int index = (front + i) % MAX;
		std::cout << data[index] << " ";
	}
	std::cout << std::endl << std::endl;
}
