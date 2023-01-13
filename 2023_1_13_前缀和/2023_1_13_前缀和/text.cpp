#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#define N 100010
int a[N], s[N];
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		printf("%d\n", s[r] - s[l - 1]);
	}
	return 0;
}