#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

//朴素版dijkstra算法

//const int N = 510;
//int g[N][N];
//int n, m;
//int dist[N];	//到1号点的距离
//bool st[N];
//
//int dijkstra()
//{
//	memset(dist, 0x3f, sizeof(dist));
//	dist[1] = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int t = -1;
//		for (int j = 1; j <= n; j++)
//		{
//			//不在s中的距离最近的点
//			if (st[j] == false && (t == -1 || dist[t] > dist[j]))	//-1是为了让他进入下一个数
//			{
//				t = j;
//			}
//		}
//		//加入t
//		st[t] = true;
//
//		//用t跟新其他点的距离
//		for (int j = 1; j <= n; j++)
//		{
//			dist[j] = min(dist[j], dist[t] + g[t][j]);
//		}
//	}
//	if (dist[n] == 0x3f3f3f3f)
//		return -1;
//	return dist[n];
//}
//
//int main()
//{
//	cin >> n >> m;
//	memset(g, 0x3f, sizeof(g));
//	while (m--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		g[a][b] = min(g[a][b], c);
//	}
//	cout << dijkstra() << endl;
//	return 0;
//}

//堆优化版的dijkstra算法

typedef pair<int, int>pii;
const int N = 100010;
int n, m;
int e[N], ne[N], M[N], h[N], idx;	//M存的是该点到前一个指向它的点的距离
int stra[N];
bool st[N];

void add(int a, int b, int c)
{
	e[idx] = b;
	M[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

int dijkstra()
{
	memset(stra, 0x3f, sizeof(stra));
	stra[1] = 0;
	//前两步和朴素版的一样
	priority_queue<pii, vector<pii>, greater<pii>> heap;
	heap.push({ 0,1 });
	while (heap.size())
	{
		pii t = heap.top();
		heap.pop();	//弹出堆顶

		int ver = t.second, distance = t.first;

		if (st[ver] == true) continue;	//修改数据会多很多已经确定最短路的点，所以要判断
		st[ver] = true;

		for (int i = h[ver]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (stra[j] > M[i] + distance)
			{
				stra[j] = M[i] + distance;
				heap.push({ stra[j],j });	//stl的堆不支持修改数据，所以只能往里面添加，最后堆最多存M个数据
			}
		}
	}
	if (stra[n] == 0x3f3f3f3f)
		return -1;
	return stra[n];
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof(h));
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);	//堆优化算法会自动处理掉重边
	}

	cout << dijkstra() << endl;
	return 0;
}