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

namespace topic12{
	int add(int& left, int& right) { return left + right; }
	double add(double& left, double& right) { return left + right; }

	template<class T>
	T add(const T& left, const T& right)
	{
		return left + right;
	}

	void testTemplates()
	{
		int a = topic12::add(5, 6);//tema12::add<int>(5, 6);
		cout << a << endl;
		double d = topic12::add(4.2, 7.8);// tema12::add<double>(4.2, 7.8);
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


namespace topic13
{
	// Disable the build Error C4996 'strcpy': This function or variable may be unsafe.Consider using strcpy_s instead.
	#pragma warning (disable : 4996)

	class Person
	{
		int age_;
		char* name_;
	public:
		// Default C'tor
		Person();

		// C'tor with params
		Person(const int& age, const char* name)
			: age_(age)
		{
			cout << "calling c'tor for " << name << endl;
			name_ = new char[strlen(name) + 1]; // allocate memory for the string
			strcpy(name_, name); // copy the input string into the object
		}

		// Copy C'tor
		Person(const Person& other)
		{
			cout << "calling copy c'tor for other " << other.name_ << endl;
			name_ = new char[strlen(other.name_) + 1];
			strcpy(name_, other.name_);
			age_ = other.age_;
		}
		
		// Assignment operator
		Person& operator=(const Person& other)
		{
			cout << "calling copy assignment for other " << other.name_ << endl;
			if (this != &other) { // if this is not self-assignment
				delete[] name_;    // clear the existing string
				name_ = nullptr;
				name_ = new char[strlen(other.name_) + 1]; // allocate the required space
				strcpy(name_, other.name_); // copy it
				age_ = other.age_;
			}

			return *this; // return reference to the pointer this of the object
		}

		// D'tor.
		~Person();

	private:
		friend std::ostream& operator<<(std::ostream& os, const Person& person)
		{
			os << person.name_ << " " << person.age_ << endl;
			return os;
		}

	};


	Person::Person()
	{
		cout << "calling defaul c'tor " << endl;
		age_ = 0;
		name_ = nullptr;
	}

	Person::~Person()
	{
		cout << "calling d'tor for other " << name_ << endl;
		if (name_ != nullptr) {
			delete[] name_; // clear the existing string
			name_ = nullptr;
		}
	}

	template<class T>
	class Foo
	{
	public:
		Foo(const T& data) : data_(data){}
		T data() const { return data_; }

	private:
		T data_;
	};

	template<class T>
	std::ostream& operator<<(std::ostream& os, const Foo<T>& f)
	{
		os << f.data() << endl;
		return os;
	}

	template<class T>
	T diff(const T& left, const T& right)
	{
		return left - right;
	}

	void testTemplates()
	{
		Foo<int> a(42);
		Foo<double> b(42.42);
		cout << a << endl;
		cout << b << endl;
		cout << diff<int>(5, 6) << endl;
	}

	void testPerson()
	{
		Person person1(18, "test"); // calls C'tor Person(const int& age, const char* name)
		Person person2(person1);  // calls Copy C'tor
		cout << person1;    // since we predefined operator << we can directly print to the std out our Person object
		cout << person2;

		int age = 5;
		Person* pPerson = new Person(age, "Sneji");
		cout << *pPerson;
		// clear the memory for the person pointer
		delete pPerson;
		pPerson = nullptr;

		Person people[2]; // use default constructor to create the objects
		people[0] = Person(26, "Tony"); // Creates Person using the C'tor Person(const int& age, const char* name). Then uses operator= to assign the created object to people[0]
		cout << people[0];
		people[1] = Person(26, "Stark"); // The same as above but for people[1]
		cout << people[1];

		return; // calls destructor for objects of people, person1 and person2
	}
}

namespace topic14
{
	namespace testingFinalSpec {
		class Base
		{
			virtual void foo();
		};

		class A : Base
		{
			void foo() final; // A::foo() is overriden and its the final override
			//void bar() final; // error: non-virtual function cannot be overriden or be final
		};

		class B final : public A
		{
			//void foo() override; // Error: foo cannot be overriden because A::foo() is the final override
		};

		/*class C : public B// Error: cannot be used as Base class, because B is final
		{

		};*/
	}

	namespace ctorsAndDtors
	{
		class Base
		{
		public:
			Base() { cout << "Base Constructor" << endl; }
			virtual ~Base() { cout << "Base Destructor" << endl; }
		};

		class B
		{
		public:
			B() { cout << "B constructor" << endl; }
			~B() { cout << "B Destructor" << endl; }
		};

		class A : public Base
		{
			B b;
		public:
			A() { cout << "A constructor" << endl; }
			~A() { cout << "A Destructor" << endl; }
		};

		void test()
		{
			A a;
		}
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

	//topic12::testPointers();
	//topic12::testTemplates();
	//topic12::testGlobals();
	//topic12::testGLobals2();
	//topic12::print(3);

	//topic13::testPerson();
	//topic13::testTemplates();

	//topic14::ctorsAndDtors::test();

	return 0;
}