#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#define N 10010
#define M 100010
int n, m;
char p[N], s[M];	//p是小的串，s是大的串
int ne[N];

int main()
{
	cin >> n >> p >> m >> s;
	ne[0] = 0;	//初始化，必然不会有前后缀相等

	for (int i = 1, j = 0; i < n; i++)	//j是前缀末尾，i是后缀末尾，j还要包含前缀的长度
	{
		while (j != 0 && p[i] != p[j])
			j = ne[j - 1];
		if (p[i] == p[j])	//不能盲目j++要判断跳到0
			j++;
		ne[i] = j;
	}

	for (int i = 0, j = 0; i < m; i++)
	{
		while (j != 0 && s[i] != p[j])
			j = ne[j - 1];
		if (s[i] == p[j])
			j++;
		if (j == n)	//已经走到尽头完美匹配,要让j多走一位
		{
			cout << i - n + 1<< " ";	
			if(j!=0)
				j = ne[j - 1];
		}
	}
	//打印ne数组
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << ne[i] << " ";
	}
	return 0;
}