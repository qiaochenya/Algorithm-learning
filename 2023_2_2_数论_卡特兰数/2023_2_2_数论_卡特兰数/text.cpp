#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

int qmi(int a, int k, int p)
{
	int res = 1;
	while (k)
	{
		if (k & 1) res = (long long)res * a % p;
		k >>= 1;
		a = (long long)a * a % p;
	}
	return res;
}

int main()
{
	int a;
	cin >> a;
	int n = 2 * a, m = a;
	int res = 1;
	for (int i = n; i >= n - m + 1; i--) res = (long long)res * i % mod;
	for (int i = m; i >= 1; i--) res = (long long)res * qmi(i, mod - 2, mod) % mod;
	res = (long long)res * qmi(a + 1, mod - 2, mod) % mod;
	cout << res << endl;
	return 0;
}