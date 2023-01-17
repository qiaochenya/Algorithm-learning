#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
const int N = 100010;
int son[N][26], cnt[N], idx;
char str[N];
// 0号点既是根节点，又是空节点
// son[][]存储树中每个节点的子节点
// cnt[]存储以每个节点结尾的单词数量

void insert(char str[])
{
	int p = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		int u = str[i] - 'a';
		if (son[p][u] == 0)
			son[p][u] = ++idx;
		p = son[p][u];
	}
	cnt[p]++;
}
int query(char str[])
{
	int p = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		int u = str[i] - 'a';
		if (son[p][u] == 0)
			return 0;
		else
			p = son[p][u];
	}
	return cnt[p];
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		char op[2];
		cin >> op;
		cin >> str;
		if (op[0] == 'I')
			insert(str);
		else
			cout << query(str) << endl;
	}
	return 0;
}