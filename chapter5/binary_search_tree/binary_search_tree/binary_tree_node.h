// Binary tree node abstract class
#ifndef BinNode_H_
#define BinNode_H_

template<typename E>
class BinNode
{
public:
	// Base destructor
	virtual ~BinNode() {}

	// Return the node's value
	virtual E& element() = 0;

	// Set the node's value
	virtual void setElement(const E&) = 0;

	// Return the node's left child
	virtual BinNode* left()const = 0;

	// Set the node's left child
	virtual void setLeft(BinNode*) = 0;

	// Return the node's right child
	virtual BinNode* right()const = 0;

	// Set the node's right child
	virtual void setRight(BinNode*) = 0;

	// Return true if the node is a leaf, false otherwise
	virtual bool isLeaf() = 0;
};

#endif // !BinNode_H_
