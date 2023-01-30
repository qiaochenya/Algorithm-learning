#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int n;
//�Գ����ж�����
bool judge(int n)
{
	for (int i = 2; i <= n / i; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

//�Գ�����������

void zhiyin()
{
	for (int i = 2; i <= n / i; i++)
	{
		if (n % i == 0)
		{
			int cnt = 0;
			while (n % i == 0)
			{
				n /= i;
				cnt++;
			}
			cout << i << " " << cnt << endl;
		}
	}
	if (n > 1) cout << n << " " << 1 << endl;	//1��������
}


int main()
{
	cin >> n;
	cout << "�Ƿ�Ϊ����: " << judge(n) << endl;
	cout << endl << "������" << endl;
	zhiyin();
	return 0;
}

//����ɸѡ���� o(nlogn)

//const int N = 10010;
//int prime[N], cnt;
//bool st[N];
//int n;
//
//void get_prime(int n)
//{
//	for (int i = 2; i <= n; i++)
//	{
//		if (st[i] == false)
//		{
//			prime[cnt++] = i;
//			for (int j = i + i; j <= n; j += i) st[j] = true;	//�����㷨���Ż�ֻɾ�������ı���
//		}
//		
//	}
//}
//
//int main()
//{
//	cin >> n;
//	get_prime(n);
//	cout << "�������� " << cnt << endl;
//	for (int i = 0; i <= cnt - 1; i++) cout << prime[i] << " ";
//	cout << endl;
//}

//����ɸ����

//const int N = 10010;
//int prime[N], cnt;
//bool st[N];
//int n;
//
//void get_prime(int n)
//{
//	for (int i = 2; i <= n; i++)
//	{
//		if (st[i] == false) prime[cnt++] = i;
//		for (int j = 0; prime[j] <= n / i; j++)
//		{
//			st[prime[j] * i] = true;
//			if (i % prime[j] == 0) break;
//		} 
// 	}
//}
//
//int main()
//{
//	cin >> n;
//	get_prime(n);
//	cout << "�������� " << cnt << endl;
//	for (int i = 0; i <= cnt - 1; i++) cout << prime[i] << " ";
//	cout << endl;
//}