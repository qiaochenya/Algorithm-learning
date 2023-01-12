#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
double eps = 1e-6;
int main()
{
	double x = 0;
	scanf_s("%lf", &x);
	double l = 0, r = x;
	for (int i = 0; i <= 100; i++)
	{
		double mid = (l + r) / 2;
		if (mid * mid >= x)
			r = mid;
		else
			l = mid;
	}
	cout << l << endl;
	return 0;
}