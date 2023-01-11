#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
const int N = 100000;
int q[N], n, m;
int main()
{
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		cin >> q[i];
	}
	while (m--)
	{
		int x = 0;
		cin >> x;
		int l = 0, r = n - 1;
		while (l < r)
		{
			int mid = (l + r + 1) >> 1;
			if (q[mid] <= x)
				l = mid;
			else
				r = mid - 1;
		}
		if (x == q[l])
			cout << l << " ";
		else
			cout << -1 << " ";
		l = 0, r = n - 1;
		while (l < r)
		{
			int mid = (l + r) / 2;
			if (q[mid] >= x)
				r = mid;
			else
				l = mid + 1;
		}
		if (x == q[l])
			cout << l << " ";
		else
			cout << -1 << " ";
		cout << "\n";
	}
	return 0;
}