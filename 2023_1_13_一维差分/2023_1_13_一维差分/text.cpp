#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#define N 100010
int a[N], b[N];
int n, m;

void insert(int l, int r, int c)
{
	b[l] += c;
	b[r + 1] -= c;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		insert(i, i, a[i]);	//b1=a1,b2=a2-a1,b3=a3-a2
	while (m--)
	{
		int l, r, c;
		cin >> l >> r >> c;
		insert(l, r, c);
	}
	for (int i = 1; i <= n; i++)
		b[i] = b[i - 1] + b[i];
	for (int i = 1; i <= n; i++)
		cout << b[i];
	return 0;
}
//6 3
//1 2 2 1 2 1
//1 3 1
//3 5 1
//1 6 1
//345342

//5 1
//1 2 3 4 5
//1 2 1
//2 3 3 4 5