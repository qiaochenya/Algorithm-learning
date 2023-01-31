#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

//试除法求约数

//int n;
//
//vector<int>get_divisor(int n)
//{
//	vector<int>res;
//	for (int i = 1; i <= n / i; i++)
//	{
//		if (n % i == 0)
//		{
//			res.push_back(i);
//			if (i != n / i)
//				res.push_back(n / i);
//		}
//	}
//	sort(res.begin(), res.end());
//	return res;
//
//}
//
//int main()
//{
//	cin >> n;
//	vector<int>res = get_divisor(n);
//	for (auto t : res) cout << t << " ";
//	cout << endl;
//	return 0;
//}

//求约数的个数

//int main()
//{
//	int n;
//	cin >> n;
//	unordered_map<int, int> primes;
//	for (int i = 2; i <= n / i; i++)
//	{
//		if (n % i == 0)
//		{
//			int s = 0;
//			while (n % i == 0)
//			{
//				n /= i;
//				s++;
//			}
//			primes[i] += s;
//		}
//		if (n > 1) primes[n]++;
//	}
//
//	int res = 1;
//	for (auto t : primes) res = res * (t.second + 1);
//	cout << res << endl << endl;
//
//	//求约数之和
//	int ans = 1;
//	for (auto t : primes)
//	{
//		int p = t.first, a = t.second;
//		int q = 1;
//		while (a--)
//		{
//			q = (q * p) + 1;
//		}
//		ans = ans * q;
//	}
//	cout << ans << endl;
//}

//辗转相除法求最大公约数

//int get(int a, int b)
//{
//	return b ? get(b, a % b) : a;
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	cout << get(n, m) << endl;
//	return 0;
//}

//欧几里得算法的拓展求a * x + b * y = d 中的x和y

//int exgcd(int a, int b, int &x, int &y)
//{
//	if (b == 0)
//	{
//		x = 1, y = 0;
//		return a;
//	}
//	int t = exgcd(b, a % b, y, x);
//	y = y - (a / b) * x;
//	return t;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		int a, b;
//		int x = 0, y = 0;
//		cin >> a >> b;
//		exgcd(a, b, x, y);
//		cout << x << " " << y << endl;
//	}
//	return 0;
//}


//线性同余方程

int exgcd(int a, int b, int& x, int& y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	int t = exgcd(b, a % b, y, x);
	y = y - a / b * x;
	return t;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a, b, m;
		cin >> a >> b >> m;
		int x = 0, y = 0;
		int d = exgcd(a, m, x, y);
		if (b % d != 0) cout << "impossible" << endl;
		else cout << x * (b / d) % m << endl;
	}
	return 0;
}

