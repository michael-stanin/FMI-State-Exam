#pragma once

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void clear();
	void insertAtStart(const int& value);
	void insertAtEnd(const int& value);
	int elementAtIndex(const int& index);
	bool removeFirst();
	bool removeLast();
	bool removeAtIndex(const int& index);
	void print() const;
	int size() const;
	// Answers whether a value is in the list
	bool find(const int& value) const;
	void reverse();
	void makeCircular();
	bool isCircular();
	void removeCircularity();

private:

	struct Node
	{
		Node() : data(0), next(nullptr) {}
		Node(const int& value, Node* pNode = nullptr) : data(value), next(pNode) {}

		int data;
		Node* next;
	};

	Node* nodeAtIndex(const int& index);

	Node* head = nullptr;
	Node* tail = nullptr;
};