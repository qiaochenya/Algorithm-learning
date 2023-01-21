#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//快速选择，快排的拓展

//const int N = 100010;
//int n, k;
//int q[N];
////递归后就两种情况i == j和i = j + 1
//int quick_sort(int l, int r, int k)
//{
//	if (l == r) return q[l];	//快速选择和归并排序可以==，而快排不可以只能>=
//	int x = q[l], i = l - 1, j = r + 1;
//	while (i < j)
//	{
//		do i++; while (x > q[i]);
//		do j--; while (x < q[j]);
//		if (i < j) swap(q[i], q[j]);
//	}
//	int sl = j - l + 1;	//左边的个数
//	if (k <= sl) return quick_sort(l, j, k);
//	return quick_sort(j + 1, r, k - sl);
//}
//int main()
//{
//	cin >> n >> k;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> q[i];
//	}
//	cout << quick_sort(0, n - 1, k) << endl;
//	return 0;
//}

//逆序对的数量，归并的应用

//int n;
//const int N = 100010;
//int q[N], tmp[N];
//
//long long int merge_sort(int l, int r)
//{
//	if (l == r) return 0;
//	int mid = (l + r) >> 1;
//	long long int res = merge_sort(l, mid) + merge_sort(mid + 1, r);
//	int k = 0, i = l, j = mid + 1;
//	while (i <= mid && j <= r)
//	{
//		if (q[i] <= q[j])
//			tmp[k++] = q[i++];
//		else
//		{
//			tmp[k++] = q[j++];
//			//那个数大过后面的数也一定大过
//			res += mid - i + 1;
//		}
//	}
//	//收尾
//	while (i <= mid) tmp[k++] = q[i++];
//	while (j <= r) tmp[k++] = q[j++];
//	for (int i = l, j = 0; i <= r; i++, j++)
//	{
//		q[i] = tmp[j];
//	}
//	return res;
//}
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> q[i];
//	}
//	cout << merge_sort(0, n - 1) << endl;
//}

//数的3次方根

//int main()
//{
//	double x;
//	cin >> x;
//	double l = -10000, r = 10000;
//	while (r - l > 1e-8)
//	{
//		double mid = (r + l) / 2;
//		if (mid * mid * mid >= x) r = mid;
//		else l = mid;
//	}
//	//cout << l << endl;	//不自己保留6位小数
//	printf("%lf", l);
//}

//一维前缀和,主要注意从1开始

//const int N = 100010;
//int n, m;
//int a[N], s[N];
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		s[i] = s[i - 1] + a[i];
//	}
//	while (m--)
//	{
//		int l, r;
//		cin >> l >> r;
//		cout << s[r] - s[l - 1] << endl;
//	}
//	return 0;
// }

//二维矩阵

const int N = 1010;
int a[N][N], s[N][N];
int n, m, k;
int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];

	while (k--)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
	}
	return 0;
}