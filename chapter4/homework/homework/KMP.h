#include<iostream>
#include<string>
using std::endl;
using std::cout;
using std::string;

#ifndef KMP
#define KMP

void get_nextval(const string&str, int next[])
{
	int q, k;
	int m = str.size();
	next[0] = 0;
	for (q = 1, k = 0; q < m; ++q)
	{
		while (k > 0 && str[q] != str[k])
			k = next[k - 1];
		if (str[q] == str[k])
			k++;
		next[q] = k;
	}
}

bool KmpMatch(const string &T, const string &P, int next[])
{
	int n, m;
	n = T.size();
	m = P.size();
	get_nextval(P, next);
	for (int i = 0, q = 0; i < n; ++i)
	{
		while (q > 0 && P[q] != T[i])
			q = next[q - 1];
		if (P[q] == T[i])
			q++;
		if (q == m)
			return true;
	}
	return false;
}
#endif // !KMP
