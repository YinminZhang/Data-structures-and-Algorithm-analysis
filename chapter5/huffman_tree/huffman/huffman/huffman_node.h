// Huffman tree node abstract base class
#ifndef HUFFNODE_H_
#define HUFFNODE_H_

template<typename E>
class HuffNode
{
public:
	virtual ~HuffNode(){}			// Base destructor
	virtual int weight() = 0;		// Return frequency
	virtual bool isLeaf() = 0;		// Determine type
};

// Leaf node subclass
template<typename E>
class LeafNode :public HuffNode<E>
{
private:
	E it;							// Value
	int wgt;						// Weight
public:
	LeafNode(const E& val, int freq)
	{
		it = val;
		wgt = freq;
	}
	int weight()const
	{
		return wgt;
	}
	E val()const
	{
		return it;
	}
	bool isLeaf()
	{
		return true;
	}
};

// Internal node subclass
template<typename E>
class IntlNode :public HuffNode<E>
{
private:
	HuffNode<E>* lc;				// Left child
	HuffNode<E>* rc;				// Right child
	int wgt;
public:
	IntlNode(HuffNode<E>* l, HuffNode<E>* r)
	{
		wgt = l->weight() + r->weight();
		lc = l;
		rc = r;
	}
	int weight()const
	{
		return weight;
	}
	bool isLeaf()
	{
		return false;
	}
	void setLeft(HuffNode<E>* b)
	{
		lc = (HuffNode<E>*)b;
	}
	void setRight(HuffNode<E>* b)
	{
		rc = (HuffNode<E>*)b;
	}
	HuffNode<E>* left()const
	{
		return lc;
	}
	HuffNode<E>* right()const
	{
		return rc;
	}
};

#endif // !HUFFNODE_H_
