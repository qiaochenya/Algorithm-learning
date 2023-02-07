#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

//数字三角形

//const int N = 510, INF = 1e9;
//int n;
//int a[N][N], f[N][N];
//
//int main()
//{
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= i; j++)
//			cin >> a[i][j];
//
//	for (int i = 0; i <= n; i++)
//		for (int j = 0; j <= i + 1; j++)	//每行多初始化一个
//			f[i][j] = -INF;
//
//	f[1][1] = a[1][1];
//
//	for (int i = 2; i <= n; i++)
//		for (int j = 1; j <= i; j++)
//			f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);
//
//	int res = -INF;
//
//	for (int i = 1; i <= n; i++) res = max(res, f[n][i]);
//	cout << res << endl;
//	return 0;
//}

//最长上升子序列

//const int N = 1145;
//int n;
//int a[N], f[N];
//
//int main()
//{
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//
//    for (int i = 1; i <= n; i++)
//    {
//        f[i] = 1;
//        for (int j = 1; j < i; j++)
//        {
//            if (a[j] < a[i])
//            {
//                f[i] = max(f[j] + 1, f[i]);
//            }
//        }
//    }
//
//    int res = 0;
//    for (int i = 1; i <= n; i++) res = max(res, f[i]);
//
//    cout << res << endl;
//    return 0;
//}

//优化

//const int N = 100010;
//int n;
//int a[N], q[N];
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	q[0] = -2e9;
//	int len = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int l = 0, r = len;
//		while (l < r)
//		{
//			int mid = (l + r + 1) / 2;
//			if (q[mid] <= a[i]) l = mid;
//			else r = mid - 1;
//		}
//		len = max(len, r + 1);
//		q[r + 1] = a[i];
//	}
//	cout << len << endl;
//	return 0;
//}

//存状态的方法

//const int N = 1145;
//int a[N], f[N], g[N];
//int n;
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//
//	for (int i = 1; i <= n; i++)
//	{
//		f[i] = 1;
//		g[i] = 0;
//		for (int j = 1; j < i; j++)
//		{
//			if (a[i] > a[j])
//				if (f[i] < f[j] + 1)
//				{
//					f[i] = f[j] + 1;
//					g[i] = j;
//				}
//		}
//	}
//
//	int k = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		if (f[i] > f[k])
//			k = i;
//	}
//	cout << f[k] << endl;
//	for (int i = 0, len = f[k]; i < len; i++)
//	{
//		cout << a[k] << " ";
//		k = g[k];
//	}
//	return 0;
//}

//最长公共子序

//const int N = 1010;
//int n, m;
//char a[N], b[N];
//int f[N][N];
//
//int main()
//{
//	cin >> n >> m;
//	cin >> a + 1 >> b + 1;
//	
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
//			if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
//		}
//	}
//	cout << f[n][m] << endl;
//	return 0;
//}

//最短编辑距离

//const int N = 1010;
//int n, m;
//char a[N], b[N];
//int f[N][N];
//
//int main()
//{
//	cin >> n >> a + 1 >> m >> b + 1;
//	//初始化
//
//	for (int i = 0; i <= m; i++) f[0][i] = i;
//	for (int i = 0; i <= n; i++) f[i][0] = i;
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
//			if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
//			else  f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
//		}
//	}
//	cout << f[n][m] << endl;
//	return 0;
//}

//最短编辑距离的应用

const int N = 15, M = 1010;
char a[M][N];
int f[N][N];
int n, m;

int find(char a[], char b[])
{
	
	int la = (int)strlen(a + 1), lb = (int)strlen(b + 1);
	for (int i = 1; i <= la; i++) f[i][0] = i;
	for (int i = 1; i <= lb; i++) f[0][i] = i;

	for (int i = 1; i <= la; i++)
		for (int j = 1; j <= lb; j++)
		{
			f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
			if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			else f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
		}
	return f[la][lb];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", a[i] + 1);
	while (m--)
	{
		char b[N];
		int limit;
		scanf("%s%d", b + 1, &limit);
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			if (find(a[i], b) <= limit)
				res++;
		}
		printf("%d\n", res);
	}
	return 0;
}