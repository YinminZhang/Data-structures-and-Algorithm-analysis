#include"List.h"
#include<iostream>
#include<string>
#define defaultSize 0
using std::cout;
using std::string;
using std::endl;

template<typename E>	// Array-based list implementation
class  AList :public List<E>
{
private:
	int maxSize;	// Maximum size of list
	int listSize;	// Number of list items now
	int curr;		// Position of current element
	E* listArray;	// Array hoding list elements
public:
	AList(int size = defaultSize);	// Constructor

	~AList();					// Destructor

	void clear();				// Reinitialize the list
	
	// Insert "it" at current position
	void insert(const E& it);

	void append(const E& it);	// Append "it"

	// Remove and return the current element.
	E remove();

	void moveToStart();			// Reset position
	void moveToEnd();			// Set at end
	void prev();				// Back up
	void next();				// Next

	// Return list size
	int length()const;

	// Return current position
	int currPos()const;

	// Set current list position to "Pos"
	void moveToPos(int pos);

	const E&getValue()const;	// Return current element

	/*void swap();*/
};

void Assert(bool log, string str)
{
	if (!log)
		cout << str << endl;
}

template<typename E>
inline AList<E>::AList(int size)
{
	maxSize = size;
	listSize = curr = 0;
	listArray = new E[maxSize];
}

template<typename E>
inline AList<E>::~AList()
{
	delete[]listArray;
}

template<typename E>
inline void AList<E>::clear()
{
	delete[]listArray;			// Remove the array
	listSize = curr = 0;		// Reset the size
	listArray = new E[maxSize];	// Recreate array
}

template<typename E>
inline void AList<E>::insert(const E & it)
{
	Assert(listSize < maxSize, "List capacity exceeded.\n");
	for (int i = listSize; i > curr; i--)	// Shift elements up
		listArray[i] = listArray[i - 1];	// to make room
	listArray[curr] = it;
	listSize++;								// Increment list size
}

template<typename E>
inline void AList<E>::append(const E & it)
{
	Assert(listSize < maxSize, "List capacity exceeded.\n");
	listArray[listSize++] = it;
}

template<typename E>
inline E AList<E>::remove()
{
	Assert((curr >= 0) && (curr < listSize), "NO element");
	E it = listArray[curr];						// Copy the element
	for (int i = curr; i < listSize - 1; i++)	// shift them down
	{
		listArray[i] = listArray[i + 1];
	}
	listSize--;
	return it;
}

template<typename E>
inline void AList<E>::moveToStart()
{
	curr = 0;
}

template<typename E>
inline void AList<E>::moveToEnd()
{
	curr = listSize;
}

template<typename E>
inline void AList<E>::prev()
{
	if (curr != 0)
		curr--;
}

template<typename E>
inline void AList<E>::next()
{
	if (curr < listSize)
		curr++;
}

template<typename E>
inline int AList<E>::length() const
{
	return listSize;
}

template<typename E>
inline int AList<E>::currPos() const
{
	return curr;
}

template<typename E>
inline void AList<E>::moveToPos(int pos)
{
	Assert((pos >= 0) && (pos <= listSize), "Position out of range");
	curr = pos;
}

template<typename E>
inline const E & AList<E>::getValue() const
{
	Assert((curr >= 0) && (curr < listSize), "No current element");
	return listArray[curr];
}
