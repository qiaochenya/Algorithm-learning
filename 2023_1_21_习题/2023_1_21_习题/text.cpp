#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//����ѡ�񣬿��ŵ���չ

//const int N = 100010;
//int n, k;
//int q[N];
////�ݹ����������i == j��i = j + 1
//int quick_sort(int l, int r, int k)
//{
//	if (l == r) return q[l];	//����ѡ��͹鲢�������==�������Ų�����ֻ��>=
//	int x = q[l], i = l - 1, j = r + 1;
//	while (i < j)
//	{
//		do i++; while (x > q[i]);
//		do j--; while (x < q[j]);
//		if (i < j) swap(q[i], q[j]);
//	}
//	int sl = j - l + 1;	//��ߵĸ���
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

//����Ե��������鲢��Ӧ��

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
//			//�Ǹ�������������Ҳһ�����
//			res += mid - i + 1;
//		}
//	}
//	//��β
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

//����3�η���

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
//	//cout << l << endl;	//���Լ�����6λС��
//	printf("%lf", l);
//}

//һάǰ׺��,��Ҫע���1��ʼ

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

//��ά����

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