#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
#include "DoubleLinkedList.h"
#include "utilities.h"

using namespace std;



void testStack()
{
	Stack s;
	s.pushBack(10);
	s.pushBack(20);
	s.pushBack(30);
	cout << "Current back " << s.back() << endl;
	cout << "Size before popping " << s.size() << endl;
	cout << s.popBack() << " Popped from stack\n";
	cout << "Size after popping " << s.size() << endl;
	cout << "Current back " << s.back() << endl;
}

void testQueue()
{
	Queue q;
	q.enqueue(2);
	q.print();
	q.enqueue(4);
	q.print();
	q.enqueue(6);
	q.print();
	q.dequeue();
	q.print();
	q.enqueue(8);
	q.print();
}

void testLinkedList()
{
	LinkedList l;
	l.removeFirst();
	l.insertAtEnd(1);
	cout << "size: " << l.size() << endl;
	l.print();
	l.insertAtEnd(2);
	cout << "size: " << l.size() << endl;
	l.print();
	//l.removeLast();
	l.insertAtEnd(3);
	cout << "size: " << l.size() << endl;
	l.print();
	l.insertAtEnd(4);
	cout << "size: " << l.size() << endl;
	l.print();
	cout << "element at index 2: " << l.elementAtIndex(2) << endl;
	cout << "element at index 0: " << l.elementAtIndex(0) << endl;
	cout << "element at index 1: " << l.elementAtIndex(1) << endl;
	
	cout << "Removing at index 0" << endl;
	l.removeAtIndex(0);
	cout << "size: " << l.size() << endl;
	l.print();

	cout << "Reverse the list" << endl;
	l.reverse();
	cout << "size: " << l.size() << endl;
	l.print();

	cout << "Removing at index 1" << endl;
	l.removeAtIndex(1);
	cout << "size: " << l.size() << endl;
	l.print();

	cout << "1 in the list: " << l.find(1) << endl;
	cout << "2 in the list: " << l.find(2) << endl;
	cout << "3 in the list: " << l.find(3) << endl;
	cout << "4 in the list: " << l.find(4) << endl;
}

void testDoubleLinkedList()
{
	DoubleLinkedList dList;
	
	// Test adding to the list
	{
		dList.append(1);
		dList.print();
		dList.append(2);
		dList.print();
		dList.append(3);
		dList.print();
		dList.append(4);
		dList.print();
		dList.append(5);
		dList.print();
		dList.append(6);
		dList.print();
	}

	// Test removing from the list
	{
		dList.removeFirst();
		dList.print();
		dList.removeFirst();
		dList.print();
		dList.removeLast();
		dList.print();
		/*dList.removeLast();
		dList.print();*/
	}

	// Test Inserting at a specific position
	{
		dList.insertAtPos(-1, 10);
		dList.insertAtPos(1231, 11);
		dList.insertAtPos(1, 42);
		dList.print();
	}

	// Test Removing of specific node
	{
		dList.removeNode(42);
		dList.print();
	}

	// Test Reversing of list
	{
		dList.reverse();
		dList.print();
	}
}

void testSorting()
{
	//static const int MAX = 10;
	

	// Bubble sort
	/*{
		int arr[] = {5, 4, 8, 9, 10, 1, 3, 2, 6, 7};
		int arrSize = (sizeof(arr) / sizeof(*arr));
		printArr(arr);

		char chArr[] = { 's', 'n', 'e', 'j', 'i' };
		printArr(chArr);

		bubbleSort(arr, static_cast<int>(customSize(arr)), DigitComparator<int>());
		printArr(arr);

		bubbleSort(chArr, static_cast<int>(customSize(chArr)), CharComparator<char>());
		printArr(chArr);
	}*/

	// Merge sort
	{
		int arr[] = { 5, 4, 8, 9, 10, 1, 3, 2, 6, 7 };
		int arrSize = (sizeof(arr) / sizeof(*arr));
		printArr(arr);

		mergeSort(arr, 0, arrSize - 1);// static_cast<int>(customSize(arr)));
		printArr(arr);
	}
}

int main()
{	
	//testStack();
	//testQueue();
	//testLinkedList();
	//testDoubleLinkedList();
	testSorting();
	return 0;
}