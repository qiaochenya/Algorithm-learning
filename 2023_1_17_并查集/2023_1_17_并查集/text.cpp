#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//�����÷�

//const int N = 100010;
//int n, m;
//int fa[N];
//
//int find(int x)	//�ҵ�����������ڽڵ� + ·��ѹ��
//{
//	if (fa[x] != x)	//�����ĸ��ڵ�һ��Ϊ�Լ�
//	{
//		fa[x] = find(fa[x]);	//ѹ��
//	}
//	return fa[x];
//
//}
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)	//��ÿ�����ĸ��ڵ��Ϊ�Լ�
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

//��Ŀ��չ��ͨ���е������

const int N = 100010;
int n, m;
int fa[N], sizes[N];

int find(int x)	//�ҵ�����������ڽڵ� + ·��ѹ��
{
	if (fa[x] != x)	//�����ĸ��ڵ�һ��Ϊ�Լ�
	{
		fa[x] = find(fa[x]);	//ѹ��
	}
	return fa[x];

}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)	//��ÿ�����ĸ��ڵ��Ϊ�Լ�
	{
		sizes[i] = 1;	//һ��ʼÿ����ֻ���Լ�1
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