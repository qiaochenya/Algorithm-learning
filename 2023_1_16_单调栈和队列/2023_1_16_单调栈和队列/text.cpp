#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//��Ŀ�ҵ������������������Ľ���������������-1

//const int N = 100010;
//int stk[N], tt;
//int n;
//
//int main()
//{
//	cin >> n;
//	while (n--)
//	{
//		int x;
//		cin >> x;
//		while (tt != 0 && stk[tt] >= x)	//ȫ�ֱ���ttһ��ʼ��0
//			tt--;	//���һֱ�Ҳ�����tt�͵�0
//		if (tt != 0)
//			cout << stk[tt] << " ";
//		else
//			cout << -1 << " ";	//λ�õ�0����û�ҵ�
//
//		stk[++tt] = x;	//��ջ
//	}
//	return 0;
//}

//��Ŀ�������ڣ���һ����СΪk�Ĵ�������С��������

int n, k;
const int N = 1000010;
int a[N], q[N];
int main()
{
	scanf_s("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	int hh = 0, tt = -1;
	for (int i = 0; i < n; i++)
	{
		//�����ж��Ƿ���ײ��ڴ�����
		if (hh <= tt && i - k + 1 > q[hh])
			hh++;
		while (hh <= tt && a[q[tt]] >= a[i])
			tt--;
		q[++tt] = i;
		if (i >= k - 1)
			cout << a[q[hh]] << " ";
	}
	cout << "\n";
	
	hh = 0, tt = -1;
	for (int i = 0; i < n; i++)
	{
		if (hh <= tt && i - k + 1 > q[hh])
			hh++;
		while (hh <= tt && a[q[tt]] <= a[i])
			tt--;
		q[++tt] = i;
		if (i >= k - 1)
			cout << a[q[hh]] << " ";
	}
	return 0;
}


//for (int i = 0; i < n; i++)
//{
//	int x;
//	cin >> x;
//	if (hh <= tt && hh < i - k + 1)
//		hh++;
//	while (hh <= tt && x <= q[tt])
//		tt--;
//	q[++tt] = x;
//	if (i >= k - 1)
//		cout << q[hh] << " ";
//}

//for (int i = 0; i < n; i++)
//{
//	//�����ж��Ƿ���ײ��ڴ�����
//	if (hh <= tt && i - k + 1 > q[hh])
//		hh++;
//	while (hh <= tt && a[q[tt]] >= a[i])
//		tt--;
//	q[++tt] = i;
//	if (i >= k - 1)
//		cout << a[q[hh]] << " ";
//}