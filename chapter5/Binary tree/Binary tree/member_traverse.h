// Node implementation with the composite design pattern
#ifndef MEMBER_H
#include<iostream>
using std::endl;
using std::cout;
using std::ostream;

// Node abstract base class
class VarBinNode
{
public:
	// Generic destructor
	virtual ~VarBinNode() {}
	virtual bool isLeaf() = 0;
	virtual void traverse() = 0;
};

class Operand {
	friend ostream& operator<<(const ostream& os, const Operand& op)
	{
		cout << endl;
		return os;
	}
};

class Operator {
public:
	friend ostream& operator<<(const ostream& os, const Operator& op)
	{
		os << endl;
		return os;
	}
};

// Leaf node
class LeafNode :public VarBinNode
{
private:
	Operand var;			// Operand value
public:
	// Constructor
	LeafNode(const Operand& val) :var(val){}
	// isLeaf for Leafnode
	bool isLeaf() { return true; }
	// Return node value
	Operand value() { return var; }
	void traverse() { cout << "Leaf: " << value() << endl; }
};

// Internal node
class IntlNode :public VarBinNode
{
private:
	VarBinNode* lc;			// Left child
	VarBinNode* rc;			// Right child
	Operator opx;			// Operator value
public:
	// Constructor
	IntlNode(const Operator& op,VarBinNode* l,VarBinNode* r):opx(op),lc(l),rc(r){}
	// isLeaf for IntlNode
	bool isLeaf() { return false; }
	// Left child
	VarBinNode* left() { return lc; }
	// Right child
	VarBinNode* right() { return rc; }
	// Value
	Operator value() { return opx; }

	// Traversal behavior for internal nodes
	void traverse() 
	{
		cout << "Internal: " << value() << endl;
		if (left() != nullptr)
			left()->traverse();
		if (right() != nullptr)
			right()->traverse();
	}
};

// Do a preorder traversal
void traverse(VarBinNode* root)
{
	if (root != nullptr)
		root->traverse();
}
#endif // !MEMBER_H
