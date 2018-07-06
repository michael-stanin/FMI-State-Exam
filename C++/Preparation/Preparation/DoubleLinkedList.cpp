#include "DoubleLinkedList.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList() = default;
DoubleLinkedList::~DoubleLinkedList()
{
	clear();
}

void DoubleLinkedList::clear()
{
	Node* current = head;
	while (head != nullptr) {
		head = head->next;
		delete current;
		current = nullptr;
	}
}

void DoubleLinkedList::removeFirst()
{
	if (head != nullptr) {
		Node* current = head;
		head = head->next;
		head->prev = nullptr;
		delete current;
		current = nullptr;
	}
}

void DoubleLinkedList::removeLast()
{
	if (head != nullptr) {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		Node* lastToBe = current->prev;
		lastToBe->next = nullptr;
		current->prev = nullptr;
		delete current;
		current = nullptr;
	}
}

void DoubleLinkedList::removeNode(const int& value)
{
	if (head != nullptr) {
		Node* current = head;
		if (current->data == value) {
			head = head->next;
			head->prev = nullptr;

			// Remove the node
			delete current;
			current = nullptr;
			return;
		}

		// Find the node to be removed
		bool nodeFound = false;
		while (current->next != nullptr && !nodeFound) {
			current = current->next;
			nodeFound = (current->data == value);
		}

		// If node is found, current will be the one we need to remove
		if (nodeFound) {
			Node* nextNode = current->next;
			Node* prevNode = current->prev;

			// Make the prevNode's next node to be the node after the one we remove
			prevNode->next = nextNode;

			// Make the nextNode's prev node to be the node before the one we remove
			nextNode->prev = prevNode;

			// Remove the node
			delete current;
			current = nullptr;
		}
	}
}

void DoubleLinkedList::push(const int& value)
{
	// 1. Allocate new node
	Node* newNode = new Node;

	// 2. Fill it in
	newNode->data = value;

	putNodeAsFirst(newNode);

	/*
	if (head == nullptr) {
	head = newNode;
	return;
	}
	*/
}

void DoubleLinkedList::append(const int& value)
{
	// 1. Allocate new node
	Node* newNode = new Node;

	// 2. Fill it in
	newNode->data = value;

	putNodeAsLast(newNode);
}

void DoubleLinkedList::insertAtPos(const int& pos, const int& value)
{
	// 0. We shouldn't add nodes outside our range - do nothing
	if (pos > size() || pos < 0) {
		return;
	}

	// 1. Allocate new node
	Node* newNode = new Node;

	// 2. Fill it in
	newNode->data = value;

	// 3. Place the node at its position
	if (pos == 0) {
		putNodeAsFirst(newNode);
	}
	else if (pos == size()) {
		putNodeAsLast(newNode);
	}
	else {

		// Move to the desired position
		int currPos = 1;
		Node* rightNeighbor = head->next;
		while (currPos++ != pos && rightNeighbor->next != nullptr) {
			rightNeighbor = rightNeighbor->next;
		}

		// Make the prev of new node as prev of the right neighbor node
		newNode->prev = rightNeighbor->prev;

		// Make the prev of right neighbor node as new node
		rightNeighbor->prev = newNode;

		// Make right neighbor node the next of new node
		newNode->next = rightNeighbor;

		// Change next of new node's prev node
		if (newNode->prev != nullptr) {
			newNode->prev->next = newNode;
		}
	}

}

DoubleLinkedList::Node* DoubleLinkedList::findNode(const int& value)
{
	Node* current = head;
	while (current != nullptr) {
		if (current->data == value) {
			return current;
		}
		current = current->next;
	}
}

int DoubleLinkedList::size() const
{
	Node* current = head;
	int mySize = 0;
	while (current != nullptr) {
		mySize++;
		current = current->next;
	}

	return mySize;
}

void DoubleLinkedList::reverse()
{
	// If we have 0 or 1 elements, nothing to reverse
	if (head == nullptr || head->next == nullptr) {
		return;
	}

	Node* temp = nullptr;
	Node* current = head;

	while (current != nullptr) {
		// Store the previous node
		temp = current->prev;

		// Reverse the pointers
		current->prev = current->next;
		current->next = temp;
		
		// Move right on the list
		current = current->prev;
	}

	if (temp != nullptr) {
		head = temp->prev;
	}
}

/*void DoubleLinkedList::add(const int& value)
{
	Node* newNode = new Node;
	newNode->data = value;
	if (head == nullptr) {
		head = newNode;
		return;
	}
	Node* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;

	temp = nullptr;
}*/

void DoubleLinkedList::print() const
{
	Node* temp = head;
	while (temp != nullptr) {
		std::cout << temp->data << ", ";
		temp = temp->next;
	}
	std::cout << std::endl;

	temp = nullptr;
}

void DoubleLinkedList::putNodeAsFirst(Node* node)
{
	// 3. Make sure next points to the head and previous to nullptr
	node->next = head;
	node->prev = nullptr;

	// 4. Change previous of head to the new node
	if (head != nullptr) {
		head->prev = node;
	}

	// 5. Move the head to point to the new node
	head = node;
}

void DoubleLinkedList::putNodeAsLast(Node* node)
{
	// 3. This is going to be the last node, so its next should be null
	node->next = nullptr;

	// 4. If the Linked List is empty, then make the new node as head
	if (head == nullptr) {
		node->prev = nullptr;
		head = node;
		return;
	}

	// 5. Else Traverse until the last node
	Node* last = head;
	while (last->next != nullptr) {
		last = last->next;
	}

	// 6. Change the next of the last node
	last->next = node;

	// 7. Make last node as previous of new node.
	node->prev = last;
}
