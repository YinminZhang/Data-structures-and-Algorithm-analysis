#include"queue_ADT.h"
using std::endl;
using std::cout;
using std::string;

// Array-based queue implementation
template<typename E>
class AQueue :public Queue<E>
{
private:
	int maxSize;				// Maximum size of queue
	int front;					// Index of front element
	int rear;					// Index of rear element
	E*listArray;				// Array holding queue elements
public:
	// Constructor
	AQueue(int size = defaultSize)
	{
		// Make list array one position larger for empty slot
		maxSize = size + 1;
		rear = 0;
		front = 1;
		listArray = new E[maxSize];
	}

	// Destructor
	~AQueue()
	{
		delete[]listArray;
	}

	// Reinitialize
	void clear()
	{
		rear = 0;
		front = 1;
	}

	// Put "it" in queue
	void enqueue(const E& it)
	{
		if ((rear + 2) % maxSize == front)
		{
			cout << "Queue is full." << endl;
			return NULL;
		}
		rear = (rear + 1) % maxSize;		// Circular increment
		listArray[rear] = it;
	}

	// Take element out
	E dequeue()
	{
		if (length() == 0)
		{
			cout << "Queue is empty." << endl;
			return NULL;
		}
		E it = listArray[front];
		front = (front + 1) % maxSize;	// Circular increment
		return it;
	}

	// Get front value
	const E& frontValue()const
	{
		if (length() == 0)
		{
			cout << "Queue is empty." << endl;
			return NULL;
		}
		return listArray[front];
	}

	// Return length
	virtual int length()const
	{
		return ((rear + maxSize) - front + 1) % maxSize;		// initial value rear=0, front=1
	}
};