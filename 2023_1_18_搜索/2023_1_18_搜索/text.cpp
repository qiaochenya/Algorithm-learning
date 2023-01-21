#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//��������

//const int N = 10;
//int n;
//int path[N];
//bool st[N];
//
//void dfs(int u)
//{
//	if (u == n)
//	{
//		for (int i = 0; i < n; i++)
//			cout << path[i] << " ";
//		cout << endl;
//		return;
//	}
//	for (int i = 1; i <= n; i++)	//����ÿһ����
//	{
//		if (st[i] == false)	//���Ǹ�����û���ù�
//		{
//			path[u] = i;
//			st[i] = true;
//			dfs(u + 1);	// ���ǵ���һ��
//			st[i] = false;	//��ԭ�ֳ�
//		}
//	}
//}
//
//int main()
//{
//	cin >> n;
//	dfs(0);
//	return 0;
//}

//n�ʺ�

//const int N = 20;
//int n;
//char g[N][N];
//bool col[N], dg[N], udg[N];
//
//void dfs(int u)
//{
//	if (n == u)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				cout << g[i][j];
//			}
//			cout << endl;
//		}
//		cout << endl;
//		return;
//	}
//	for (int i = 0; i < n; i++)	//ö����
//	{
//		if (!col[i] && !dg[i + u] && !udg[n - u + i])
//		{
//			g[u][i] = 'G';
//			col[i] = dg[i + u] = udg[n - u + i] = true;
//			dfs(u + 1);
//			g[u][i] = '.';
//			col[i] = dg[i + u] = udg[n - u + i] = false;
//		}
//
//	}
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			g[i][j] = '.';
//	dfs(0);
//	return 0;
//}

//��һ��д����ö��ÿһ������

const int N = 20;
int n;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];

void dfs(int x, int y, int s)
{
	if (y == n)
		x++, y = 0;
	if (x == n)
	{
		if (s == n)
		{
			for (int i = 0; i < n; i++)
				puts(g[i]);
			cout << endl;
			return;
		}
		return;
	}
	//��һ�����Żʺ�
	dfs(x, y + 1, s);
	//�Żʺ�
	if (!row[x] && !col[y] && !dg[y + x] && !udg[x - y + n])
	{
		g[x][y] = 'Q';
		row[x] = col[y] = dg[y + x] = udg[x - y + n] = true;
		dfs(x, y + 1, s + 1);
		g[x][y] = '.';
		row[x] = col[y] = dg[y + x] = udg[x - y + n] = false;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = '.';
	dfs(0, 0, 0);
	return 0;
}