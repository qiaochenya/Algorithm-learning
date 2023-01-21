#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int n, m;
#define N 110
int d[N][N], g[N][N];
pair<int, int>q[N * N], Prex[N][N];

int bfs()
{
	int hh = 0, tt = 0;
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
	while (hh <= tt)
	{
		pair<int, int>t = q[hh++];
		for (int i = 0; i < 4; i++)
		{
			int x = t.first + dx[i], y = t.second + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
			{
				Prex[x][y] = t;
				d[x][y] = d[t.first][t.second] + 1;
				q[++tt] = { x,y };
			}
		}
	}
	int x = n - 1, y = m - 1;
	while (x != 0 || y != 0)
	{
		cout << x << " " << y << endl;
		pair<int, int>t = Prex[x][y];
		x = t.first;
		y = t.second;
	}
	return d[n - 1][m - 1];
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> g[i][j];
	//≥ı ºªØ
	memset(d, -1, sizeof(d));
	q[0] = { 0,0 };
	d[0][0] = 0;

	cout << bfs() << endl;
	return 0;
}