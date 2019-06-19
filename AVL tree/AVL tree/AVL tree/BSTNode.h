// Simple binary tree node implementation
#ifndef BTNODE_H_
#define BTNODE_H_
#include"binary_tree_node.h"

template<typename Key, typename E>
class BSTNode :public BinNode<E>
{
private:
	Key k;				// The node's key
	E it;				// The node's value
	int height;			// The node's height
	BSTNode*lc;			// Pointer to left child
	BSTNode*rc;			// Pointer to right child
public:
	// Two constructors -- with and without initial values
	BSTNode() { lc = rc = nullptr; }
	BSTNode(Key K, E e, BSTNode*l = nullptr, BSTNode*r = nullptr) :k(K), it(e), lc(l), rc(r) {}

	// Destructor
	~BSTNode(){}

	// Fuctions to set and return the value and key
	E& element() { return it; }
	void setElement(const E&e) { it = e; }
	Key& key() { return k; }
	void setKey(const Key&K) { k = K; }

	// Fucntions to set and return the children
	inline BSTNode* left()const { return lc; }
	void setLeft(BinNode<E>*b) { lc = (BSTNode*)b; }
	inline BSTNode* right()const { return rc; }
	void setRight(BinNode<E>*b) { rc = (BSTNode*)b; }

	// Return true if it is a leaf, false otherwise
	bool isLeaf() { return (lc == nullptr) && (rc = nullptr); }

	// The max height of subtree
	int maxheight()const
	{
		return lc->height > rc->height ? lc->height : rc->height;
	}

	// 
};

#endif // !BTNODE_H_