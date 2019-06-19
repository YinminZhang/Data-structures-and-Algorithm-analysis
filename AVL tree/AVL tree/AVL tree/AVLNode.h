// AVL tree node
#ifndef AVLTREENODE_H_
#define AVLTREENODE_H_

template<typename E>
class AVLTreeNode
{
private:
	AVLTreeNode<E>* lc;		// Pointer to left child
	AVLTreeNode<E>* rc;		// Pointer to right child
	E value;				// The node's value

	// Function
	int height(AVLTreeNode<E>* rt);		// Get node's height
	int hgt;							// The node's height
public:
	// Constructor
	AVLTreeNode()
	{
		rc = lc = nullptr;
	}
	AVLTreeNode(const E& val, AVLTreeNode<E>* r = nullptr, AVLTreeNode<E>* l = nullptr)
	{
		value = val;
		rc = r;
		lc = l;
	}
	// Destructor
	~AVLTreeNode()
	{

	}

	// Return the value
	E getValue()const
	{
		return value;
	}
	// Set the value
	void setValue(E& val)
	{
		value = val;
		return;
	}
	void setValue(E val)
	{
		value = val;
	}
	// Return the children
	AVLTreeNode* left()const
	{
		return lc;
	}
	AVLTreeNode* right()const
	{
		return rc;
	}
	// Set the children
	void setLeft(AVLTreeNode<E>* l)
	{
		lc = (AVLTreeNode<E>*)l;
	}
	void setRight(AVLTreeNode<E>* r)
	{
		rc = (AVLTreeNode<E>*)r;
	}
	// Return true if it is a leaf, false otherwise.
	bool isLeaf()const
	{
		if (rc == lc == nullptr)
			return true;
		else
			return false;
	}
	// Return the height
	int getHeight()const
	{
		return hgt;
	}
	// Set the height
	void setHeight(int Height)
	{
		hgt = Height;
		return;
	}
	void setHeight()
	{
		int a = height(lc), b = height(rc);
		hgt = (a > b) ? (a + 1) : (b + 1);
	}
	// Get node's balance factor
	int balance_factor(AVLTreeNode<E>* rt)const
	{
		if (rt != nullptr)
			return height(rt->left()) - height(rt->right());
		return 0;
	}
	int balance_factor()
	{
		if (this != nullptr)
			return height(lc) - height(rc);
		return 0;
	}
};

#endif // !AVLTREENODE_H_

template<typename E>
inline int AVLTreeNode<E>::height(AVLTreeNode<E>*rt)
{
	if (rt == nullptr)
		return 0;
	else
	{
		int a = height(rt->left()), b = height(rt->right());
		rt->setHeight((a > b) ? (a + 1) : (b + 1));
		return rt->getHeight();
	}
}
