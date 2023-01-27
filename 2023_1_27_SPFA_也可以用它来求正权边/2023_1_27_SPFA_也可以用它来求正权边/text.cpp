#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

//const int N = 100010;
//int h[N], e[N], ne[N], M[N], idx;
//int dist[N];
//int n, m;
//bool st[N];
//
//void add(int a, int b, int c)
//{
//	e[idx] = b;
//	M[idx] = c;
//	ne[idx] = h[a];
//	h[a] = idx++;
//}
//
//int SPFA()
//{
//	memset(dist, 0x3f, sizeof(dist));
//	dist[1] = 0;
//	queue<int> q;
//	q.push(1);
//	st[1] = true;
//
//	while (q.size())
//	{
//		int t = q.front();
//		q.pop();
//		st[t] = false;
//
//		for (int i = h[t]; i != -1; i = ne[i])
//		{
//			int j = e[i];
//			if (dist[j] > dist[t] + M[i])
//			{
//				dist[j] = dist[t] + M[i];
//				if (st[j] == false)
//				{
//					q.push(j);
//					st[j] = true;
//				}
//			}
//		}
//
//	}
//	if (dist[n] == 0x3f3f3f3f) return -1;
//	return dist[n];
//}
//
//int main()
//{
//	cin >> n >> m;
//	memset(h, -1, sizeof(h));
//
//	while (m--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		add(a, b, c);
//	}
//
//	cout << SPFA() << endl;
//	return 0;
//}

const int N = 100010;
int h[N], e[N], ne[N], M[N], idx;
int n, m;
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c)
{
	e[idx] = b;
	M[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool spfa()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
		st[i] = true;
	}
	while (q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false;

		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + M[i])
			{
				dist[j] = dist[t] + M[i];
				cnt[j] = cnt[t] + 1;

				if (cnt[j] >= n) return true;

				if (st[j] == false)
				{
					st[j] = true;
					q.push(j);
				}
			}
		}
	}
	return false;
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof(h));
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	if (spfa() == true) puts("yes");
	else puts("no");
	return 0;
}