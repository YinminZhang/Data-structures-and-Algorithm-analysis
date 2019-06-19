// AVL tree
#ifndef AVLTREE_H_
#define AVLTREE_H_
#include"AVLNode.h"

template<typename E>
class AVLTree
{
private:
	AVLTreeNode<E>* root;		// Root of AVL tree
	// Function
	AVLTreeNode<E>* inserthelp(AVLTreeNode<E>* rt, E& val);		// Insert a node with value
	AVLTreeNode<E>* removehelp(AVLTreeNode<E>* rt, E& val);		// Remove a node with value

	AVLTreeNode<E>* getmax(AVLTreeNode<E>* rt);					// Get pointer to teh max of tree
	AVLTreeNode<E>* getmin(AVLTreeNode<E>* rt);					// Get pointer to the min of tree
	AVLTreeNode<E>* deletemin(AVLTreeNode<E>* rt);				// Delete node with the min of tree

	AVLTreeNode<E>* leftLeftRotation(AVLTreeNode<E>* rt);		// Simple rotation
	AVLTreeNode<E>* rightRightRotation(AVLTreeNode<E>* rt);
	AVLTreeNode<E>* leftRightRotation(AVLTreeNode<E>* rt);		// Double rotation
	AVLTreeNode<E>* rightLeaftRotation(AVLTreeNode<E>* rt);

	void preOrderTraversalhelp(AVLTreeNode<E>* rt)const;		// Traversal
	void inOrderTraversalhelp(AVLTreeNode<E>* rt)const;
	void postOrderTraversalhelp(AVLTreeNode<E>* rt)const;

	void clearhelp(AVLTreeNode<E>* rt);		// Clear

public:
	AVLTree();				// Constructor	
	~AVLTree();				// Desctructor
	void insert(E& val);	// Insert value
	void remove(E& val);	// Remove value
	void clear();			// Clear
	void preOrderTraversal()const;		// Preorder traversal
	void inOrderTraversal()const;		// Inorder traversal
	void postOrderTraversal()const;		// Postorder traversal
	E maxValue()const;					// Max value
	E minValue()const;					// Min value
	
};

#endif // !AVLTREE_H_

template<typename E>
inline AVLTreeNode<E>* AVLTree<E>::inserthelp(AVLTreeNode<E>* rt, E& val)
{
	if (rt == nullptr)
		rt = new AVLTreeNode<E>(val);
	else if (val < rt->getValue())
	{
		rt->setLeft(inserthelp(rt->left(), val));
		if (rt->balance_factor() == 2)
		{
			if (rt->left()->getValue() > val)
				rt = leftLeftRotation(rt);
			else
				rt = leftRightRotation(rt);
		}
	}
	else
	{
		rt->setRight(inserthelp(rt->right(), val));
		if (rt->balance_factor() == -2)
		{
			if (rt->right()->getValue() > val)
				rt = rightLeaftRotation(rt);
			else
				rt = rightRightRotation(rt);
		}
	}
	rt->setHeight();
	return rt;
}

template<typename E>
inline AVLTreeNode<E>* AVLTree<E>::getmax(AVLTreeNode<E>* rt)
{
	if (rt->right() == nullptr)
		return rt;
	else
		return getmax(rt->right());
}

template<typename E>
inline AVLTreeNode<E>* AVLTree<E>::getmin(AVLTreeNode<E>* rt)
{
	if (rt->left() == nullptr)
		return rt;
	else
		return getmin(rt->left());
}

template<typename E>
inline AVLTreeNode<E>* AVLTree<E>::deletemin(AVLTreeNode<E>* rt)
{
	if (rt->left() == nullptr)
		return rt->right();
	else
	{
		rt->setLeft(deletemin(rt->left()));
		return rt;
	}
}

template<typename E>
inline AVLTreeNode<E>* AVLTree<E>::removehelp(AVLTreeNode<E>* rt, E & val)
{
	if (rt != nullptr)
	{
		if (rt->getValue() > val)
		{
			AVLTreeNode<E>*temp = removehelp(rt->left(), val);
			rt->setLeft(temp);
			if (rt->balance_factor() == -2)
			{
				if (rt->balance_factor() == 1)
					rt = rightLeaftRotation(rt);
				else
					rt = rightRightRotation(rt);
			}
			
		}
		else if (rt->getValue() < val)
		{
			AVLTreeNode<E>* temp = removehelp(rt->right(), val);
			rt->setRight(temp);
			if (rt->balance_factor() == 2)
			{
				if (rt->left()->balance_factor() == 1)
					rt = leftLeftRotation(rt);
				else
					rt = leftRightRotation(rt);
			}
		}
		else
		{
			AVLTreeNode<E>* temp = rt;
			if (rt->left() == nullptr)
			{
				rt = rt->right();
				delete temp;
			}
			else if (rt->right() == nullptr)
			{
				rt = rt->left();
				delete temp;
			}
			else
			{
				AVLTreeNode<E>* temp = getmin(rt->right());
				rt->setValue(temp->getValue());
				rt->setRight(deletemin(rt->right()));
				delete temp;
				if (rt->balance_factor() == 2)
					rt = leftLeftRotation(rt);
			}
		}
	return rt;
	}
	else
		return NULL;
}

template<typename E>
inline AVLTreeNode<E>* AVLTree<E>::leftLeftRotation(AVLTreeNode<E>* rt)
{
	AVLTreeNode<E>* rt_left = rt->left();
	rt->setLeft(rt_left->right());
	rt_left->setRight(rt);
	return rt_left;
}

template<typename E>
inline AVLTreeNode<E>* AVLTree<E>::rightRightRotation(AVLTreeNode<E>* rt)
{
	AVLTreeNode<E>* rt_right = rt->right();
	rt->setRight(rt_right->left());
	rt_right->setLeft(rt);
	return rt_right;
}

template<typename E>
inline AVLTreeNode<E>* AVLTree<E>::leftRightRotation(AVLTreeNode<E>* rt)
{
	rt->setLeft(rightRightRotation(rt->left()));
	return leftLeftRotation(rt);
}

template<typename E>
inline AVLTreeNode<E>* AVLTree<E>::rightLeaftRotation(AVLTreeNode<E>* rt)
{
	rt->setRight(leftLeftRotation(rt->right()));
	return rightRightRotation(rt);
}

template<typename E>
inline void AVLTree<E>::preOrderTraversalhelp(AVLTreeNode<E>* rt) const
{
	if (rt != nullptr)
	{
		cout << rt->getValue() << " ";
		preOrderTraversalhelp(rt->left());
		preOrderTraversalhelp(rt->right());
	}
	return;
}

template<typename E>
inline void AVLTree<E>::inOrderTraversalhelp(AVLTreeNode<E>* rt) const
{
	if (rt != nullptr)
	{
		inOrderTraversalhelp(rt->left());
		cout << rt->getValue() << " ";
		inOrderTraversalhelp(rt->right());
	}
	return;
}

template<typename E>
inline void AVLTree<E>::postOrderTraversalhelp(AVLTreeNode<E>* rt) const
{
	if (rt != nullptr)
	{
		postOrderTraversalhelp(rt->left());
		postOrderTraversalhelp(rt->right());
		cout << rt->value << " ";
	}
	return;
}

template<typename E>
inline void AVLTree<E>::clearhelp(AVLTreeNode<E>* rt)
{
	if (rt == nullptr)
		return;
	clearhelp(rt->left());
	clearhelp(rt->right());
	delete rt;
	return;
}

template<typename E>
inline AVLTree<E>::AVLTree()
{
	root = nullptr;
}

template<typename E>
inline AVLTree<E>::~AVLTree()
{
}

template<typename E>
inline void AVLTree<E>::insert(E & val)
{
	root = inserthelp(root, val);
	return;
}

template<typename E>
inline void AVLTree<E>::remove(E & val)
{
	root = removehelp(root, val);
	return;
}

template<typename E>
inline void AVLTree<E>::clear()
{
	clearhelp(root);
	return;
}

template<typename E>
inline void AVLTree<E>::preOrderTraversal() const
{
	preOrderTraversalhelp(root);
	return;
}

template<typename E>
inline void AVLTree<E>::inOrderTraversal() const
{
	preOrderTraversalhelp(root);
	return;
}

template<typename E>
inline void AVLTree<E>::postOrderTraversal() const
{
	postOrderTraversalhelp(root);
	return;
}

template<typename E>
inline E AVLTree<E>::maxValue() const
{
	AVLTreeNode<E>* temp = getmax(root);
	return temp->getValue();
}

template<typename E>
inline E AVLTree<E>::minValue() const
{
	AVLTreeNode<E>* temp = getmin(root);
	return temp->getValue();
}
