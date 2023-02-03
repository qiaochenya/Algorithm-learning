#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 20;
int prime[N];
int n, m;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> prime[i];

	int res = 0;
	for (int i = 1; i < (1 << m); i++)
	{
		int t = 1, cnt = 0;
		for (int j = 0; j < m; j++)
		{
			if (i >> j & 1)
			{
				cnt++;
				if ((long long)prime[j] * t > n)
				{
					t = -1;
					break;
				}
				t *= prime[j];
			}
		}
		if (t != -1)
		{
			if (cnt % 2 == 0) res -= n / t;
			else res += n / t;
		}
	}
	cout << res << endl;
	return 0;
}