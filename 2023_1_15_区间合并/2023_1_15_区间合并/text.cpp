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
	int l = (int)-2e9, r = (int)-2e9;	//��ʼӦ��Ϊ������
	for (auto a : a)
	{
		if (r < a.first)	//û�н�������Ϊ��һ�������l��r
		{
			if (l != -2e9)
				b.push_back({ l,r });
			l = a.first;
			r = a.second;
		}
		else   //�н����͸���һ��r
			r = max(r, a.second);
	}
	if (l != -2e9)
		b.push_back({ l,r });
	a = b;	//���ϲ���ķ���ȥ
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
	sort(a.begin(), a.end());	//��һ����������˵�����
	merge(a);
	cout << a.size() << endl;
	return 0;
}