// General tree representation for UNION/FIND
#ifndef PARPTRTREE_H_
#define PARPTRTREE_H_
#define	ROOT -1

class ParPtrTree
{
private:
	int* array;				// Node array
	int size;				// Size of node array
	int FIND(int)const;		// Find root
	int FIND_PATH_COMPRESSION(int)const;	// FIND with path compression
public:
	ParPtrTree(int);		// Constructor
	~ParPtrTree()			// Destructor
	{
		delete[]array;
	}
	void UNION(int, int);	// Merge equivalences
	bool differ(int, int);	// True if not in same tree
};

int ParPtrTree::FIND(int curr)const	//Find root
{
	while (array[curr]!=ROOT)
	{
		curr = array[curr];
	}
	return curr;
}

inline int ParPtrTree::FIND_PATH_COMPRESSION(int curr) const
{
	if (array[curr] == ROOT)	// At root
		return curr;
	array[curr] = FIND(array[curr]);	// Recursion pointer to the root
	return array[curr];
}

#endif // !PARPTRTREE_H_
