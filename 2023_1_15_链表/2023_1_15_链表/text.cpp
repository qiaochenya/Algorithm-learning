#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
const int N = 100010;
int head, e[N], ne[N], idx;
//��ʼ��
void init()
{
	head = -1;	//ָ��սڵ�
	idx = 0;	//��ʾ�½ڵ���±�
}
//����½ڵ�
void add_to_head(int x)
{
	e[idx] = x;
	ne[idx] = head;
	head = idx;
	idx++;
}
//����k���棬�²�һ����
void add(int k,int x)
{
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx++;
}
//���±���k�ĵ����ĵ�ɾ��
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
			if (k == 0)	//ͷ�ǵ�0���������
				head = ne[head];	//ɾ��ͷ����Ľڵ�
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