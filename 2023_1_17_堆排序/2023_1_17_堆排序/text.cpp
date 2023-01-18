#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 100010;
int n, m;
int h[N], sizes;
int ph[N], hp[N];
void swap_heap(int a, int b)	//这里的a，b其实是堆里面的下标
{
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}
void down(int x)
{
	int t = x;
	if (x * 2 <= sizes && h[x * 2] < h[t])
		t = x * 2;
	if (x * 2 + 1 <= sizes && h[x * 2 + 1] < h[t])
		t = x * 2 + 1;
	if (t != x)
	{
		swap_heap(x, t);
		down(t);
	}
}
void up(int x)
{
	while (x / 2 > 0 && h[x / 2] > h[x])
	{
		swap_heap(x / 2, x);
		x /= 2;
	}
}
//题目输出最小数

//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//		cin >> h[i];
//	sizes = n;
//	for (int i = n / 2; i; i--)
//	{
//		down(i);
//	}
//	while (m--)
//	{
//		cout << h[1] << " ";
//		h[1] = h[sizes];
//		sizes--;
//		down(1);
//	}
//}

//题目进行多种操作,删除等5种

int main()
{
	int n, m = 0;
	cin >> n;
	while (n--)
	{
		char op[10];
		int x, k;
		cin >> op;
		if (strcmp(op, "I") == 0)
		{
			cin >> x;
			m++;
			sizes++;	//从1开始
			ph[m] = sizes; hp[sizes] = m;
			h[sizes] = x;
			up(sizes);
		}
		else if (strcmp(op, "PM") == 0)
			cout << h[1] << endl;
		else if (strcmp(op, "DM") == 0)
		{
			swap_heap(1, sizes);
			sizes--;
			down(1);
		}
		else if (strcmp(op, "D") == 0)
		{
			cin >> k;
			k = ph[k];
			swap_heap(k, sizes);
			sizes--;
			down(k), up(k);
		}
		else
		{
			cin >> k >> x;
			k = ph[k];
			h[k] = x;
			down(k), up(k);
		}
	}
}