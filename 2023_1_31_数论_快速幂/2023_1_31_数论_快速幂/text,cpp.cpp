#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//������a ^ k % p

//long long int qmi(int a, int k, int p)
//{
//	long long int res = 1;
//	while (k != 0)
//	{
//		if ((k & 1) == 1) res = res * a % p;
//		k = k >> 1;
//		a = a * a % p;
//	}
//	return res;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		int a, k, p;
//		cin >> a >> k >> p;
//		cout << qmi(a, k, p) << endl;
//	}
//	return 0;
//}

//����Ԫ,���ҽ���p�����������ÿ���������

long long int qmi(int a, int k, int p)
{
	long long int res = 1;
	while (k != 0)
	{
		if ((k & 1) == 1) res = res * a % p;
		k = k >> 1;
		a = a * a % p;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a, p;
		cin >> a >> p;
		if (a % p == 0) cout << "impossible" << endl;
		else cout << qmi(a, p - 2, p) << endl;
	}
	return 0;
}

