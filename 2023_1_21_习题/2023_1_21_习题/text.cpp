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

//һά���

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

//��ά���

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

//����Ԫ��֮�ͣ��������鶼������ģ���һ����������һ��Ԫ�غ���һ����������һ��Ԫ�ؼ���������x
//˫ָ���㷨��Ҫ�ȿ��Ǳ�������˼��������

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

//˫����

//const int N = 100010;
//int l[N], r[N], e[N], idx;
//int n;
//
//void init()	//0����ߵĵ㣬1���ұߵĵ�
//{
//	r[0] = 1;
//	l[1] = 0;
//	idx = 2;
//}
//
//void add(int k, int x)	//����ĺ��Ĳ�������廹���Ҳ壬ͷ�廹��β�嶼����ͨ�����ʵ��
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
//		if (op == "L")	//����˵���ұ߲���һ����
//		{
//			cin >> x;
//			add(0, x);
//		}
//		else if (op == "R")
//		{
//			cin >> x;
//			add(l[1], x);
//		}
//		else if (op == "D")	//ɾ����k���������
//		{
//			cin >> k;
//			remove(k + 1);
//		}
//		else if (op == "IL")	//�ڵ�k��������߲���һ����
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

//const int N = 10010;
//char s[N], p[N];
//int ne[N];	//p��ģ�崮
//int n, m;
//
//int main()
//{
//	cin >> m >> s >> n >> p;
//	//��next����
//	ne[0] = 0;
//	for (int i = 1, j = 0; i < n; i++)
//	{
//		while (j != 0 && p[j] != p[i])
//			j = ne[j - 1];
//		if (p[j] == p[i])
//			j++;
//		ne[i] = j;
//	}
//
//	for (int i = 0, j = 0; i < m; i++)
//	{
//		while (j != 0 && s[i] != p[j])
//			j = ne[j - 1];
//		if (p[j] == s[i])
//			j++;
//		if (j == n)
//		{
//			cout << i - n + 1 << " ";
//			if (j != 0)
//				j = ne[j - 1];
//		}
//	}
//	//��ӡne����
//	cout << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cout << ne[i] << " ";
//	}
//	return 0;
//}

//��N��������ѡ���������������㣬�õ��Ľ������Ƕ���

//const int N = 100010, M = N * 31;	//ÿ����31λ
//int n;
//int a[N], son[M][2], idx;	//2����Ϊ������
//
////�������
//void insert(int x)
//{
//	int p = 0;
//	for (int i = 30; i >= 0; i--)
//	{
//		int u = x >> i & 1;
//		if (son[p][u] == 0)	//����һ���ڵ�
//			son[p][u] = ++idx;
//		p = son[p][u];
//	}
//}
//
////ѯ�ʲ���
//int query(int x)
//{
//	int p = 0, ans = 0;
//	for (int i = 30; i >= 0; i--)
//	{
//		int u = x >> i & 1;
//		if (son[p][!u] != 0)	//Ҫ�򷴷���ȥ
//		{
//			p = son[p][!u];
//			ans = ans * 2 + !u;
//		}
//		else
//		{
//			p = son[p][u];	//û�е�ֻ�ý���
//			ans = ans * 2 + u;
//		}
//	}
//	return ans;
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	int res = 0;
//	for (int i = 0; i < n; i++)
//	{
//		insert(a[i]);	//�Ȳ����ٲ��ҿ��Բ�д��һ���ж��Ƿ�Ϊ��
//		int t = query(a[i]);
//		res = max(res, a[i] ^ t);
//	}
//	cout << res << endl;
//	return 0;
//}
//

//ʳ�����������鼯

const int N = 50010;
int n, m;
int fa[N], d[N];	//d�����ǵ����ڵ�ľ���

int find(int x)
{
	if (x != fa[x])
	{
		int t = find(fa[x]);
		d[x] += d[fa[x]];
		fa[x] = t;
	}
	return fa[x];
}

int main()
{
	cin >> n >> m;
	//��ʼ��father����
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	int res = 0;	//�ٻ�����
	while (m--)
	{
		int t, x, y;
		cin >> t >> x >> y;
		if (x > n || y > n)
		{
			res++;
		}
		else
		{
			int px = find(x), py = find(y);
			if (t == 1)
			{
				if (px == py && ((d[x] % 3) - (d[y] % 3)) != 0)	//��ͬһ�����ϲ��ҵ����ڵ�ľ��벻ͬ�����Ǽٻ�
				{
					res++;
				}
				else if (px != py)	// ����ͬһ�����ϣ��ϲ�������
				{
					fa[px] = py;
					d[px] = d[y] - d[x];
				}
			}
			else if (t == 2)
			{
				if (px == py && ((d[x] % 3 - d[y] % 3 != 1) && (d[x] % 3 - d[y] % 3 != -2)))	//������ͬ����·�ȷ�����ͬһ������,ע��Ӻ���ǰ�Ժʹ�ǰ����Լ��Ľ����ͬ
				{
					res++;
				}
				else if (px != py)
				{
					fa[px] = py;
					d[px] = 1 - d[x] + d[y];
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}