#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#define N 10010
#define M 100010
int n, m;
char p[N], s[M];	//p��С�Ĵ���s�Ǵ�Ĵ�
int ne[N];

int main()
{
	cin >> n >> p >> m >> s;
	ne[0] = 0;	//��ʼ������Ȼ������ǰ��׺���

	for (int i = 1, j = 0; i < n; i++)	//j��ǰ׺ĩβ��i�Ǻ�׺ĩβ��j��Ҫ����ǰ׺�ĳ���
	{
		while (j != 0 && p[i] != p[j])
			j = ne[j - 1];
		if (p[i] == p[j])	//����äĿj++Ҫ�ж�����0
			j++;
		ne[i] = j;
	}

	for (int i = 0, j = 0; i < m; i++)
	{
		while (j != 0 && s[i] != p[j])
			j = ne[j - 1];
		if (s[i] == p[j])
			j++;
		if (j == n)	//�Ѿ��ߵ���ͷ����ƥ��,Ҫ��j����һλ
		{
			cout << i - n + 1<< " ";	
			if(j!=0)
				j = ne[j - 1];
		}
	}
	//��ӡne����
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << ne[i] << " ";
	}
	return 0;
}