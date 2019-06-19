#include"array_based_queue_bool.h"
#include"AStack.h"

void main()
{
	AQueue<int> m(4);
	m.enqueue(11);
	m.enqueue(12);
	m.enqueue(13);
	m.enqueue(14);
	int x = m.length();
	AStack<int>mm(x);
	for (int i = 0; i < x; i++)
	{
		int ww = m.dequeue();
		m.length();
		mm.push(ww);
		cout << ww << " ";
	}
	for (int i = 0; i < x; i++)
	{
		int qq = mm.pop();
		m.length();
		m.enqueue(qq);
		m.length();
	}
	for (int i = 0; i < x; i++)
		cout << m.dequeue() << " ";
}
