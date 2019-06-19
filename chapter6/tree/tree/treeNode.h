// General tree node ADT
#ifndef TREENODE_H_
#define TREENODE_H_

template<typename E>
class GTNode
{
public:
	E value();						// Return node's value
	bool isLeaf();					// True if node is a leaf
	GTNode* parent();				// Return parent
	GTNode* leftmostChild();		// Return first child
	GTNode* rightSibling();			// Return right sibling
	void setValue(E&);				// Set node's value
	void insertFirst(GTNode<E>*);	// Insert first child
	void insertNext(GTNode<E>*);	// Insert next sibling
	void removeFirst();				// Remove first child
	void removeNext();				// Remove right child
};

#endif // !TREENODE_H_
