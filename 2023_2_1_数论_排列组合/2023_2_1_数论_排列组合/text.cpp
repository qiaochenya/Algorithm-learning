#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 2010;
int c[N][N];

void init()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			if (j == 0) c[i][j] = 1;
			else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
}

int main()
{
	init();
	int n;
	cin >> n;
	while (n--)
	{
		int i, j;
		cin >> i >> j;
		cout << c[i][j] << endl;
	}
	return 0;
}