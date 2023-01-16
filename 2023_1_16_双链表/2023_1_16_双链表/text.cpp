#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
const int N = 100010;
int m;
int e[N], l[N], r[N], idx;

//初始化
void init()
{
	l[0] = 0;
	r[1] = 1;
	idx = 2;
}

//在k的后面插入一个节点
void add(int k, int x)
{
	e[idx] = x;
	l[idx] = k;
	r[idx] = r[k];
	l[r[k]] = idx;
	r[k] = idx;	//最后改
	idx++;
}

//删除第k个点
void remove(int k)
{
	r[l[k]] = r[k];
	l[r[k]] = l[k];
}