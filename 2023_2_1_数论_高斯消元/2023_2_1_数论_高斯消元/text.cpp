#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
using namespace std;

const int N = 110;
int n;
double a[N][N];

void cou()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int gaosi()
{
	int c, r;
	for (c = 0, r = 0; c < n; c++)
	{
		int t = r;
		for (int i = r; i < n; i++)
			if (fabs(a[t][c]) < fabs(a[i][c]))
				t = i;

		if (fabs(a[t][c]) < 1e-6) continue;

		for (int i = c; i <= n; i++) swap(a[t][i], a[r][i]);

		for (int i = n; i >= c; i--) a[r][i] /= a[r][c];

		for (int i = r + 1; i < n; i++)
		{
			if (fabs(a[i][c]) > 1e-6)
			{
				for (int j = n; j >= c; j--)
				{
					a[i][j] -= a[r][j] * a[i][c];
				}
			}
		}
		cou();
		r++;
	}
	if (r < n)
	{
		for (int i = r; i < n; i++)
		{
			if (a[i][n] > 1e-6)
				return 1;
		}
		return 2;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			a[i][n] -= a[j][n] * a[i][j];
		}
	}

	return 0;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= n; j++)
			cin >> a[i][j];
	
	int t = gaosi();
	if (t == 0) for (int i = 0; i < n; i++) printf("%.2lf\n", a[i][n]);
	else if (t == 2) cout << "无数解" << endl;
	else cout << "无解" << endl;
	return 0;
}
