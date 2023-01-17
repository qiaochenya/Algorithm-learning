#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//题目找到左边离它最近的数在哪将数字输出否则，输出-1

//const int N = 100010;
//int stk[N], tt;
//int n;
//
//int main()
//{
//	cin >> n;
//	while (n--)
//	{
//		int x;
//		cin >> x;
//		while (tt != 0 && stk[tt] >= x)	//全局变量tt一开始是0
//			tt--;	//如果一直找不到就tt就到0
//		if (tt != 0)
//			cout << stk[tt] << " ";
//		else
//			cout << -1 << " ";	//位置到0就是没找到
//
//		stk[++tt] = x;	//入栈
//	}
//	return 0;
//}

//题目滑动窗口，找一个大小为k的窗口中最小和最大的数

//暴力做法,求最大值，会超时

//int n, k;
//const int N = 1000010;
//int a[N];
//vector<int>coun;
//int search(int l, int r, int b[])
//{
//	int max = 0;
//	while (l <= r)
//	{
//		if (r - l + 1 == k)
//			max = b[l];
//		else
//			if (max < b[l])
//				max = b[l];
//		l++;
//	}
//	return max;
//}
//int main()
//{
//	cin >> n >> k;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	int l = 0, r = k - 1;
//	while (r <= n - 1)
//	{
//		coun.push_back(search(l, r, a));
//		l++;
//		r++;
//	}
//	for (auto i = coun.begin(); i < coun.end(); i++)
//		cout << *i << " ";
//	return 0;
//}

int n, k;
const int N = 1000010;
int a[N], q[N];
int main()
{
	scanf_s("%d%d", &n, &k);
	/*for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);*/
	int hh = 0, tt = -1;

	for (int i = 0; i < n; i++)
	{
		//首先判断是否队首不在窗口内
		if (hh <= tt && i - k + 1 > q[hh])
			hh++;
		while (hh <= tt && a[q[tt]] >= a[i])
			tt--;
		q[++tt] = i;
		if (i >= k - 1)
			cout << a[q[hh]] << " ";
	}
	cout << "\n";
	
	hh = 0, tt = -1;
	for (int i = 0; i < n; i++)
	{
		if (hh <= tt && i - k + 1 > q[hh])
			hh++;
		while (hh <= tt && a[q[tt]] <= a[i])
			tt--;
		q[++tt] = i;
		if (i >= k - 1)
			cout << a[q[hh]] << " ";
	}
	return 0;
}


//for (int i = 0; i < n; i++)
//{
//	int x;
//	cin >> x;
//	if (hh <= tt && hh < i - k + 1)
//		hh++;
//	while (hh <= tt && x <= q[tt])
//		tt--;
//	q[++tt] = x;
//	if (i >= k - 1)
//		cout << q[hh] << " ";
//}

//for (int i = 0; i < n; i++)
//{
//	//首先判断是否队首不在窗口内
//	if (hh <= tt && i - k + 1 > q[hh])
//		hh++;
//	while (hh <= tt && a[q[tt]] >= a[i])
//		tt--;
//	q[++tt] = i;
//	if (i >= k - 1)
//		cout << a[q[hh]] << " ";
//}