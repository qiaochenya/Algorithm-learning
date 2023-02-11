#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//���򲻵�ʽ

//const int N = 1e5 + 10;
//int n;
//int t[N];
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> t[i];
//	sort(t + 1, t + n + 1);
//	int res = 0;
//	for (int i = 1; i <= n; i++) res += t[i] * (n - i);
//	cout << res << endl;
//	return 0;
//}

//����ѡַ,����ֵ����ʽ

//const int N = 1e5 + 10;
//int n;
//int a[N];
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++) cin >> a[i];
//
//	sort(a, a + n);
//	int res = 0;
//	for (int i = 0; i < n; i++)
//	{
//		res += abs(a[i] - a[n / 2]);
//	}
//	cout << res << endl;
//	return 0;
//}

//�ƹ�ʽ���Ӽ���ţ

//����w[i] + s[i]��С������������Σ��ϵ��һ������С��
const int N = 5e5 + 10;
int n;
pair<int, int>cow[N];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int w, s;
		cin >> w >> s;
		cow[i] = { w + s, s };
	}
	sort(cow, cow + n);
	int res = -2e9, sum = 0;
	for (int i = 0; i < n; i++)
	{
		int w = cow[i].first - cow[i].second, s = cow[i].second;
		res = max(res, sum - s);
		sum += w;
	}
	cout << res << endl;
	return 0;
}