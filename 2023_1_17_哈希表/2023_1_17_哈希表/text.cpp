#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;

//������

//const int N = 100003;
//int h[N], e[N], ne[N], idx;
//
//void insert(int x)
//{
//	int k = (x % N + N) % N;	//��֤��������
//	e[idx] = x;
//	ne[idx] = h[k];
//	h[k] = idx;
//	idx++;	//h[k]��ʵ���Ǹ���β
//}
//
//bool find(int x)
//{
//	int k = (x % N + N) % N;
//	for (int i = h[k]; i != -1; i = ne[i])
//	{
//		if (e[i] == x)
//			return true;
//	}
//	return false;
//}
//int main()
//{
//	int n;
//	cin >> n;
//
//	memset(h, -1, sizeof(h));
//	while (n--)
//	{
//		int x;
//		char op[2];
//		cin >> op >> x;
//		if (*op == 'I')
//			insert(x);
//		else
//		{
//			if (find(x))
//				cout << "yes" << endl;
//			else
//				cout << "no" << endl;
//		}
//	}
//	return 0;
//}

//����Ѱַ��

//const int N = 200003, null = 0xf3f3f3f3;
//int h[N];
//
//int find(int x)	//����x��λ�û�xӦ���ڵ�λ��
//{
//	int k = (x % N + N) % N;	//��֤��������
//	while (h[k] != null && h[k] != x)
//	{
//		k++;
//		if (k == N)
//			k = 0;
//	}
//	return k;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	memset(h, 0xf3f3f3f3, sizeof(h));
//	while (n--)
//	{
//		int x, k;
//		char op[2];
//		cin >> op >> x;
//		k = find(x);
//		if (*op == 'I')
//			h[k] = x;
//		else
//		{
//			if (h[k] != null)
//				cout << "yes" << endl;
//			else
//				cout << "no" << endl;
//		}
//	}
//	return 0;
//}

//�ַ�����ϣ

typedef unsigned long long ULL;
const int N = 100010, P = 131;
int n, m;
char str[N];
ULL h[N], p[N];

ULL get(int l, int r)
{
	return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
	cin >> n >> m >> str + 1;
	p[0] = 1;	//p��0�η�
	for (int i = 1; i <= n; i++)	//��1��ʼ
	{
		p[i] = p[i - 1] * P;	//Ԥ����p��ֵ
		h[i] = h[i - 1] * P + str[i];	//str[i]����0ʲôֵ�����ԣ���һ��Ҫ����a��
	}
	while (m--)
	{
		int l1, l2, r1, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if (get(l1, r1) == get(l2, r2))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}