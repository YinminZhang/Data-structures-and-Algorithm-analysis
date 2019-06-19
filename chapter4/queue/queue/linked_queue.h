#include"queue_ADT.h"

template<typename E>
class Link
{
private:
	E element;			// Value for this node
	Link*next;			// Pointer to next node in list
	// Constructors
	Link(const E& elemval, Link* nextval = nullptr)
	{
		element = elemval;
		next = nextval;
	}
	Link(Link*nextval = nullptr)
	{
		next = nextval;
	}
};

// Linked queue implementation
template<typename E>
class LQueue :public Queue<E>
{
private:
	// No element stored in the front
	// The pointer is the head of the List Queue
	Link<E>*front;				// Pointer to front queue node							
	Link<E>*rear;				// Poniter to queue node
	int size;					// Number of elements in queue
public:
	// Constructor
	LQueue(int sz = defaultSize)
	{
		front = rear = new Link<E>();
		size = 0;
	}

	// Destructor
	~LQueue()
	{
		clear();
		delete front;
	}

	// Clear queue
	void clear()
	{
		// Delete each link node
		while (front->next != nullptr)
		{
			rear = front->next;
			front->next = front->next->next;
			delete = rear;
		}
		rear = front;
		size = 0;
	}

	// Put element on rear
	void enqueue(const E& it)
	{
		rear->next = new Link<E>(it, nullptr);
		rear = rear->next;
		size++;
	}

	// Remove element from front
	E dequeue()
	{
		if (size == 0)
		{
			cout << "Queue is empty." << endl;
			return NULL;
		}
		E it = front->next->element;		// Store dequeued value
		Link<E>*ltemp = front->next;		// Hold dequeue link
		front->next = ltemp->next;			// Dequeue last element
		if (rear == ltemp)					// Delete link
			rear = front;
		delete ltemp;
		size--;
		return it;							// Return element value
	}

	// Get front element
	const E& frontValue()const
	{
		if (size == 0)
		{
			cout << "Queue is empty." << endl;
			return NULL;
		}
		return front->next->element;
	}

	virtual int length()const
	{
		return size;
	}
};