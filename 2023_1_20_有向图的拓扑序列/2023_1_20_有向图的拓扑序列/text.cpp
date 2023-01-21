#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
using namespace std;
const int N = 100010;
int n, m;	//n�ǵ�����m�Ǳ���
int e[N], ne[N], h[N], idx;
int q[N], d[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool topsort()
{
	int hh = 0, tt = -1;
	//�Ȱ����Ϊ0�ĵ�ӽ���
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 0)
			q[++tt] = i;
	}
	//������չ
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			d[j]--;
			if (d[j] == 0)
				q[++tt] = j;
		}
	}
	return tt == n - 1;	//�����Ǵ�0��ʼ,tt == n - 1����ͼ�Ѿ���������
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof(h));
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		d[b] += 1;
	}
	if (topsort())
	{
		for (int i = 0; i < n; i++)
			cout << q[i] << " ";
		cout << endl;
	}
	else
		cout << -1 << endl;
	return 0;
}