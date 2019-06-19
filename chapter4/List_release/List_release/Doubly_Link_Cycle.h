#include"List.h"

// Singly linked list node
template<typename E>
class Link
{
public:
	E element;			// Value for this node
	Link* next;			// Pointer to next node in list
	Link* prev;			// Pointer to previous node
						// Constructors
	Link(const E& elemval, Link *prevp = nullptr, Link* nextp = nullptr)
	{
		element = elemval;
		next = nextp;
		prev = prevp;
	}

	Link(Link*nextp = nullptr, Link*prevp = nullptr)
	{
		next = nextp;
		prev = prevp;
	}

};

// Linked list implementation
template<typename E>
class DList :public List<E>
{
private:
	Link<E>*head;			// Pointer to list header
	Link<E>*tail;			// Pointer to last element
	Link<E>*curr;			// Pointer to current element
	int cnt;				// Size of list

	void init()				// Intialization helper method
	{
		tail->prev = curr = head = new Link<E>;
		head->next = new Link<E>;
		head->prev = tail;
		tail->next = head;
		cnt = 0;
	}

	void	removeall()		// Return link nodes to free store
	{
		tail->next = nullptr;
		while (head != nullptr)
		{
			curr = head;
			head = head->next;
			delete curr;
		}
	}

public:
	DList(int size = defaultSize)	// Constructor
	{
		init();
	}

	~DList()						// Destructor
	{
		removeall();
	}

	void print()const;				// Print list contents
	void clear()					// Clear list
	{
		removeall();
		init();
	}

	// Insert "it" at current position
	void insert(const E& it)
	{
		curr->next = curr->next->prev = new Link<E>(it, curr, curr->next);
		cnt++;
	}

	// Append "it" to the end of the list
	void append(const E& it)		// Append "it" to list
	{
		tail->prev = tail->prev->next = new Link<E>(it, tail->prev, tail);
		tail->next = head;
		cnt++;
	}

	// Remove and return current element
	E remove()
	{
		if (curr->next == tail)				// Nothing to remove
			return nullptr;
		E it = curr->next->element;			// Remember value
		Link<E>* ltemp = curr->next;		// Remember link node
		curr->next->next->prev = curr;
		curr->next = curr->next->next;		// Remove from list
		delete ltemp;						// Reclaim sapce
		cnt--;								// Decrement cnt
		return it;
	}

	void moveToStart()		// Place curr at list strat
	{
		curr = head;
	}

	void moveToEnd()		// Place curr at list end
	{
		curr = tail;
	}

	// Move fence one step left; no change if left is empty
	void prev()
	{
		if (curr != head)			// Can't back up from list head
			curr = curr->prev;
	}

	// Move curr one step right; no change if already at end
	void next()
	{
		if (curr == tail)
		{
			curr = curr->next;
			curr = curr->next;
		}
		else
			curr = curr->next;
	}

	int length()const
	{
		return cnt;		// Return length
	}

	// Return the position of the current element
	int currPos()const
	{
		Link<E>*temp = head;
		int i;
		for (i = 0; curr != temp; i++)
			temp = temp->next;
		return i;
	}

	// Move down list to "pos" position
	void moveToPos(int pos)
	{
		Assert((pos >= 0) && (pos <= cnt), "Position out of range.");
		curr = head;
		for (int i = 0; i < pos; i++)
			curr = curr->next;
	}

	const E& getValue()const		// Return current element
	{
		Assert(curr->next != nullptr, "No value.");
		return curr->next->element;
	}
};