#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;

//拉链法

//const int N = 100003;
//int h[N], e[N], ne[N], idx;
//
//void insert(int x)
//{
//	int k = (x % N + N) % N;	//保证它是正数
//	e[idx] = x;
//	ne[idx] = h[k];
//	h[k] = idx;
//	idx++;	//h[k]其实就是个链尾
//}
//
//bool find(int x)
//{
//	int k = (x % N + N) % N;
//	for (int i = h[k]; i != -1; i = ne[i])
//	{
//		if (e[i] == x)
//			return true;
//	}
//	return false;
//}
//int main()
//{
//	int n;
//	cin >> n;
//
//	memset(h, -1, sizeof(h));
//	while (n--)
//	{
//		int x;
//		char op[2];
//		cin >> op >> x;
//		if (*op == 'I')
//			insert(x);
//		else
//		{
//			if (find(x))
//				cout << "yes" << endl;
//			else
//				cout << "no" << endl;
//		}
//	}
//	return 0;
//}

//开放寻址法

//const int N = 200003, null = 0xf3f3f3f3;
//int h[N];
//
//int find(int x)	//返回x的位置或x应该在的位置
//{
//	int k = (x % N + N) % N;	//保证它是正数
//	while (h[k] != null && h[k] != x)
//	{
//		k++;
//		if (k == N)
//			k = 0;
//	}
//	return k;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	memset(h, 0xf3f3f3f3, sizeof(h));
//	while (n--)
//	{
//		int x, k;
//		char op[2];
//		cin >> op >> x;
//		k = find(x);
//		if (*op == 'I')
//			h[k] = x;
//		else
//		{
//			if (h[k] != null)
//				cout << "yes" << endl;
//			else
//				cout << "no" << endl;
//		}
//	}
//	return 0;
//}

//字符串哈希

typedef unsigned long long ULL;
const int N = 100010, P = 131;
int n, m;
char str[N];
ULL h[N], p[N];

ULL get(int l, int r)
{
	return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
	cin >> n >> m >> str + 1;
	p[0] = 1;	//p的0次方
	for (int i = 1; i <= n; i++)	//从1开始
	{
		p[i] = p[i - 1] * P;	//预处理p的值
		h[i] = h[i - 1] * P + str[i];	//str[i]不是0什么值都可以，不一定要减‘a’
	}
	while (m--)
	{
		int l1, l2, r1, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if (get(l1, r1) == get(l2, r2))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}