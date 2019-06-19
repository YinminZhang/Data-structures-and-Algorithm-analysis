// Binary Search Tree implementation for the Dictionary ADT
#ifndef BST_H_
#define BST_H_
#include"Dict_ADT.h"
#include"BSTNode.h"
#include<iostream>
using std::endl;
using std::cout;

template<typename Key, typename E>
class BST :public Dictionary<Key, E>
{
private:
	BSTNode<Key, E>* root;			// Root of the BST
	int nodecount;					// Number of nodes in the BST

	// Private "helper" function
	void clearhelp(BSTNode<Key, E>*);
	BSTNode<Key, E>* inserthelp(BSTNode<Key, E>*, const Key&, const E&);
	BSTNode<Key, E>* deletemin(BSTNode<Key, E>*);
	BSTNode<Key, E>* getmin(BSTNode<Key, E>*);
	// Remove a node with key value k
	// Return: The tree with the node removed
	// Remove a node with key value k
	// Return: The tree with the node removed
	BSTNode<Key, E>* removehelp(BSTNode<Key, E>*, const Key&);
	E findhelp(BSTNode<Key, E>*, const Key&)const;
	void printhelp(BSTNode<Key, E>*, int)const;


	// Traverse
	void preOrderTraversehelp(BSTNode<Key, E>* rt)const
	{
		if (rt != nullptr)
		{
			cout << rt->element() << " ";
			preOrderTraversehelp(rt->left());
			preOrderTraversehelp(rt->right());
		}
		return;
	}
	void inOrderTraversehelp(BSTNode<Key, E>* rt)const
	{
		if (rt != nullptr)
		{
			inOrderTraversehelp(rt->left());
			cout << rt->element() << " ";
			inOrderTraversehelp(rt->right());
		}
		return;
	}
	void postOrderTraversehelp(BSTNode<Key, E>* rt)const
	{
		if (rt != nullptr)
		{
			postOrderTraversehelp(rt->left());
			postOrderTraversehelp(rt->right());
			cout << rt->element() << " ";
		}
		return;
	}
public:
	// Constructor
	BST() { root = nullptr; nodecount = 0; }
	// Destructor
	~BST() {}

	// Reinitialize tree
	void clear()
	{
		clearhelp(root);
		root = nullptr;
		nodecount = 0;
	}

	// Insert a record into the tree.
	// k Key value of the record.
	// e The record to insert
	void insert(const Key&k, const E&e)
	{
		root = inserthelp(root, k, e);
		nodecount++;
	}

	// Remove a record from the tree.
	// k Key value of record to remove.
	// Return: The record removed, or nullptr if there is none.
	E remove(const Key&k)
	{
		// First find it
		E temp = findhelp(root, k);			// First find it
		if (temp != NULL)
		{
			root = removehelp(root, k);
			nodecount--;
		}
		return temp;
	}

	// Remove and return the root node from the dictionary.
	// Return: The record removed, nullptr if tree is empty.
	E removeAny()
	{
		if (root != nullptr)
		{
			E temp = root->element();
			root = removehelp(root, root->key());
			nodecount--;
			return temp;
		}
		else
			return NULL;
	}

	// Return Record with key value k, nullptr if none exist.
	// k: The key value to find
	// Return some record matching "k".
	// Return true if such exists, false otherwise.
	// If multiple records match "k",return an arbitrary one.
	E find(const Key&k)const { return findhelp(root, k); }

	// Return the number of records in the dictionary.
	int size() { return nodecount; }

	// Print the contents of the BST
	void print()const
	{
		if (root == nullptr)
			cout << "The BST is empty." << endl;
		else
			printhelp(root, 0);
	}

	void preOrderTraverse()const
	{
		preOrderTraversehelp(root);
		cout << endl;
		return;
	}
	void inOrderTraverse()const
	{
		inOrderTraversehelp(root);
		cout << endl;
		return;
	}
	void postOrderTraverse()const
	{
		postOrderTraversehelp(root);
		cout << endl;
		return;
	}
};

template<typename Key, typename E>
inline void BST<Key, E>::clearhelp(BSTNode<Key, E>* rt)
{
	if (rt == nullptr)
		return;
	clearhelp(rt->left());
	clearhelp(rt->right());
	delete rt;
}

template<typename Key, typename E>
inline BSTNode<Key, E>* BST<Key, E>::inserthelp(BSTNode<Key, E>* root, const Key& k, const E& it)
{
	if (root == nullptr)				// Empty tree: create node
		return new BSTNode<Key, E>(k, it, nullptr, nullptr);
	if (k < root->key())
		root->setLeft(inserthelp(root->left(), k, it));
	else
		root->setRight(inserthelp(root->right(), k, it));
	return root;						// Return tree with node inserted
}

template<typename Key, typename E>
inline BSTNode<Key, E>* BST<Key, E>::deletemin(BSTNode<Key, E>*rt)
{
	if (rt->left() == nullptr)		// Fonund min
		return rt->right();
	else
	{								// Continue left
		rt->setLeft(deletemin(rt->left()));
		return rt;
	}
}

template<typename Key, typename E>
inline BSTNode<Key, E>* BST<Key, E>::getmin(BSTNode<Key, E>* rt)
{
	if (rt->left() == nullptr)
		return rt;
	else
		return getmin(rt->left());
}

template<typename Key, typename E>
inline BSTNode<Key, E>* BST<Key, E>::removehelp(BSTNode<Key, E>* rt, const Key & k)
{
	if (rt == nullptr)			// k is not in tree
		return NULL;
	else if (k < rt->key())
		rt->setLeft(removehelp(rt->left(), k));
	else if (k > rt->key())
		rt->setRight(removehelp(rt->right(), k));
	else							// Found: remove it
	{
		BSTNode<Key, E>* temp = rt;
		if (rt->left() == nullptr)	// Only a right child
		{
			rt = rt->right();
			delete temp;
		}
		else if (rt->right() == nullptr)	// Only a left child
		{
			rt = rt->left();
			delete temp;
		}
		else
		{
			BSTNode<Key, E>* temp = getmin(rt->right());
			rt->setElement(temp->element());
			rt->setKey(temp->key());
			rt->setRight(deletemin(rt->right()));
		}
	}
	return rt;
}

template<typename Key, typename E>
inline E BST<Key, E>::findhelp(BSTNode<Key, E>*root, const Key &k) const
{
	if (root == nullptr)					// Empty tree
		return NULL;
	if (k < root->key())
		return findhelp(root->left(), k);	// Check left
	else if (k > root->key())
		return findhelp(root->right(), k);	// Check right
	else
		return root->element();				// Find it
}

template<typename Key, typename E>
inline void BST<Key, E>::printhelp(BSTNode<Key, E>* rt, int level) const
{
	if (rt == nullptr)						// Empty tree
		return;
	printhelp(rt->left(), level + 1);		// Do left subtree
	for (int i = 0; i < level; i++)			// Indent to level
		cout << " ";
	cout << rt->key() << endl;				// Print node value
	printhelp(rt->right(), level + 1);		// Do right subtree
}

#endif // !BST_H_