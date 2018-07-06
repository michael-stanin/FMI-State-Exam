#pragma once

class Stack
{
public:
	Stack();
	~Stack();

	bool pushBack(const int& value);
	int popBack();
	int size() const;
	bool isEmpty() const;
	int back() const;


private:
	static const int MAX = 1000;

	int top;
	int data[MAX];
};
