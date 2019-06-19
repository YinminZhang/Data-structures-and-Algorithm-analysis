#include"AStack.h"

using namespace std;

long fact(int n)
{
	long val = 0;
	AStack<int> Tn;
	Tn.push(n);

	while (!Tn.empty())
	{
		int temp = Tn.topValue();
		Tn.pop();

		if (temp == 1)
		{
			val += 1;
		}
		else
		{
			Tn.push((temp + 1) / 2);
			Tn.push(temp / 2);
			val += temp;
		}

	}
	return val;
}
