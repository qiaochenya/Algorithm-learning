#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//01背包问题
//二维

//const int N = 1145;
//int n, m;	//n是物品个数，m是背包容量
//int v[N], w[N], f[N][N];
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j <= m; j++)
//		{
//			f[i][j] = f[i - 1][j];
//			if (j >= v[i]) f[i][j] = max(f[i - 1][j - v[i]] + w[i], f[i][j]);
//		}
//	}
//	cout << f[n][m] << endl;
//	return 0;
//}

//一维

//const int N = 1145;
//int n, m;
//int v[N], w[N];
//int f[N];
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
//
//	for (int i = 1; i <= n; i++)
//		for (int j = m; j >= v[i]; j--)
//			f[j] = max(f[j], f[j - v[i]] + w[i]);
//	cout << f[m] << endl;
//	return 0;
//}

//完全背包问题

//二维朴素

//const int N = 1145;
//int n, m;
//int v[N], w[N];
//int f[N][N];
//
//int main()
//{
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
//
//    for (int i = 1; i <= n; i++)
//        for (int j = 0; j <= m; j++)
//            for (int k = 0; k * v[i] <= j; k++)
//                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
//
//    cout << f[n][m] << endl;
//    return 0;
//}

//优化

//const int N = 1145;
//int n, m;
//int v[N], w[N];
//int f[N][N];
//
//int main()
//{
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
//
//    for (int i = 1; i <= n; i++)
//        for (int j = 0; j <= m; j++)
//        {
//            f[i][j] = f[i - 1][j];
//            if (j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
//        }
//
//    cout << f[n][m] << endl;
//    return 0;
//}

//再优化

//#include <iostream>
//using namespace std;
//const int N = 1145;
//int n, m;
//int v[N], w[N];
//int f[N];
//
//int main()
//{
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
//
//    for (int i = 1; i <= n; i++)
//        for (int j = v[i]; j <= m; j++)
//            f[j] = max(f[j], f[j - v[i]] + w[i]);
//
//    cout << f[m] << endl;
//    return 0;
//}

//多重背包

//#include <iostream>
//using namespace std;
//
//const int N = 25000, M = 2100;
//int n, m;
//int v[N], w[N];
//int f[N];
//
//int main()
//{
//    cin >> n >> m;
//    int cnt = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        int a, b, c;
//        cin >> a >> b >> c;
//        int k = 1;
//        while (k <= c)
//        {
//            cnt++;
//            v[cnt] = a * k;
//            w[cnt] = b * k;
//            c -= k;
//            k *= 2;
//        }
//        if (c > 0)
//        {
//            cnt++;
//            v[cnt] = c * a;
//            w[cnt] = c * b;
//        }
//    }
//    n = cnt;
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = m; j >= v[i]; j--)
//        {
//            f[j] = max(f[j - v[i]] + w[i], f[j]);
//        }
//    }
//    cout << f[m] << endl;
//    return 0;
//}

//分组背包问题

#include <iostream>
using namespace std;

const int N = 110;
int n, m;
int v[N][N], w[N][N], s[N];
int f[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < s[i]; j++)
        {
            cin >> v[i][j] >> w[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 0; k < s[i]; k++)
            {
                if (v[i][k] <= j)
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}