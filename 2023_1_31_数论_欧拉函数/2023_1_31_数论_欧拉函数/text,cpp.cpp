#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//求欧拉函数，套公式
//res / i * (i - 1)

//int main()
//{
//	int x;
//	cin >> x;
//	int res = x;
//	for (int i = 2; i <= x / i; i++)
//	{
//		if (x % i == 0)
//		{
//			res = res / i * (i - 1);	//防止小数
//			while (x % i == 0) x /= i;
//		}
//	}
//	if (x > 1) res = res / x * (x - 1);
//	cout << res << endl;
//}

//线性筛欧拉函数

const int N = 100010;
int prime[N], cnt;
bool st[N];
int oula[N];

long long int get_oula(int n)
{
	oula[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (st[i] == false)
		{
			prime[cnt++] = i;
			oula[i] = i - 1;
		}
		for (int j = 0; prime[j] <= n / i; j++)
		{
			st[prime[j] * i] = true;
			if (i % prime[j] == 0)
			{
				oula[prime[j] * i] = prime[j] * oula[i];
				break;
			}
			oula[prime[j] * i] = (prime[j] - 1) * oula[i];
		}
	}
	long long int res = 0;
	for (int i = 1; i <= n; i++) res += oula[i];
	return res;
}

int main()
{
	int n;
	cin >> n;
	cout << get_oula(n) << endl;
	return 0;
}