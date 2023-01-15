#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n, m;
#define N 300010
int a[N], s[N];	//s[N]是前缀和数组
vector<pair<int, int>>add, ask;
vector<int>alls;

//unique函数的实现

vector<int>::iterator unique(vector<int>& a)
{
	int j = 0;
	for (int i = 0; i < a.size(); i++)
		if (!i || a[i] != a[i - 1])
			a[j++] = a[i];
	return a.begin() + j;
}

int find(int x)
{
	int l = 0, r = (int)alls.size() - 1;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (x <= alls[mid])
			r = mid;
		else
			l = mid + 1;
	}
	return r + 1;
}
int main()
{
	cin >> n >> m;
	//读入操作
	while (n--)
	{
		int x, c;
		cin >> x >> c;
		alls.push_back(x);
		add.push_back({ x,c });
	}
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		alls.push_back(l);
		alls.push_back(r);
		ask.push_back({ l,r });
	}
	//去重,将大的小标去重 
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls), alls.end());
	//将数据插入
	for (auto item : add)
	{
		int x = find(item.first);	//把大下标映射成小下标
		a[x] += item.second;
	}
	//前缀和的处理
	int len = sizeof(a) / sizeof(a[0]);	//求长度
	for (int i = 1; i < len; i++)
		s[i] = s[i - 1] + a[i];	//前缀和方便都是从1开始
	for (auto item : ask)
	{
		int l = find(item.first);
		int r = find(item.second);
		cout << s[r] - s[l - 1] << endl;
	}
	return 0;
}