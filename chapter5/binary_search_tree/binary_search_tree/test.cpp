#include"binary_search_tree.h"

int main()
{
	BST<int,int>test;
	test.insert(15,15);
	test.insert(20,20);
	test.insert(25, 25);
	test.insert(18, 18);
	test.insert(16, 16);
	test.insert(5, 5);
	test.insert(7, 7);
	test.preOrderTraverse();
	test.inOrderTraverse();
	test.postOrderTraverse();
}