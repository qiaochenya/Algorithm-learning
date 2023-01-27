#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 210;
int d[N][N];
int n, m, q;

void floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == j) d[i][j] = 0;	//防止自环
			else d[i][j] = 1e9;

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);	//取最小的边
	}

	floyd();

	while (q--)
	{
		int a, b;
		cin >> a >> b;
		if (d[a][b] > 1e9 / 2) cout << "inpossible" << endl;	//它不能通向那个点，但可能负边将它更新了
		else cout << d[a][b];
	}
	return 0;
}