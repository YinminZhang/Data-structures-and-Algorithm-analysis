// Node implementation with simple inheritance
#ifndef VARBINNODE_H
#define VARBINNODE_H
#include<iostream>
using std::endl;
using std::cout;
using std::ostream;

class Operand{
	friend ostream& operator<<(const ostream& os, const Operand& op)
	{
		cout << endl;
		return os;
	}
};

class Operator{
public:
	friend ostream& operator<<(const ostream& os,const Operator& op)
	{
		os << endl;
		return os;
	}
};

class VarBinNode
{
public:
	virtual ~VarBinNode() {}
	// Subclass must implement
	virtual bool isLeaf() = 0;
};

// Leaf node
class LeafNode :public VarBinNode
{
private:
	Operand var;		// Operand value
public:
	// Constructor
	LeafNode(const Operand& val) { var = val; }
	// Version for LeafNode
	bool isLeaf() { return true; }
	// Return node value
	Operand value() { return var; }
};	

// Internal node
class IntlNode :public VarBinNode
{
private:
	VarBinNode* left;			// Left child
	VarBinNode* right;			// Right child
	Operator opx;				// Operator value
public:
	// Constructor
	IntlNode(const Operator&op, VarBinNode* l, VarBinNode* r)
	{
		opx = op; left = l; right = r;
	}
	// Version for INtlNode
	bool isLeaf() { return false; }
	// Left child
	VarBinNode* leftchild() { return left; }
	// Right child
	VarBinNode* rightchild() { return right; }
	// Value
	Operator value() { return opx; }
};

// Preorder traversal
void traverse(VarBinNode* root)
{
	if (root == nullptr)		// Nothing to visit
		return;
	if (root->isLeaf())
		cout << "Leaf: " << ((LeafNode*)root)->value() << endl;
	else
	{
		cout << "Internal: " << ((IntlNode*)root)->value() << endl;
		traverse(((IntlNode*)root)->leftchild());
		traverse(((IntlNode*)root)->rightchild());
	}
}

#endif // !VARBINNODE_H