#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int lowbit(int x)
{
	return x & -x;
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		int count = 0;
		while (x)
		{
			x = x - lowbit(x);
			count++;
		}
		cout << count << " ";
	}
	return 0;
}