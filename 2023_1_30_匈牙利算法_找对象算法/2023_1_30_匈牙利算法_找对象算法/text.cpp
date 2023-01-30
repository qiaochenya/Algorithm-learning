#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 114514;
int n1, n2, m;
int h[N], ne[N], e[N], idx;
int match[N];	//存女生的对象
bool st[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool find(int x)
{
	for (int i = h[x]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (st[j] == false)
		{
			st[j] = true;
			if (match[j] == 0 || find(match[j]) == true)
			{
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	cin >> n1 >> n2 >> m;
	memset(h, -1, sizeof(h));
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}

	int res = 0;

	for (int i = 1; i <= n1; i++)
	{
		memset(st, false, sizeof(st));
		if (find(i) == true) res++;
	}
	cout << res << endl;
	return 0;
}