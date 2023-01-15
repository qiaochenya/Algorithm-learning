#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
const int N = 100010;
int head, e[N], ne[N], idx;
//初始化
void init()
{
	head = -1;	//指向空节点
	idx = 0;	//表示新节点的下标
}
//添加新节点
void add_to_head(int x)
{
	e[idx] = x;
	ne[idx] = head;
	head = idx;
	idx++;
}
//将在k后面，新插一个点
void add(int k,int x)
{
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx++;
}
//将下标是k的点后面的点删掉
void remove(int k)
{
	ne[k] = ne[ne[k]];
}
int main()
{
	int m;
	cin >> m;
	init();
	while (m--)
	{
		int k, x;
		char op;
		cin >> op;
		if (op == 'H')
		{
			cin >> x;
			add_to_head(x);
		}
		else if (op == 'D')
		{
			cin >> k;
			if (k == 0)	//头是第0个插入的数
				head = ne[head];	//删除头后面的节点
			remove(k - 1);
		}
		else
		{
			cin >> k >> x;
			add(k - 1, x);
		}
	}
	for (int i = head; i != -1; i = ne[i])
	{
		cout << e[i] << " ";
	}
	return 0;
}