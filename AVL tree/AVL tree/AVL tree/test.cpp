#include<iostream>
#include"AVL.h"
using std::endl;
using std::cout;

int main()
{
	int arr[] = { 3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9 };
	AVLTree<int> test;
	for (int i = 0; i < 16; i++)
		test.insert(arr[i]);
	test.remove(arr[12]);
	test.preOrderTraversal();
	return 0;
}