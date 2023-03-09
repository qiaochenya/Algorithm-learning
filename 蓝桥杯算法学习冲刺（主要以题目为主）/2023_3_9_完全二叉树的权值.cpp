#include <iostream>
using namespace std;
typedef long long LL;

const int N = 1e5 + 110;
int g[N];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> g[i];

    //! 1e5个1e5肯定爆int
    LL maxv = -1e6;
    int dist;

    for (int i = 1, d = 1; i <= n; i *= 2, d++)
    {
        LL cnt = 0;
        for (int j = i; j < i + (1 << (d - 1)) && j <= n; j++)  //! 完全二叉树最后面可能不全
            cnt += g[j];

        if (maxv < cnt)
        {
            maxv = cnt;
            dist = d;
        }
    }

    cout << dist << endl;

    return 0;
}