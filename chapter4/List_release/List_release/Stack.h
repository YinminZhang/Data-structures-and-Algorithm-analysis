#include<iostream>
#include<string>
using std::string;
using std::endl;
using std::cout;

// Stack abtract class
template<typename E>
class Stack
{
private:
	void operator=(const Stack&) {}		// Protect assignment
	Stack(const Stack&){}				// Protect copy constructor
public:
	Stack(){}							// Default constructor
	virtual ~Stack() {}					// Base destructor

	// Reinitialize the stack. The user is reponsible for reclaiming the storage use by the stack elements.
	virtual void clear() = 0;

	// Push an element onto the top of the stack.
	// it:The element being pushed onto teh stack.
	virtual void push(const E&it) = 0;

	// Remove the element at the top of the stack.
	// it: The element at the top of the stack.
	virtual E pop() = 0;
	
	// Return : A copy of the top element.
	virtual const E& topValue()const = 0;

	// Return: The number of elements in the stack.
	virtual int length()const = 0;
};

void Assert(bool log, string str)
{
	if (!log)
		cout << str << endl;
}