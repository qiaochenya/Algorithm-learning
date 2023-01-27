#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//走迷宫最短路问题

int n, m;
#define N 110
int d[N][N], g[N][N];
pair<int, int>q[N * N], Prex[N][N];	//Prex数组存走过的路径，方便最后打印出来

int bfs()
{
	int hh = 0, tt = 0;	//tt为0是因为一开始不用给队列里面添加数，和队列已经初始化完成
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };	//上下左右四个位置拓展
	while (hh <= tt)
	{
		pair<int, int>t = q[hh++];
		//4个位置
		for (int i = 0; i < 4; i++)
		{
			int x = t.first + dx[i], y = t.second + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)	//判断是否越界和是否可以走和是否走过
			{
				Prex[x][y] = t;	//存这个点对应的上一个点是什么
				d[x][y] = d[t.first][t.second] + 1;	//距离++
				q[++tt] = { x,y };	//入队
			}
		}
	}
	int x = n - 1, y = m - 1;	//x和y从最后一个点开始
	while (x != 0 || y != 0)
	{
		cout << x << " " << y << endl;
		pair<int, int>t = Prex[x][y];	//这个点的上一个点取出来
		x = t.first;
		y = t.second;
	}
	return d[n - 1][m - 1];	//如果走不到就是0
}
int main()
{
	cin >> n >> m;
	//输入迷宫里面的0和1
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> g[i][j];
	//初始化
	memset(d, -1, sizeof(d));	//链表初始化都指向-1
	q[0] = { 0,0 };	//队列初始化
	d[0][0] = 0;	//起点到起点的距离为0

	cout << bfs() << endl;
	return 0;
}