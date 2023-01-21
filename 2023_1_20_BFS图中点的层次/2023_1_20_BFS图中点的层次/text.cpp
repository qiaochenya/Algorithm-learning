#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
using namespace std;
//��Ŀn����m���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի������б߳�����1����ı����1~n
//�������1�ŵ㵽n�ŵ�ľ��룬�޷��ߵ������-1
const int N = 100010;
int q[N], d[N];
int n, m;
int h[N], e[N], ne[N], idx;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs()
{
	int hh = 0, tt = 0;
	q[0] = 1;
	d[1] = 0;	//��һ����
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (d[j] == -1)	//��ֹ�رߺ��Ի�
			{
				d[j] = d[t] + 1;
				q[++tt] = j;
			}
		}
	}
	return d[n];
}

int main()
{
	//n�ǵ㣬m�Ǳ���
	cin >> n >> m;
	memset(h, -1, sizeof(h));
	memset(d, -1, sizeof(d));	//��Ϊ�Ҳ���·�������-1
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	cout << bfs() << endl;
	return 0;
}