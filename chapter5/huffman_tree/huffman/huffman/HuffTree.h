// HuffTree is a template of two parameters:
// the element type being coded and a comparator for two such elements.
#ifndef HUFFTREE_H_
#define HUFFTREE_H_
#include"huffman_node.h"

template<typename E>
class HuffTree
{
private:
	HuffTree<E>* Root;			// Huffman Tree root
public:
	// Leaf constructor
	HuffTree(E& val, int freq)
	{
		Root = new LeafNode<E>(val, freq);
	}
	// Internal node constructor
	HuffTree(HuffTree<E>* l, HuffTree<E>* r)
	{
		Root = new IntlNode(l->root(), r->root());
	}
	// Get root
	HuffNode<E>* root()const
	{
		return Root;
	}
	// Root weight
	int weight()const
	{
		return Root->weight();
	}
	// Destructor
	~HuffTree()
	{

	}
};

// Get the min node
template<typename E>
HuffNode<E>* minHuffNode(HuffTree<E>** TreeArray, int count)
{
	HuffNode<E>* temp = *TreeArray;
	int pos;
	for (int i = 0; i < count; i++)
	{
		if (temp->weight() > TreeArray[i].weight())
		{
			temp = TreeArray[i];
			pos = i;
		}
	}
	for (int i = pos, i < count, i++)
	{
		TreeArray[i] = TreeArray[i + 1];
	}
	return temp;
}

// Build a Huffman tree from a collection of frequencies
template<typename E>
HuffTree<E>* buildHuff(HuffTree<E>** TreeArray, int count)
{
	HuffTree<E> *temp1, *temp2, temp3 = nullptr;
	while (count > 1)
	{
		temp1 = minHuffNode(TreeArray, count--);
		temp2 = minHuffNode(TreeArray, count--);
		temp3 = new HuffTree<E>(temp1, temp2);
		TreeArray[count++] = temp3;
	}
	return *TreeArray;
}

#endif // !HUFFTREE_H_
