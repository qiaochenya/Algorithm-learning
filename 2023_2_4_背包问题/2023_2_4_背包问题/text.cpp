#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//01��������
//��ά

//const int N = 1145;
//int n, m;	//n����Ʒ������m�Ǳ�������
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

//һά

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

//��ȫ��������

//��ά����

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

//�Ż�

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

//���Ż�

#include <iostream>
using namespace std;
const int N = 1145;
int n, m;
int v[N], w[N];
int f[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;
    return 0;
}