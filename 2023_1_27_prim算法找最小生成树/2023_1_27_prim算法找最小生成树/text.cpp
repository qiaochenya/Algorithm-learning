#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
int g[N][N], dist[N];
int n, m;
bool st[N];

int prim()
{
	memset(dist, 0x3f, sizeof(dist));
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)
			if (st[j] == false && (t == -1 || dist[t] > dist[j]))
				t = j;

		st[t] = true;

		if (i != 0 && dist[t] == 0x3f3f3f3f) return 0x3f3f3f3f;

		if (i != 0) res += dist[t];

		for (int j = 1; j <= n; j++)
		{
			dist[j] = min(dist[j], g[t][j]);
		}
	}
	return res;
}

int main()
{
	cin >> n >> m;
	memset(g, 0x3f, sizeof(g));
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = min(g[a][b], c);
	}
	int t = prim();
	if (t == 0x3f3f3f3f) cout << "impossible" << endl;
	else cout << t << endl;
	return 0;
}