#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include "BinaryTree.h"
#include "DoubleLinkedList.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "utilities.h"
#include <string>
#include <queue>

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

namespace July2017
{
	namespace task1 {
		bool badTerrain(char** terrain, int i, int j, int m, int n)
		{
			int numberOfAdjacent4s = 0;

			if ((i - 1 > 0 && j - 1 > 0) && terrain[i - 1][j - 1] == '4') {
				numberOfAdjacent4s += 1;
			}
			if ((i - 1 > 0) && terrain[i - 1][j] == '4') {
				numberOfAdjacent4s += 1;
			}
			if ((i - 1 > 0 && j + 1 < n) && terrain[i - 1][j + 1] == '4') {
				numberOfAdjacent4s += 1;
			}
			if ((j - 1 > 0) && terrain[i][j - 1] == '4') {
				numberOfAdjacent4s += 1;
			}
			if ((j + 1 < n) && terrain[i][j + 1] == '4') {
				numberOfAdjacent4s += 1;
			}
			if ((i + 1 < m && j - 1 > 0) && terrain[i + 1][j - 1] == '4') {
				numberOfAdjacent4s += 1;
			}
			if ((i + 1 < m) && terrain[i + 1][j] == '4') {
				numberOfAdjacent4s += 1;
			}
			if ((i + 1 < m && j + 1 < n) && terrain[i + 1][j + 1] == '4') {
				numberOfAdjacent4s += 1;
			}

			return numberOfAdjacent4s >= 3;
		}

		void evolveTerrain(char** terrain, int m, int n)
		{
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					char c = terrain[i][j];
					int nc = (int)c;
					switch (c)
					{
					case 'R':
					case 'S':
						break;
					case '1':
					case '2':
					case '3':
						nc++;
						break;
					case '4':
						if (badTerrain(terrain, i, j, m, n)) {
							nc--;
						}
					default:
						break;
					}
					terrain[i][j] = (char)nc;
				}
			}
		}

		void simulate(char** terrain, int m, int n, int years)
		{
			cout << "Initial environment:" << endl;
			printMatrix(terrain, m, n);
			cout << endl;

			while (years / 10) {
				cout << "Environment after 10 years: " << endl;
				evolveTerrain(terrain, m, n);
				printMatrix(terrain, m, n);
				cout << endl;
				years -= 10;
			}
		}

		void initTerrain(char** terrain, int m, int n)
		{
			terrain[0][0] = 'R';
			terrain[0][1] = 'R';
			terrain[0][2] = '1';
			terrain[0][3] = '1';
			terrain[0][4] = '2';
			terrain[0][5] = '2';

			terrain[1][0] = '1';
			terrain[1][1] = 'R';
			terrain[1][2] = 'R';
			terrain[1][3] = 'R';
			terrain[1][4] = '1';
			terrain[1][5] = '2';

			terrain[2][0] = 'S';
			terrain[2][1] = '1';
			terrain[2][2] = 'R';
			terrain[2][3] = 'R';
			terrain[2][4] = '2';
			terrain[2][5] = '3';

			terrain[3][0] = '4';
			terrain[3][1] = '4';
			terrain[3][2] = 'S';
			terrain[3][3] = 'S';
			terrain[3][4] = 'R';
			terrain[3][5] = 'R';

			// TODO comment out the above and uncomment below when needs be testing.
			/*char c;
			for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
			cout << "Enter terrain value for [" << i << "][" << j << "]: ";
			cin >> c;
			terrain[i][j] = c;
			}
			}*/
		}

		void testTask1()
		{
			const int N = 100;
			const int M = 100;
			// TODO comment out the above and uncomment below when needs be testing.
			/*int M, N;
			cin >> M;
			cin >> N;*/
			char** terrain;
			terrain = new char*[M];
			for (int i = 0; i < M; i++) {
				terrain[i] = new char[N];
			}

			initTerrain(terrain, M, N);

			//simulate(terrain, M, N, 100);
			simulate(terrain, 4, 6, 100);

			for (int i = 0; i < M; i++) {
				delete[] terrain[i];
			}

			delete[] terrain;
		}
	}
	
	namespace task2 {
		
		// VERY Sloppy but does the work
		void sortList(LinkedList& list)
		{
			// Allocate memory and copy the values from the list into an array
			const int listSize = list.size();
			int* arr = new int[listSize];
			for (int i = 0; i < listSize; i++) {
				arr[i] = list.elementAtIndex(i);
			}

			printPArr<int>(arr, listSize);

			// Sort the array
			mergeSort(arr, 0, listSize-1);
			
			cout << "Sorted array: " << endl;
			printPArr<int>(arr, listSize);

			// Clear the list before adding the sorted elements
			list.clear();

			// Copy the sorted values
			for (int i = 0; i < listSize; i++) {
				list.insertAtEnd(arr[i]);
			}

			delete[] arr;
		}

		void testTask2()
		{
			LinkedList list;
			list.insertAtEnd(3);
			list.insertAtEnd(1);
			list.insertAtEnd(5);
			list.insertAtEnd(2);
			sortList(list);
			
			cout << "Sorted list: " << endl;
			list.print();
		}
	}
}

namespace July2016
{
	namespace task1
	{
		void testTask1()
		{
			// It is basically like July 2017 task 1, but instead of checking all of the values of the "adjacent" elements of a[i][j]
			// We need to check the elements in the symmetric group of a[i][j] and change its value to their average...
		}
	}

	namespace task2
	{
		struct Tree {
			Tree(int _data = 0) : data(_data) {}

			int data;
			std::vector<July2016::task2::Tree> subtrees;
		};

		Tree parseTree(std::istream& is) {
			char c;
			Tree t;
			//   '('  <digit>   '('  ')'? '('
			is >> c >> t.data >> c >> c;
			if (c == '(')
				is.putback(c);
			while (c == '(' || c == ',') {
				// there are more descendants
				//t.subtrees.push_back(parseTree(is));
				t.subtrees.push_back(parseTree(is));
				is >> c;
			}
			is >> c;
			return t;
		}

		Tree readTree(std::string fileName) {
			std::ifstream fi(fileName);
			return parseTree(fi);
		}

		int maxSum(Tree t) {
			if (t.subtrees.empty())
				return t.data;
			int m = maxSum(t.subtrees[0]);
			for (Tree st : t.subtrees)
				m = std::max(m, maxSum(st));
			return t.data + m;
		}

		void testTask2()
		{
			std::cout << maxSum(readTree("July2016SampleTree.txt")) << '\n';
		}
	}
}

namespace September2016
{
	namespace task1
	{
		/*
		Задача 1 . Задачата да се реши с използване на език за процедурно или обектно-ориентирано
		програмиране (C, C++ или Java).
		Да се състави функция, която приема като параметър низ с произволна дължина и връща като
		резултат позициите на двойката еднакви символи, които са максимално отдалечени един от друг.
		Ако в низа съществуват няколко двойки максимално отдалечени символи, функцията да връща
		позициите на най-ляво разположената двойка. Счита се, че номерата на позициите започват от 0.
		Пример:
		В символния низ "this is just a simple example" най-ляво и най-дясно разположените
		символи ‘ ‘ (интервали) , са на позиции съответно 4 и 21, намират се на разстояние 17 символа един
		от друг и няма друга двойка еднакви символи, които са на по-голямо разстояние един от друг.
		*/


		void solve(char* testString, int strSize, int& start, int& end)
		{
			if (testString == nullptr) {
				return;
			}

			int max = 0;
			char* pString = testString;
			for (int i = 0; i < strSize; i++) {
				char currentChar = testString[i];
				for (int j = i + 1; j < strSize; j++) {
					if (currentChar == pString[j]) {
						if ((j - i) > max) {
							start = i;
							end = j;
							max = ((j - i) > max) ? (j - i) : max;
						}
					}
				}
			}
		}

		void testTask1()
		{
			char* testString = "this is just a simple example";
			static const int strSize = 29;
			int start = 0;
			int end = 0;
			solve(testString, strSize, start, end);
			if (start != end) {
				cout << "The start and end position of the pair of the same symbols: " << start << " : " << end << endl;
				cout << "Length is: " << end - start << endl;
			}
			else {
				cout << "There are no pairs of symbols in the given string." << endl;
			}
		}
	}
	
	namespace task2
	{
		/*
		Задача 2.Задачата да се реши с използване на език за процедурно или обектно - ориентирано
			програмиране(C, C++ или Java).
			Да се напише функция, която получава като параметри цяло число K и едномерен масив A с елементи
			различни цели числа.Функцията трябва да построи в паметта дърво T, съдържащо данните в масива
			A, като дървото T трябва да удовлетворява следните условия :
		1. Всеки елемент на A се среща като възел в T точно веднъж.
			2. Всеки възел в T има най - много K преки наследници(деца).
			3. T е с възможно най - малка дълбочина.
			4. Ако i < j, то A[i] да не се намира по - дълбоко от A[j] в T(т.е.да е на същата или по - малка
				дълбочина).
			Като резултат функцията да връща построеното дърво и да извежда на стандартния изход неговата
			дълбочина.Конкретното представяне на дървото в паметта е по Ваш избор.
			Пример: За A = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } и K = 3, минималната дълбочина е 3
		*/
		
		struct Node
		{
			Node(const int& data) : data_(data) {}
			Node() = default;
			int data_;
			vector<Node*> children_;
		};

		Node* buildTree(int arr[],int k, int n)
		{
			if (n < 1) {
				return nullptr;
			}

			Node* root = new Node(*arr);
			arr++;
			n--;

			queue<Node*> queue;
			queue.push(root);

			while (!queue.empty() && n > 0) {
				Node* current = queue.front();
				queue.pop();
				cout << "Current element is: " << current->data_ << endl;

				int childIndex = 0;
				while (childIndex < k && (n-- > 0)) {
					Node* child = new Node(*arr);

					current->children_.push_back(child);
					queue.push(child);

					cout << "Adding child to: " << current->data_ << " with value: " << *arr << endl;

					arr++;
					childIndex++;
				}
			}

			return root;
		}
		
		void dummyPrintTree(Node* root)
		{
			cout << std::to_string(root->data_) << " ";
			for (auto child : root->children_) {
				dummyPrintTree(child);
			}
		}

		int calculateDepth(Node* root)
		{
			if (root->children_.empty())
				return 1;
			int m = calculateDepth(root->children_[0]);
			for (auto child : root->children_)
				m = std::max(m, calculateDepth(child));
			return 1 + m;
		}

		int solution(int k, int* arr, int size)
		{
			//cout << endl;
			printPArr(arr, size);
			Node* root = buildTree(arr, k, size);

			dummyPrintTree(root);
			cout << endl;

			int depth = calculateDepth(root);
			return depth;
		}

		void testTask2()
		{
			int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
			int k = 3;
			int size = 14;
			cout << "The three is with depth: " << solution(k, arr, size) << endl;
		}
	}
}

namespace September2015
{
	namespace task1
	{
		namespace A
		{
			/*
			A) Следните програмни фрагменти са съответно от булева функция на C++ и статичен булев
			метод на Java, проверяващи дали в даден масив a от цели числа, подредени в нарастващ ред, се
			съдържа числото x . Функцията/методът прилагат алгоритъма за двоично търсене. Липсващите
			части от фрагментите са обозначени с ______. Попълнете липсващите части така, че функцията
			или съответно методът да са коректно дефинирани спрямо това описание.
			*/

			bool member(int x, int arr[], int size)
			{
				if (size == 0)
					return false;
				int mid = size / 2;
				int midElement = arr[mid];
				bool isMember = (midElement) == x ||
					(midElement < x && member(x, (arr + (mid + 1)), mid)) ||
					(member(x, arr, mid));
				return isMember;
			}

			void testA()
			{
				int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
				int size = 14;

				// Positive tests
				vector<int> positiveTests = { 1, 14, 7, 8, 9, 6, 3, 11 };
				for (auto& positiveTest : positiveTests)
					cout << "Is " << positiveTest << " member of the array: " << (member(positiveTest, arr, 14) ? "yes" : "no") << endl;

				// Negative tests
				vector<int> negativeTests = { 0, 42};
				for (auto& negativeTest : negativeTests)
					cout << "Is " << negativeTest << " member of the array: " << (member(negativeTest, arr, 14) ? "yes" : "no") << endl;
			}
		}

		namespace B
		{
			/*
			Нека е дефиниран масив nums , в който се съдържат N целочислени стойности.
			Попълнете празните полета, за да бъде коректна програмната реализация на алгоритъма за
			сортиране във възходящ ред чрез пряка селекция (selection sort).
			*/

			void selectionSort(int arr[], int n)
			{
				for (int i = 0; i < n; ++i) {
					
					// Find the index of the minimum element
					int min = i;					
					for (int j = i + 1; j < n; j++) {
						if (arr[j] < arr[min])
							min = j;
					}

					// Swap when required
					if (min != i) {
						int x = arr[i];
						arr[i] = arr[min];
						arr[min] = x;
					}
				}
			}

			void testInput(int arr[], int size)
			{
				cout << "Before: ";
				printPArr(arr, size);

				// Selection Sort it
				selectionSort(arr, size);

				cout << "After:  ";
				printPArr(arr, size);
			}

			void testB()
			{
				int arr1[] = { 3, 5, 4, 1, 7, 10, 9, 2, 6, 8 };
				int size1 = 10;
				testInput(arr1, size1);
				cout << endl;

				int arr2[] = { 3, 7, 10, 9, 2, 6, 8 };
				int size2 = 7;
				testInput(arr2, size2);
				cout << endl;

				int arr3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
				int size3 = 10;
				testInput(arr3, size3);
				cout << endl;

				int arr4[] = { 11, 3, 5, 4, 14, 13, 1, 7, 10, 9, 12, 2, 6, 8, 15 };
				int size4 = 15;
				testInput(arr4, size4);
				cout << endl;

				int arr5[] = { 3 };
				int size5 = 1;
				testInput(arr5, size5);
				cout << endl;

				int arr6[] = { 5, 3 };
				int size6 = 2;
				testInput(arr6, size6);
				cout << endl;
			}
		}

		namespace C
		{
			/*
			Каква ще бъде стойността на променливата result след изпълнение на следния програмен
			фрагмент
			*/
			void testC()
			{
				int a = 0; int b = 15; int result = 1;
				if (b < 10 && b / a < 10)
					result = 0;
				else
					result = 1;
				cout << result << endl;
			}
		}

		namespace D
		{
			/*
			Каква е стойността на израза 6 | 11
			*/

			void testD()
			{
				int i = 6 | 11;
				bool b = bool(6 | 11);
				cout << i << endl;
				cout << b << endl;
			}
		}
	}
	
	namespace task2
	{
		/*
		Следната задача да се реши на един от езиците за програмиране C++ или
		Java. Да се обозначи явно на кой от двата езика е решавана задачата. При решението на
		задачата да не се използват библиотеки за работа със структури от данни.
		а) Да се дефинира подходяща структура от данни, позволяваща представянето в паметта на
		програмата на ориентиран граф от типа G=<V,E> , където V е множеството на целите
		положителни числа, не поголеми
		от 1000 (представено чрез типа данни int) , а E=V×V .
		б) За така дефинираната структура от данни да се дефинира функция (или статичен метод)
		[булев тип] isConnected ([подходящ тип] g)
		чиято стойност е истина точно за тези графи g , които са свързани. За един граф G=<V,Е>
		казваме, че е свързан, ако за всяка двойка u∈V, v∈V има път от u до v или от v до u . На
		примера са показани два графа, първият от които е свързан, а вторият – не.
		*/

		class Graph
		{
			int numberOfVerticies;

			int** adjacents;

		public:
			Graph(int n) : numberOfVerticies(n)
			{
				adjacents = new int* [numberOfVerticies];
				for (int i = 0; i < numberOfVerticies; ++i)
					adjacents[i] = new int[numberOfVerticies];

				for (int i = 0; i < numberOfVerticies; ++i)
					for (int j = 0; j < numberOfVerticies; ++j)
						adjacents[i][j] = 0;
			}

			void addEdge(int v, int w)
			{
				adjacents[v - 1][w - 1] = 1;
			}

			bool isConnected()
			{
				printMatrix(adjacents, numberOfVerticies, numberOfVerticies);

				int i = 0, j = 1;
				if (!adjacents[i][j] && adjacents[j][i]) {// If not connected, check the other way around
					i = 1;
					j = 0;
				}
				bool isGraphConnected = true;
				while (isGraphConnected && i < numberOfVerticies && j < numberOfVerticies) {
					isGraphConnected = adjacents[i][j];
					i++;
					j++;
				}

				return isGraphConnected;
			}
		};

		void testGraph1()
		{
			Graph g(3);
			g.addEdge(3, 2);
			g.addEdge(2, 1);
			cout << "Graph is: " << (g.isConnected() ? "connected" : "not connected") << endl;
		}

		void testGraph2()
		{
			Graph g(3);
			g.addEdge(2, 1);
			g.addEdge(2, 3);
			cout << "Graph is: " << (g.isConnected() ? "connected" : "not connected") << endl;
		}
		
		void testGraph3()
		{
			Graph g(3);
			g.addEdge(1, 2);
			g.addEdge(2, 3);
			cout << "Graph is: " << (g.isConnected() ? "connected" : "not connected") << endl;
		}

		void testTask2()
		{
			testGraph1();
			testGraph2();
			testGraph3();
		}
	}

}

namespace July2015
{
	namespace task1
	{
		/*
		Дадена е floatматрица imgс размери М ≤ 10реда и N ≤ 10стълба. Напишете функция
		subsample, която получава като аргументи M , N и i mg и извежда на екрана матрица s с размери
		(М+1)/2 и ( N+1)/2 ( при целочислено деление), всеки елемент s [i][j] на която е равен на
		средноаритметичното
		от всички елементи img[y][x] , такива че
		i*2 ≤ y ≤ i*2+1 и j*2 ≤ x ≤ j*2+1 .
		Например, при матрица img , представена таблично по следния начин:
		1.0 2.0 3.0
		4.5 6.5 7.5
		функцията да извежда на екрана:
		3.5 5.25
		*/
		float calculateOutputValue(int i, int j, float** source, int m, int n)
		{
			int lowYBound = i * 2;
			int highYBound = i * 2 + 1;

			int lowXBound = j * 2;
			int highXBound = j * 2 + 1;

			float total = 0;
			int occurrences = 0;
			for (int sourceJ = lowYBound; sourceJ <= highYBound && sourceJ < m; ++sourceJ) {
				for (int sourceI = lowXBound; sourceI <= highXBound && sourceI < n; ++sourceI) {
					total += source[sourceJ][sourceI];
					occurrences++;
				}
			}

			return (float)total / occurrences;
		}

		void convertMatrix(float** source, int m, int n, float** dest, int k, int l)
		{
			for (int i = 0; i < k; ++i) {
				for (int j = 0; j < l; ++j) {
					float value = calculateOutputValue(i, j, source, m, n);
					dest[i][j] = value;
				}
			}
		}

		void testTask1()
		{
			float** img = new float*[2];
			for (int i = 0; i < 2; ++i) {
				img[i] = new float[3];
			}

			img[0][0] = 1.0;
			img[0][1] = 2.0;
			img[0][2] = 3.0;
			img[1][0] = 4.5;
			img[1][1] = 6.5;
			img[1][2] = 7.5;

			cout << "Input matrix: " << endl;
			printMatrix(img, 2, 3);

			cout << endl;
			float** s = new float*[1];
			for (int i = 0; i < 1; ++i) {
				s[i] = new float[2];
			}

			convertMatrix(img, 2, 3, s, 1, 2);


			cout << "Output matrix: " << endl;
			printMatrix(s, 1, 2);
		}
	}

	namespace task2
	{
		/*
		Да се обозначи явно на кой от двата езика е решавана задачата. При решението на задачата да не
		се използват библиотеки за работа със структури от данни.
		а) Да се дефинира подходяща индуктивна (рекурсивна) структура от данни, позволяваща
		представянето в паметта на програмата на възел на дърво от цели числа ( int ), за което всеки връх
		може да има произволен брой наследници (0, 1 или повече).
		б) Да се дефинира рекурсивна функция (или статичен метод)
		[булев тип] member ([подходящ тип]root, int x)
		чиято стойност е истина точно тогава, когато в дървото с корен, представен от параметъра root ,
		съществува възел със стойност x .
		в) Да се дефинира рекурсивна функция (или статичен метод)
		void filterOdd ([подходящ тип] root)
		Функцията да премахва (чрез мутация) всяко поддърво t’ на дървото с корен, представен от
		параметъра root , за което е изпълнено, че коренът на t’ е със стойност нечетно число. На
		следната фигура е показано примерно дърво преди и след изпъпнението на операцията
		filterOdd .
		*/

		struct Node
		{
			Node(const int& data) : data_(data) {}

			int data_;
			vector<Node*> children;
		};

		Node* buildSimpleTree()
		{
			Node* root = new Node(8);
			root->children.emplace_back(new Node(2));
			root->children.emplace_back(new Node(3));
			root->children.emplace_back(new Node(12));

			root->children[1]->children.emplace_back(new Node(4));
			root->children[1]->children.emplace_back(new Node(5));
			root->children[1]->children.emplace_back(new Node(6));

			root->children[1]->children[1]->children.emplace_back(new Node(7));

			return root;
		}

		Node* member(Node* root, int x)
		{
			if (root->data_ == x)
				return root;
			Node* element = nullptr;
			for (auto& child : root->children) {
				element = member(child, x);
				if (element) {
					break;
				}
			}
			return element;
		}

		void freeNode(Node* node)
		{
			delete node;
			node = nullptr;
		}

		void filterOdd(Node* root)
		{
			if (root->data_ % 2)
				freeNode(root);
			for (auto& child : root->children)
				filterOdd(child);
		}

		void testTask2()
		{
			Node* root = buildSimpleTree();
			
			vector<int> positiveTests = { 8, 2, 5, 3, 4, 12 };
			for (auto& positiveTest : positiveTests) 
				cout << "Is " << positiveTest << " element of the tree: " << (member(root, positiveTest) ? "yes" : "no") << endl;

			vector<int> negativeTests = { 7, 42, 1 };
			for (auto& negativeTest : negativeTests)
				cout << "Is " << negativeTest << " element of the tree: " << (member(root, negativeTest) ? "yes" : "no") << endl;

			filterOdd(root);

			for (auto& positiveTest : positiveTests)
				cout << "Is " << positiveTest << " element of the tree: " << (member(root, positiveTest) ? "yes" : "no") << endl;
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
	
	//July2017::task1::testTask1();
	//July2017::task2::testTask2();
	
	//July2016::task1::testTask1();
	//July2016::task2::testTask2();

	//September2016::task1::testTask1();
	//September2016::task2::testTask2();

	//September2015::task1::A::testA();
	//September2015::task1::B::testB();
	//September2015::task1::C::testC();
	//September2015::task1::D::testD();
	//September2015::task2::testTask2();

	//July2015::task1::testTask1();
	July2015::task2::testTask2();

	return 0;
}