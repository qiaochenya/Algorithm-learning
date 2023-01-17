#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//基本用法

//const int N = 100010;
//int n, m;
//int fa[N];
//
//int find(int x)	//找到这个数的祖宗节点 + 路径压缩
//{
//	if (fa[x] != x)	//数根的父节点一定为自己
//	{
//		fa[x] = find(fa[x]);	//压缩
//	}
//	return fa[x];
//
//}
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)	//将每个数的父节点变为自己
//	{
//		fa[i] = i;
//	}
//	while (m--)
//	{
//		int a, b;
//		char op[2];
//		cin >> op >> a >> b;
//		if (op[0] == 'M')
//		{
//			fa[find(a)] = find(b);
//		}
//		else
//		{
//			if (find(a) == find(b))
//			{
//				cout << "yes" << endl;
//			}
//			else
//			{
//				cout << "no" << endl;
//			}
//		}
//	}
//	return 0;
//}

//题目拓展连通块中点的数量

const int N = 100010;
int n, m;
int fa[N], sizes[N];

int find(int x)	//找到这个数的祖宗节点 + 路径压缩
{
	if (fa[x] != x)	//数根的父节点一定为自己
	{
		fa[x] = find(fa[x]);	//压缩
	}
	return fa[x];

}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)	//将每个数的父节点变为自己
	{
		sizes[i] = 1;	//一开始每个块只有自己1
		fa[i] = i;
	}
	while (m--)
	{
		int a, b;
		char op[5];
		scanf("%s", op);
		if (op[0] == 'C')
		{
			cin >> a >> b;
			if (find(a) == find(b))
				continue;
			sizes[find(b)] += sizes[find(a)];
			fa[find(a)] = find(b);
		}
		else if (op[1] == '1')
		{
			cin >> a >> b;
			if (find(a) == find(b))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
		else if (op[1] == '2')
		{
			cin >> a;
			cout << sizes[find(a)] << endl;
		}
	}
	return 0;
}