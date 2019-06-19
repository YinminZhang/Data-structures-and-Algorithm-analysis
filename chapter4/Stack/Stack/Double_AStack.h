#include"Stack.h"
#define defaultSize 10

// Array-based stack implementation
template<typename E>
class AStack
{
private:
	int maxSize;				// Maximum size of stack
	int top1;					// Index for top1 element
	int top2;					// Index for top2 element
	E* listArray;				// Array hoding stack elements

public:
	AStack(int size = defaultSize)	// Constructor
	{
		maxSize = size;
		top1 = 0;
		top2 = maxSize - 1;
		listArray = new E[size];
	}

	~AStack()						// Destructor
	{
		delete[] listArray;
	}

	void clear1()					// Reinitialize top1
	{
		top1 = 0;
	}

	void clear2()					// Reintialize top2
	{
		top2 = maxSize - 1;
	}

	void push1(const E& it)			// Put "it" on stack
	{
		Assert(top1 != top2, "Stack is full.");
		listArray[top1++] = it;
	}

	void push2(const E& it)			// Put "it" on stack
	{
		Assert(top2 != top1, "Stack is full.");
		listArray[top2--] = it;
	}

	E pop1()							// Pop "it" on stack
	{
		Assert(top1 != 0, "Stack is empty.");
		return listArray[--top1];
	}

	E pop2()							// Pop "it" on stack
	{
		Assert(top1 != 0, "Stack is empty.");
		return listArray[top2++];
	}

	const E& top1Value()const		// Return top1 element
	{
		Assert(top1 != 0, "Stack is empty.");
		return listArray[top1 - 1];
	}

	const E& top2Value()const		// Return top2 element
	{
		Assert(top2 != maxSize - 1, "Stack is empty.");
		return listArray[top2+1];
	}

	int length1()const				// Return length of the stack1
	{
		return top1;
	}

	int length2()const				// Return length of the stack2
	{
		return maxSize - top2 - 1;
	}
};