#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
using namespace std;
//��������
const int N = 100010, M = N * 2;
bool st[N];
int h[N], e[M], ne[M], idx;
int ans = N, n;
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
//�Żص�ǰ�ڵ������
int dfs(int u)
{
	st[u] = true;	//�������Ͳ�Ҫ����
	int sum = 1, res = 0;	//sun�ǵ�ǰ�ڵ��������res��������Сֵ
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!st[j])
		{
			int s = dfs(j);
			res = max(res, s);
			sum += s;
		}
	}
	res = max(res, n - sum);
	
	ans = min(ans, res);
	return sum;
}

int main()
{
	memset(h, -1, sizeof(h));
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}
