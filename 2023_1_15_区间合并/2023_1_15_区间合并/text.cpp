#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 100010;
vector<pair<int, int>>a;
int n;
void merge(vector<pair<int, int>>& a)
{
	vector<pair<int, int>>b;
	int l = (int)-2e9, r = (int)-2e9;	//初始应该为负无穷
	for (auto a : a)
	{
		if (r < a.first)	//没有交集更新为下一个区间的l和r
		{
			if (l != -2e9)
				b.push_back({ l,r });
			l = a.first;
			r = a.second;
		}
		else   //有交集就更新一下r
			r = max(r, a.second);
	}
	if (l != -2e9)
		b.push_back({ l,r });
	a = b;	//将合并完的返回去
}
int main()
{
	cin >> n;
	while (n--)
	{
		int l, r;
		cin >> l >> r;
		a.push_back({ l,r });
	}
	sort(a.begin(), a.end());	//第一步按区间左端点排序
	merge(a);
	cout << a.size() << endl;
	return 0;
}