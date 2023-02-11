#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
//����ѡ��

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

//����ཻ�������

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

//�������

//const int N = 1e5 + 10;
//int n;
//struct Range
//{
//	int l, r;
//	bool operator < (const Range& w)const
//	{
//		return l < w.l;
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
//		range[i] = { l,r };
//	}
//	sort(range, range + n);
//
//	priority_queue<int, vector<int>, greater<int>> heap;
//	for (int i = 0; i < n; i++)
//	{
//		if (heap.empty() || heap.top() >= range[i].l) heap.push(range[i].r);
//		else
//		{
//			heap.pop();
//			heap.push(range[i].r);
//		}
//	}
//	cout << heap.size() << endl;
//	return 0;
//}

//���串��

//const int N = 1e5 + 10;
//int n, st, ed;
//struct Range
//{
//	int l, r;
//	bool operator <(const Range& w)const
//	{
//		return l < w.l;
//	}
//}range[N];
//
//int main()
//{
//	cin >> st >> ed;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int l, r;
//		cin >> l >> r;
//		range[i] = { l,r };
//	}
//	sort(range, range + n);
//
//	bool succese = false;
//	int res = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int j = i, r = (int)-2e9;
//		while (j < n && range[j].l <= st)
//		{
//			r = max(r, range[j].r);
//			j++;
//		}
//		if (r < st)
//		{
//			res = -1;
//			break;
//		}
//		res++;
//		if (r >= ed)
//		{
//			succese = true;
//			break;
//		}
//		i = j - 1;
//		st = r;
//	}
//	if (succese == false) cout << -1 << endl;
//	else cout << res << endl;
//	return 0;
//}

//�ϲ�����

int main()
{
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>>heap;
	while (n--)
	{
		int x;
		cin >> x;
		heap.push(x);
	}
	int res = 0;
	while (heap.size() > 1)
	{
		int a = heap.top(); 
		heap.pop();
		int b = heap.top();
		heap.pop();
		res += a + b;
		heap.push(a + b);
	}
	cout << res << endl;
	return 0;
}