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

//const int N = 1010;
//int a[N][N], s[N][N];
//int n, m, k;
//int main()
//{
//	cin >> n >> m >> k;
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++)
//			cin >> a[i][j];
//
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++)
//			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
//
//	while (k--)
//	{
//		int x1, x2, y1, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
//	}
//	return 0;
//}

//一维差分

//int n, m;
//const int N = 100010;
//int a[N], s[N];
//
//void insert(int l, int r, int k)
//{
//	s[l] += k;
//	s[r + 1] -= k;
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		int x;
//		cin >> x;
//		a[i] = x;
//		insert(i, i, x);
//	}
//	while (m--)
//	{
//		int l, r, k;
//		cin >> l >> r >> k;
//		insert(l, r, k);
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		a[i] = a[i - 1] + s[i];
//		cout << a[i] << ' ';
//	}
//	return 0;
//}

//二维差分

//const int N = 1010;
//int n, m, q;
//int a[N][N], b[N][N];
//
//void insert(int x1, int y1, int x2, int y2, int k)
//{
//	b[x1][y1] += k;
//	b[x1][y2 + 1] -= k;
//	b[x2 + 1][y1] -= k;
//	b[x2 + 1][y2 + 1] += k;
//}
//int main()
//{
//	cin >> n >> m >> q;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			int x;
//			cin >> x;
//			a[i][j] = x;
//			insert(i, j, i, j, x);
//		}
//	}
//	while (q--)
//	{
//		int x1, x2, y1, y2, k;
//		cin >> x1 >> y1 >> x2 >> y2 >> k;
//		insert(x1, y1, x2, y2, k);
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + b[i][j];
//			cout << a[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}

//数组元素之和，两个数组都是有序的，找一个数组其中一个元素和另一个数组其中一个元素加起来等于x

//const int N = 100010;
//int n, m, k;
//int a[N], b[N];
//
//int main()
//{
//	cin >> n >> m >> k;
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	for (int i = 0; i < m; i++)
//		cin >> b[i];
//	for (int i = 0, j = m - 1; i < n; i++)
//	{
//		while (j >= 0 && a[i] + b[j] > k)
//		{
//			j--;
//		}
//		if (a[i] + b[j] == k)
//		{
//			cout << i << " " << j << endl;
//			break;
//		}
//	}
//	return 0;
//}

//双链表

//const int N = 100010;
//int l[N], r[N], e[N], idx;
//int n;
//
//void init()	//0是左边的点，1是右边的点
//{
//	r[0] = 1;
//	l[1] = 0;
//	idx = 2;
//}
//
//void add(int k, int x)	//插入的核心操作，左插还是右插，头插还是尾插都可以通过这个实现
//{
//	e[idx] = x;
//	r[idx] = r[k];
//	l[idx] = k;
//	l[r[k]] = idx;
//	r[k] = idx++;
//}
//
//void remove(int k)
//{
//	l[r[k]] = l[k];
//	r[l[k]] = r[k];
//}
//
//int main()
//{
//	init();
//	cin >> n;
//	while (n--)
//	{
//		string op;
//		int x, k;
//		cin >> op;
//		if (op == "L")	//在左端点的右边插入一个数
//		{
//			cin >> x;
//			add(0, x);
//		}
//		else if (op == "R")
//		{
//			cin >> x;
//			add(l[1], x);
//		}
//		else if (op == "D")	//删除第k个插入的数
//		{
//			cin >> k;
//			remove(k + 1);
//		}
//		else if (op == "IL")	//在第k个数的左边插入一个数
//		{
//			cin >> k >> x;
//			add(l[k + 1], x);
//		}
//		else
//		{
//			cin >> k >> x;
//			add(k + 1, x);
//		}
//	}
//	for (int i = r[0]; i != 1; i = r[i])
//	{
//		cout << e[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}

//KMP

const int N = 10010;
char s[N], p[N];
int ne[N];	//p是模板串
int n, m;

int main()
{
	cin >> m >> s >> n >> p;
	//求next数组
	ne[0] = 0;
	for (int i = 1, j = 0; i < n; i++)
	{
		while (j != 0 && p[j] != p[i])
			j = ne[j - 1];
		if (p[j] == p[i])
			j++;
		ne[i] = j;
	}

	for (int i = 0, j = 0; i < m; i++)
	{
		while (j != 0 && s[i] != p[j])
			j = ne[j - 1];
		if (p[j] == s[i])
			j++;
		if (j == n)
		{
			cout << i - n + 1 << " ";
			if (j != 0)
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