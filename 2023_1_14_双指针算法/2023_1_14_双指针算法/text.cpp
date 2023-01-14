#define _CRT_SECURE_NO_WARNINGS 1
#include<cstring>
#include<iostream>
using namespace std;

//int main()
//{
//	char arr[1000] = { 0 };
//	gets_s(arr);
//	int len = (int)strlen(arr);
//	for (int i = 0; i < len; i++)
//	{
//		int j = i;
//		while (j < len && arr[j] != ' ')
//			j++;
//		for (int k = i; k < j; k++)
//			cout << arr[k];
//		printf("\n");
//		i = j;
//	}
//	return 0;
//}

//最长连续不重复子序列

const int N = 100010;
int a[N], s[N];
int n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int res = 0;
	for (int i = 0, j = 0; i < n; i++)
	{
		s[a[i]]++;
		while (s[a[i]] > 1)
		{
			s[a[j]]--;
			j++;
		}
		if (res < i - j + 1)
			res = i - j + 1;
	}
	cout << res << endl;
	return 0;
}