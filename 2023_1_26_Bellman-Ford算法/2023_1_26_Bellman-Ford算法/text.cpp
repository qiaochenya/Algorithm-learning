#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 100010;
int n, m, k;
int stra[N], backup[N];

struct edge
{
	int a, b, c;
}Edge[M];

int bellman()
{
	memset(stra, 0x3f, sizeof(stra));
	stra[1] = 0;

	for (int i = 0; i < k; i++)
	{
		memcpy(backup, stra, sizeof(stra));
		for (int j = 0; j < m; j++)
		{
			int a = Edge[j].a, b = Edge[j].b, c = Edge[j].c;
			stra[b] = min(stra[b], backup[a] + c);
		}
	}
	if (stra[n] > 0x3f3f3f3f / 2) return -1;
	return stra[n];
}

int main()
{
	cin >> n >> m >> k;	
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Edge[i] = { a,b,c };
	}
	int t = bellman();
	if (t == -1)
		cout << "impossible" << endl;
	else
		cout << t << endl;
	return 0;
}