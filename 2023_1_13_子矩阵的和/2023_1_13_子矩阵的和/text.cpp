#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#define N 1010
int a[N][N], s[N][N];
int n, m, q;
int main()
{
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];	//求前缀和，加上两条柱，减去重合，加上一点
	while (q--)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1] << endl;	//求子区间，大块减去两条柱，加上减多的部分
	}
	return 0;
}

//3 4 3
//1 7 2 4
//3 6 2 8
//2 1 2 3
//1 1 2 2
//2 1 3 4
//1 3 3 4

//17
//27 
//21