#include "LinkedList.h"
#include "Stack.h"
#include <iostream>

LinkedList::LinkedList() = default;

LinkedList::~LinkedList()
{
	clear();
}

void LinkedList::clear()
{
	if (head == nullptr) {
		return;
	}

	Node* curr = head;
	while (head != nullptr)
	{
		head = head->next;
		delete curr;
		curr = head;
	}

	head = nullptr;
	tail = nullptr;
}

void LinkedList::insertAtStart(const int& value)
{
	Node* newNode = new Node(value);
	newNode->next = head;
	head = newNode;
	if (head->next == nullptr) {
		tail = newNode;
	}
}

void LinkedList::insertAtEnd(const int& value)
{
	Node* newNode = new Node(value);
	if (tail == nullptr) {
		newNode->next = tail;
		tail = newNode;
		head = newNode;
		return;
	}
	tail->next = newNode;
	tail = tail->next;
}

int LinkedList::elementAtIndex(const int& index)
{
	return nodeAtIndex(index)->data;
}

bool LinkedList::removeFirst()
{
	if (head != nullptr) {
		Node* temp = head;
		head = head->next;
		if (head == nullptr) {
			tail = head;
		}

		delete temp;
		temp = nullptr;

		return true;
	}
	return false;
}

bool LinkedList::removeLast()
{
	if (tail != nullptr) {
		Node* current = head;
		if (current == tail) {
			delete current;
			head = nullptr;
			tail = nullptr;

			return true;
		}

		Node* previous = head;
		while (current->next != nullptr) {
			previous = current;
			current = current->next;
		}
		previous->next = nullptr;
		tail = previous;

		delete current;
		current = nullptr;

		return true;
	}

	return false;
}

bool LinkedList::removeAtIndex(const int& index)
{
	if (index == 0) {
		return removeFirst();
	}
	else if (index < (size() - 1)) {
		Node* current = head;
		Node* previous = head;
		for (int i = 0; i < index; i++) {
			previous = current;
			current = current->next;
		}

		previous->next = current->next;
		delete current;
		current = nullptr;

		return true;
	}
	else {
		return removeLast();
	}
	return false;
}

void LinkedList::print() const
{
	Node* temp = head;
	while (temp != nullptr) {
		std::cout << temp->data << ", ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

int LinkedList::size() const
{
	Node* curr = head;
	int mySize = 0;
	while (curr != nullptr) {
		mySize++;
		curr = curr->next;
	}

	return mySize;
}

// Answers whether a value is in the list
bool LinkedList::find(const int& value) const
{
	Node* curr = head;
	while (curr != nullptr) {
		if (curr->data == value) {
			return true;
		}
		curr = curr->next;
	}
	return false;
}

void LinkedList::reverse()
{
	// Empty or just one element - nothing to reverse
	if (head == nullptr || head->next == nullptr) {
		return;
	}

	Node* previous = head;
	Node* current = previous->next;
	Node* next = current->next;

	// Convert head to tail.
	head->next = nullptr;
	tail = head;

	// Reverse pointer direction.
	current->next = head;

	while (next != nullptr) {
		// Reverse diretion
		current->next = previous;

		// Move all pointers to the right
		previous = current;
		current = next;
		next = next->next;
	}

	// Assign the head to the current (last existing element, i.e. the tail from the previous list)
	head = current;

	// Head should point to the pre-last Node
	head->next = previous;

	// Another way of reversing is to use temporary Linked List:
	// 1. Go over each of the current list nodes.
	// 2. For each Node, insert its value at the start of the temporary list
	// 3. In the temporary list we will have the reversed order
	// 4. Use Copy C'tor ...

	/* Using stack
	Stack s;
	if (head != nullptr) {

	// Put all of the values in a stack
	Node* current = head;
	s.pushBack(current->data);
	while (current->next != nullptr) {
	current = current->next;
	s.pushBack(current->data);
	}

	// Clear the current list
	clear();

	// Create the reversed list
	while (!s.isEmpty()) {
	const int& value = s.popBack();
	insertAtEnd(value);
	}
	}
	*/
}

void LinkedList::makeCircular()
{
	if (tail != nullptr) {
		tail->next = head;
	}
}

bool LinkedList::isCircular()
{
	if (tail != nullptr) {
		return (tail->next == head);
	}
	return false;
}

void LinkedList::removeCircularity()
{
	if (isCircular()) {
		tail->next = nullptr;
	}
}



LinkedList::Node* LinkedList::nodeAtIndex(const int& index)
{
	int curr = 0;
	Node* temp = head;
	if (curr == index) {
		return temp;
	}

	while (curr++ != index && temp->next != nullptr) {
		temp = temp->next;
	}
	return temp;
}
