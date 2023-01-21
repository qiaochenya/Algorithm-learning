#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
using namespace std;
//题目n个点m条边的有向图，图中可能存在重边和自环，所有边长都是1，点的编号是1~n
//请求出从1号点到n号点的距离，无法走到就输出-1
const int N = 100010;
int q[N], d[N];
int n, m;
int h[N], e[N], ne[N], idx;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs()
{
	int hh = 0, tt = 0;
	q[0] = 1;
	d[1] = 0;	//第一个点
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (d[j] == -1)	//防止重边和自环
			{
				d[j] = d[t] + 1;
				q[++tt] = j;
			}
		}
	}
	return d[n];
}

int main()
{
	//n是点，m是边数
	cin >> n >> m;
	memset(h, -1, sizeof(h));
	memset(d, -1, sizeof(d));	//因为找不到路径就输出-1
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	cout << bfs() << endl;
	return 0;
}