#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;
//Nim游戏

//int main()
//{
//	int n;
//	cin >> n;
//	int res = 0;
//	while (n--)
//	{
//		int x;
//		cin >> x;
//		res ^= x;
//	}
//	if (res) cout << "yes" << endl;
//	else cout << "no" << endl;
//	return 0;
//}

//Nim游戏,集合——sg函数

const int N = 110, M = 10010;
int s[N], sg[M];
int n, m;

int get_sg(int x)
{
	if (sg[x] != -1) return sg[x];
	unordered_set<int> S;
	for (int i = 0; i < n; i++)
	{
		int number = s[i];
		if (number <= x) S.insert(get_sg(x - number));
	}
	for (int i = 0;; i++)
	{
		if (S.count(i) == 0) return sg[x] = i;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	memset(sg, -1, sizeof(sg));
	cin >> m;
	int res = 0;
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		res ^= get_sg(x);
	}
	if (res) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}