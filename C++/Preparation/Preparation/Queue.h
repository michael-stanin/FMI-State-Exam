#pragma once


class Queue
{
public:
	Queue();
	~Queue();

	bool isEmpty() const;
	bool isFull() const;
	void enqueue(const int& value);
	void dequeue();
	int Front();
	void print();

private:
	static const int MAX = 1000;

	int front, rear;
	int data[MAX];
};
