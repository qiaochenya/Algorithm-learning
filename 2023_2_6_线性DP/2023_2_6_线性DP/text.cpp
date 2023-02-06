#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
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

const int N = 1010;
int n, m;
char a[N], b[N];
int f[N][N];

int main()
{
	cin >> n >> m;
	cin >> a + 1 >> b + 1;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
		}
	}
	cout << f[n][m] << endl;
	return 0;
}