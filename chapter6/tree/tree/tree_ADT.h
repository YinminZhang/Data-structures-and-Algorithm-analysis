#ifndef TREE_ADT_H_
#define TREE_ADT_H_
#include"treeNode.h"
#include<iostream>
using std::endl;
using std::cout;

// General tree ADT
template<typename E>
class GenTree
{
private:
	// Print using a preorder traversal
	void printhelp(GTNode<E>* root);

public:
	void clear();			// Send all nodes to free store
	GTNode<E>* root();		// Return the root of the tree
	void newroot(E&, GTNode<E>*, GTNode<E>*);	// Combine two subtrees
	void print();			// Print a tree
};

#endif // !TREE_ADT_H_

template<typename E>
inline void GenTree<E>::printhelp(GTNode<E>* root)
{
	if (root->isLeaf())
		cout << "Leaf: ";
	else
		cout << "Internal: ";
	cout << root->value() << endl;
	// Now process the children of "root"
	for (GTNode<E>* temp = root->leftmostChild();
		temp != nullptr; temp = temp->rightSibling())
	{
		printhelp(temp);
	}
}
