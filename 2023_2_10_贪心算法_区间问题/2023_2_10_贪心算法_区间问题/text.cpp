#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
//区间选点

//const int N = 1e5 + 10;
//
//struct Interval
//{
//	int l, r;
//}interval[N];
//
//bool cmp(Interval a, Interval b)
//{
//	return a.r < b.r;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int l, r;
//		cin >> l >> r;
//		interval[i] = { l, r };
//	}
//
//	sort(interval, interval + n, cmp);
//
//	int res = 0, ed = -2e9;
//	for (int i = 0; i < n; i++)
//	{
//		if (interval[i].l > ed)
//		{
//			ed = interval[i].r;
//			res++;
//		}
//	}
//	cout << res << endl;
//	return 0;
//}

//最大不相交区间个数

//const int N = 1e5 + 10;
//int n;
//struct Range
//{
//	int l, r;
//	bool operator <(const Range& w)const
//	{
//		return r < w.r;
//	}
//}range[N];
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int l, r;
//		cin >> l >> r;
//		range[i] = { l, r };
//	}
//	sort(range, range + n);
//	int res = 0, ed = -2e9;
//	for (int i = 0; i < n; i++)
//	{
//		if (ed < range[i].l)
//		{
//			ed = range[i].r;
//			res++;
//		}
//	}
//	cout << res << endl;
//	return 0;
//}

//区间分组

const int N = 1e5 + 10;
int n;
struct Range
{
	int l, r;
	bool operator < (const Range& w)const
	{
		return l < w.l;
	}
}range[N];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		range[i] = { l,r };
	}
	sort(range, range + n);

	priority_queue<int, vector<int>, greater<int>> heap;
	for (int i = 0; i < n; i++)
	{
		if (heap.empty() || heap.top() >= range[i].l) heap.push(range[i].r);
		else
		{
			heap.pop();
			heap.push(range[i].r);
		}
	}
	cout << heap.size() << endl;
	return 0;
}