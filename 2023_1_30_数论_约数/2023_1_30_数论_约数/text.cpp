#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

//�Գ�����Լ��

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

//��Լ���ĸ���

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
//	//��Լ��֮��
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

//շת����������Լ��

int get(int a, int b)
{
	return b ? get(b, a % b) : a;
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << get(n, m) << endl;
	return 0;
}