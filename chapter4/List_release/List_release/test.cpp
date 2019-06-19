#include"Link_Cycle.h"
#include<iostream>
using namespace std;

template<typename E>
LList<E> combine(LList<E>&list1, LList<E>&list2)
{
	LList<E> temp(list1.length() + list2.length());
	for (int i = 0, j = 0; i < list1.length() && j < list2.length();)
	{
		if (!list1.getValue())
		{
			temp.append(list2.getValue());
			list2.next();
			j++;
		}
		else if (!list2.getValue())
		{
			temp.append(list1.getValue());
			list1.next();
			i++;
		}
		else if (list2.getValue() >= list1.getValue())
		{
			temp.append(list1.getValue());
			list1.next();
			i++;
		}
		else
		{
			temp.append(list2.getValue());
			list2.next();
			j++;
		}
	}
	return temp;
}

template<typename E>
void reverse(E*array,int length)
{
	E temp;
	for (int i = 0; i < length < 2; i++)
	{
		temp = array[i];
		array[i] = array[length - i - 1];
		array[length - i - 1] = temp;
	}
}

int main()
{
	LList<int> test_list(5);
	test_list.append(1);
	test_list.append(2);
	test_list.append(3);
	test_list.append(4);
	test_list.append(5);
	test_list.moveToEnd();
	test_list.next();
	cout << test_list.getValue() << endl;
	return 0;
}
