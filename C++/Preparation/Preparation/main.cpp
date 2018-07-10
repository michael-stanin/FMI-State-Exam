#include <iostream>
#include "BinaryTree.h"
#include "DoubleLinkedList.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
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

	cout << "Make the list circular." << endl;
	l.makeCircular();

	cout << "Is it circular: " << ((l.isCircular()) ? "yes " : "no ") << endl;

	cout << "Make it normal again." << endl;
	l.removeCircularity();
	
	cout << "Is it circular: " << ((l.isCircular()) ? "yes " : "no ") << endl;
	l.print();

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

	// Test Removing of specific Node
	{
		dList.removeNode(42);
		dList.print();
	}

	// Test Reversing of list
	{
		dList.reverse();
		dList.print();
	}

	// Test circularity
	{
		cout << "Make the list circular." << endl;
		dList.makeCircular();

		cout << "Is it circular: " << ((dList.isCircular()) ? "yes " : "no ") << endl;

		cout << "Make it normal again." << endl;
		dList.removeCircularity();
		
		cout << "Is it circular: " << ((dList.isCircular()) ? "yes " : "no ") << endl;
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

void testBinaryTree()
{
	BinaryTree *tree = new BinaryTree();

	tree->insert(10);
	tree->insert(6);
	tree->insert(14);
	tree->insert(5);
	tree->insert(8);
	tree->insert(11);
	tree->insert(18);

	tree->preorder_print();
	tree->inorder_print();
	tree->postorder_print();

	delete tree;
	tree = nullptr;
}

namespace tema12{
	int add(int& left, int& right) { return left + right; }
	double add(double& left, double& right) { return left + right; }

	template<class T>
	T add(const T& left, const T& right)
	{
		return left + right;
	}

	void testTemplates()
	{
		int a = tema12::add(5, 6);//tema12::add<int>(5, 6);
		cout << a << endl;
		double d = tema12::add(4.2, 7.8);// tema12::add<double>(4.2, 7.8);
		cout << d << endl;
	}

	void testParams(const int& constIntRef, int* pInt, double myDouble, int defInt = 42)
	{
		//constIntRef++;

		pInt++;
		int mint = *pInt;
		pInt = nullptr;

		myDouble -= 0.42;

		cout << defInt << endl;
	}

	void testPointers()
	{
		/*
		{
		int a = 5;
		int* p = &a;
		cout << p << endl;
		(*p)++;
		cout << a << endl;

		p++;
		cout << p << endl;
		a += 2;
		p--;
		cout << *p << endl;
		}
		*/

		/*
		{
		int arr[] = { 1, 2 ,3 };
		int* parr = arr;
		cout << ++(*(++parr)) << endl;
		parr = arr;
		for (int i = 0; i < 3; i++) {
		cout << *(parr+i) << endl;
		}
		}
		*/

		
		{
			int arr[2][3] = { {1, 2 ,3}, {4, 5, 6} };
			int (*parr)[2][3] = &arr;
			int* pparr0 = *parr[0];
			for (int j = 0; j < 3; j++) {
				cout << (*pparr0+j) << endl;
			}
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 3; j++) {
					cout << (*parr)[i][j] << endl;
				}
			}
		}
		

	}

	int myInt = 42;
	void testGlobals()
	{
		cout << myInt << endl;
		
		myInt += 7;
		cout << myInt << endl;

		int myInt = 7;
		cout << myInt << endl;
	}

	void testGLobals2()
	{
		cout << myInt << endl;
	}

	void print(int test)
	{
		if (test < 1) {
			return;
		}
		cout << test << endl;
		print(test - 1);
		return;
	}
}


int main()
{	
	//testStack();
	//testQueue();
	//testLinkedList();
	//testDoubleLinkedList();
	//testSorting();
	//testBinaryTree();

	//tema12::testPointers();
	//tema12::testTemplates();
	//tema12::testGlobals();
	//tema12::testGLobals2();
	//tema12::print(3);

	return 0;
}