#include"Stack.h"
#define defaultSize 10

// Array-based stack implementation
template<typename E>
class AStack :public Stack<E>
{
private:
	int maxSize;				// Maximum size of stack
	int top;					// Index for top element
	E* listArray;				// Array hoding stack elements

public:
	AStack(int size = defaultSize)	// Constructor
	{
		maxSize = size;
		top = 0;
		listArray = new E[size];
	}

	~AStack()						// Destructor
	{
		delete[] listArray;
	}

	void clear()					// Reinitialize
	{
		top = 0;
	}

	void push(const E& it)			// Put "it" on stack
	{
		Assert(top != maxSize, "Stack is full.");
		listArray[top++] = it;
	}

	E pop()							// Pop "it" on stack
	{
		Assert(top != 0, "Stack is empty.");
		return listArray[--top];
	}

	const E& topValue()const		// Return top element
	{
		Assert(top != 0, "Stack is empty.");
		return listArray[top - 1];
	}

	int length()const				// Return length
	{
		return top;
	}
};