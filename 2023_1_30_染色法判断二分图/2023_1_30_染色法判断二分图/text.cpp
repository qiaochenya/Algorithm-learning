#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int n, m;
int color[N];
int h[N], e[N], ne[N], idx;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool dfs(int x, int y)
{
	color[x] = y;
	for (int i = h[x]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (color[j] == 0)
		{
			if (dfs(j, 3 - y) == false)
				return false;
		}
		else if (color[j] == y)
			return false;
	}
	return true;
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof(h));
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}

	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		if (color[i] == 0)
		{
			if (dfs(i, 1) == false)
			{
				flag = false;
				break;
			}
		}
	}

	if (flag == true) cout << "Yes" << endl;
	else cout << "No" << endl;
}