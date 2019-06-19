#include"Stack.h"
#include"Link.h"
#define defaultSize 10

// Linked stack implementation
template<typename E>
class LStack :public Stack<E>
{
private:
	Link<E>* top;		// Pointer to first element
	int size;			// Number of elements
public:
	LStack(int sz = defaultSize)	// Constructor
	{
		top = nullptr;
		size = 0;
	}

	~LStack()						// Destructor
	{
		clear();
	}
	
	void clear()					// Reinitialize
	{
		while (top!=nullptr)		// Delete link nodes
		{
			Link<E>* temp = top;
			top = top->next;
			delete temp;
		}
		size = 0;
	}

	void push(const E& it)			// Put "it" on stack
	{
		top = new Link<E>(it, top);
		size++;
	}

	E pop()							// Remove "it" from stack
	{
		if (top == nullptr)
		{
			cout << "Stack is empty." << endl;
			return NULL;
		}
		E it = top->element;
		Link<E>* ltemp = top->next;
		delete top;
		top = ltemp;
		size--;
		return it;
	}

	const E& topValue()const		// Return top value
	{
		if (top == 0)
		{
			cout << "Stack is empty." << endl;
			return NULL;
		}
		return top->element;
	}

	int length()const				// Return length
	{
		return size;
	}
};