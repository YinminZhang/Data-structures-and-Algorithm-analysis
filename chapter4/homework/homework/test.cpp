#include"KMP.h"

int main()
{
	int next[4];
	bool test;
	test=KmpMatch("ACABA", "ABA", next);
	cout << test << endl;
}