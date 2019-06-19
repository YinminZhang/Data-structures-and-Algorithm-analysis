// Heap class
#ifndef HEAP_H_
#define HEAP_H_
#include<iostream>
using std::endl;
using std::cout;

template<typename E, typename Comp>
class heap
{
private:
	E* Heap;				// Pointer to the heap array
	int maxsize;			// Maximum size of the heap
	int n;					// Number of elements now in the heap

	// Halper function to put element in its correct place
	void siftdown(int pos)
	{
		while (!isLeaf(pos))		// Stop if pos is a leaf
		{
			int j = leftchild(pos);
			int rc = rightchild(pos);
			if ((rc < n) && Comp::prior(Heap[rc], Heap[j]))
				j = rc;				// Set j to greater child's value
			if (Comp::prior(Heap[pos], Heap[j]))
				return;				// Done
			swap(Heap, pos, j);
			pos = j;				// Move down
		}
	}

public:
	// Constructor
	heap(E* h, int num, int max)
	{
		Heap = h;
		n = num;
		maxsize = max;
		buildHeap();
	}

	// Return current heap size
	int size()const { return n; }

	// True if pos is a leaf
	bool isLeaf(int pos)const { return (pos >= n / 2) && (pos < n); }

	// Return leftchild position
	int leftchild(int pos)const { return 2 * pos + 1; }

	// Return rightchild position
	int rightchild(int pos)const { return 2 * pos + 2; }

	// Return parent position
	int parent(int pos)const { return(pos - 1) / 2; }

	// Heapify contents of Heap
	void buildHeap()
	{
		for (int i = n / 2 - 1; i >= 0; i--)
			siftdown(i);
	}

	// Insert "it" into the heap
	void insert(const E& it)
	{
		if (n >= maxsize)
		{
			cout << "Heap is full." << endl;
			return;
		}
		int curr = n++;
		Heap[curr] = it;			// Start at end of heap
		// Now sift up until curr's parent > curr
		while ((curr != 0) && (Comp::prior(Heap[curr], Heap[parent(curr)])))
		{
			swap(Heap, curr, parent(curr));
			curr = parent(curr);
		}
	}

	// Remove first value
	E removefirst()
	{
		if (n <= 0)
		{
			cout << "Heap is empty." << endl;
			return NULL;
		}
		swap(Heap, 0, --n);				// Swap first with last value
		if (n != 0)
			siftdown(0);				// Siftdown new root val
		return Heap[n];					// Return deleted value
	}

	// Remove and return element at specified position
	E remove(int pos)
	{
		if ((pos < 0) || (pos >= n))	// Assert
		{
			cout << "Bad position." << endl;
			return NULL;
		}

		if (pos == (n - 1))				// Last element, no work to do
			n--;
		else
		{
			swap(Heap, pos, --n);		// Swap with last value
			while ((pos!=0)&&(Comp::prior(Heap[pos],Heap[parent(pos)])))
			{
				swap(Heap, pos, paren(pos));		// Push up large key
				pos = parent(pos);
			}
			if (n != 0)
				siftdown(pos);			// Push down small key
		}
		return Heap[n];
	}
};

#endif // !HEAP_H_
