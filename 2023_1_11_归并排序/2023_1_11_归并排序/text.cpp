#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int n;
int q[1000000];
int tmp[1000000];
void merge_sort(int q[], int l, int r)
{
	if (l >= r)
		return;
	int mid = (l + r) / 2;
	merge_sort(q, l, mid);
	merge_sort(q, mid + 1, r);
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r)
	{
		if (q[i] <= q[j])
		{
			tmp[k] = q[i];
			k++;
			i++;
		}
		else
			tmp[k++] = q[j++];
	}
	while (i <= mid)
		tmp[k++] = q[i++];
	while (k <= r)
		tmp[k++] = q[j++];
	for (i = l, j = 0; i <= r; i++, j++)
		q[i] = tmp[j];
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> q[i];
	}
	merge_sort(q, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << q[i] << " ";
	}
	return 0;
}