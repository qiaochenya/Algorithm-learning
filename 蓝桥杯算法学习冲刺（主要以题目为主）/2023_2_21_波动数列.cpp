#include <iostream>
using namespace std;

const int N = 1010, mod = 100000007;
int n, s, a, b;
int f[N][N];

int get_mod(int a, int b)
{
    //! 保证余数是正数
    return (a % b + b) % b;
}

int main()
{
    cin >> n >> s >> a >> b;
    f[0][0] = 1;

    //! 集合所有只考虑前i项，且当前的总和除以n的余数是j的方案的集合
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            f[i][j] = (f[i - 1][get_mod(j - i * a, n)] + f[i - 1][get_mod(j + i * b, n)]) % mod;
        }
    }
    //! 只有n - 1项目
    cout << f[n - 1][get_mod(s, n)] << endl;
    return 0;
}