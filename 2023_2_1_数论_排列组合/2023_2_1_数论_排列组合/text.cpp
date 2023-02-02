#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

//1.应对a,b数据范围小的

//const int N = 2010;
//int c[N][N];
//
//void init()
//{
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j <= i; j++)
//			if (j == 0) c[i][j] = 1;
//			else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
//}
//
//int main()
//{
//	init();
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		int i, j;
//		cin >> i >> j;
//		cout << c[i][j] << endl;
//	}
//	return 0;
//}

//2.应对a,b数据范围大的

//const int N = 1e5 + 10, mod = 1e9 + 7;
//int fact[N], infact[N];
//
//int qmi(int a, int b, int m)
//{
//	int res = 1;
//	while (b != 0)
//	{
//		if ((b & 1) == 1) res = (long long)res * a % m;
//		b >>= 1;
//		a = (long long)a * a % m;
//	}
//	return res;
//}
//
//void init()
//{
//	fact[0] = infact[0] = 1;
//	for (int i = 1; i < N; i++)
//	{
//		fact[i] = (long long int)fact[i - 1] * i % mod;
//		infact[i] = (long long int)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
//	}
//}
//
//int main()
//{
//	init();
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		int a, b;
//		cin >> a >> b;
//		cout << (long long)fact[a] * infact[a - b] % mod * infact[b] % mod << endl;
//	}
//	return 0;
//}

//3.应对a,b数据极大，且p较小运用卢卡斯定理


//int p;
//
//int qmi(long long int a, long long int k)
//{
//	int res = 1;
//	while (k != 0)
//	{
//		if ((k & 1) == 1) res = (long long)res * a % p;
//		k >>= 1;
//		a = (long long)a * a % p;
//	}
//	return res;
//}
//
//int c(int n, int m)
//{
//	int res = 1;
//	for (int i = 1, j = n; i <= m; i++, j--)
//	{
//		res = (long long)res * j % p;
//		res = (long long)res * qmi(i, p - 2) % p;
//	}
//	return res;
//}
//
//int lukasi(int n, int m)
//{
//	if (n < p && m < p) return c(n, m);
//	else return (long long)c(n % p, m % p) * lukasi(n / p, m / p);
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		int n, m;
//		cin >> n >> m >> p;
//		cout << lukasi(n, m) << endl;
//	}
//	return 0;
//}

//4.应对不能模一个数，求真实值

const int N = 2010;
int prime[N], sum[N], cnt;
bool st[N];

void get_prime(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (st[i] == false) prime[cnt++] = i;	
		for (int j = 0; prime[j] <= n / i; j++)
		{
			st[prime[j] * i] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

int get(int n, int p)
{
	int res = 0;
	while (n != 0)
	{
		res += n / p;
		n /= p;
	}
	return res;
}

vector<int>mul(vector<int>a, int b)
{
	vector<int>c;
	int t = 0;
	for (int i = 0; i < (int)a.size(); i++)
	{
		t += a[i] * b;
		c.push_back(t % 10);
		t /= 10;
	}
	while (t != 0)
	{
		c.push_back(t % 10);
		t /= 10;
	}
	return c;
}

int main()
{
	int n, m;
	cin >> n >> m;
	get_prime(n);

	for (int i = 0; i < cnt; i++)
	{
		int p = prime[i];
		sum[i] = get(n, p) - get(m, p) - get(n - m, p);
	}
	vector<int>res;
	res.push_back(1);

	for (int i = 0; i < cnt; i++)
		for (int j = 0; j < sum[i]; j++)
			res = mul(res, prime[i]);

	for (int i = (int)res.size() - 1; i >= 0; i--)
		cout << res[i];
	cout << endl;
	return 0;
}