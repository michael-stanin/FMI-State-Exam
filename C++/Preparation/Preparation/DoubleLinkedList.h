#pragma once

class DoubleLinkedList
{
	struct Node
	{
		Node() = default;
		Node(const int& value) : data(value), prev(nullptr), next(nullptr) {}

		int data = 0;
		Node* prev = nullptr;
		Node* next = nullptr;
	};

public:
	DoubleLinkedList();
	~DoubleLinkedList();

	void clear();
	void removeFirst();
	void removeLast();
	void removeNode(const int& value);
	void push(const int& value);
	void append(const int& value);
	void insertAtPos(const int& pos, const int& value);
	Node* findNode(const int& value);
	int size() const;
	void reverse();
	void print() const;

	void makeCircular();
	bool isCircular();
	void removeCircularity();

private:
	void putNodeAsFirst(Node* node);
	void putNodeAsLast(Node* node);

	Node* head = nullptr;

	// TODO: If required 0(1) insertion at the back,
	//       tail to the list should be handled everywhere...
	//Node* tail;
};