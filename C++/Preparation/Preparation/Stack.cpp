#include "Stack.h"
#include <iostream>

Stack::Stack()
{ 
	top = -1;
}
Stack::~Stack() = default;

bool Stack::pushBack(const int& value)
{
	bool rc = top < (MAX - 1);
	if (rc) {
		data[++top] = value;
	}
	else {
		std::cout << "Stack Overflow";
	}

	return rc;
}

int Stack::popBack()
{
	int x = 0;
	if (top >= 0) {
		x = data[top--];
	}
	else {
		std::cout << "Stack Underflow";
	}
	return x;
}

int Stack::size() const
{
	return top + 1;
}

bool Stack::isEmpty() const
{
	return (top < 0);
}

int Stack::back() const
{
	if (top > 0) {
		return data[top];
	}
	else {
		std::cout << "Stack Underflow";
		return 0;
	}
}
