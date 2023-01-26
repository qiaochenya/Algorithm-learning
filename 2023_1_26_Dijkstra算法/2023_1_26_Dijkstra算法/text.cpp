#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

//���ذ�dijkstra�㷨

//const int N = 510;
//int g[N][N];
//int n, m;
//int dist[N];	//��1�ŵ�ľ���
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
//			//����s�еľ�������ĵ�
//			if (st[j] == false && (t == -1 || dist[t] > dist[j]))	//-1��Ϊ������������һ����
//			{
//				t = j;
//			}
//		}
//		//����t
//		st[t] = true;
//
//		//��t����������ľ���
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

//���Ż����dijkstra�㷨

typedef pair<int, int>pii;
const int N = 100010;
int n, m;
int e[N], ne[N], M[N], h[N], idx;	//M����Ǹõ㵽ǰһ��ָ�����ĵ�ľ���
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
	//ǰ���������ذ��һ��
	priority_queue<pii, vector<pii>, greater<pii>> heap;
	heap.push({ 0,1 });
	while (heap.size())
	{
		pii t = heap.top();
		heap.pop();	//�����Ѷ�

		int ver = t.second, distance = t.first;

		if (st[ver] == true) continue;	//�޸����ݻ��ܶ��Ѿ�ȷ�����·�ĵ㣬����Ҫ�ж�
		st[ver] = true;

		for (int i = h[ver]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (stra[j] > M[i] + distance)
			{
				stra[j] = M[i] + distance;
				heap.push({ stra[j],j });	//stl�ĶѲ�֧���޸����ݣ�����ֻ����������ӣ���������M������
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
		add(a, b, c);	//���Ż��㷨���Զ�������ر�
	}

	cout << dijkstra() << endl;
	return 0;
}