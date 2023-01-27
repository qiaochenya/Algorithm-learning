#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200010;
int n, m;
int fa[N];

struct Edge
{
	int a, b, c;
}edge[N];

bool cmp(Edge x, Edge y)
{
	return x.c < y.c;
}

int find(int x)
{
	if (x != fa[x]) fa[x] = find(fa[x]);
	return fa[x];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = { a, b, c };
	}
	sort(edge, edge + m, cmp);

	for (int i = 1; i <= n; i++) fa[i] = i;

	int res = 0, cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		a = edge[i].a, b = edge[i].b, c = edge[i].c;
		a = find(a), b = find(b);
		if (a != b)
		{
			res += c;
			cnt++;
			fa[a] = b;
		}
	}

	if (cnt < n - 1) cout << "impossible" << endl;
	else cout << res << endl;
	return 0;
}