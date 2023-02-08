#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//整数划分

//const int N = 1010, mod = 1e9 + 7;
//int n, f[N];
//
//int main()
//{
//	cin >> n;
//	f[0] = 1;
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = i; j <= n; j++)
//		{
//			f[j] = f[j] + f[j - i];
//		}
//	}
//	cout << f[n] << endl;
//	return 0;
//}

//const int N = 1010, mod = 1e9 + 7;
//int n, f[N][N];
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i <= n; i++) f[i][0] = 1;
//	
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			//cout << i << " " << j - i << " " << f[i][j - i] << "|";
//			if (j - i >= 0)
//			{
//				f[i][j] = f[i - 1][j] + f[i][j - i];
//			}
//			else f[i][j] = f[i - 1][j];
//		}
//	}
//	cout << f[n][n] << endl;
//	//cout << f[4][1] << endl;
//	return 0;
//}

//其他算法

const int N = 1010;
int n;
int f[N][N];

int main()
{
	cin >> n;
	f[0][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			f[i][j] = f[i - 1][j - 1] + f[i - j][j];
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) res += f[n][i];
	cout << res << endl;
	return 0;

}