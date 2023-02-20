#include <iostream>
using namespace std;

const int mod = 1e9 + 7;
const int N = 55;
int n, m, k;
int w[N][N];
int f[N][N][13][14];

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> w[i][j];
            w[i][j]++;  //! 因为c要用到-1所有从-1 ~ 12 变为0 ~ 13
        }

    //! 边界，其它边界直接是0种方案
    f[1][1][1][w[1][1]] = 1;
    f[1][1][0][0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
                continue;

            for (int u = 0; u <= k; u++)
                for (int v = 0; v <= 13; v++)
                {
                    //! 不选这个数
                    int &val = f[i][j][u][v];
                    val = (val + f[i - 1][j][u][v]) % mod;
                    val = (val + f[i][j - 1][u][v]) % mod;

                    if (u > 0 && v == w[i][j])  //! 选这个数
                    {
                        for (int c = 0; c < v; c++)
                        {
                            val = (val + f[i - 1][j][u - 1][c]) % mod;
                            val = (val + f[i][j - 1][u - 1][c]) % mod;
                        }
                    }
                }
        }
    int res = 0;
    for (int i = 0; i <= 13; i++)
    {
        res = (f[n][m][k][i] + res) % mod;
    }
    cout << res << endl;

    return 0;
}