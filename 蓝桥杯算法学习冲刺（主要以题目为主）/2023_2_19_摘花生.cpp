#include <iostream>
using namespace std;

const int N = 110;
int T;
int g[N][N];

int dfs(int cnt, int x, int y, int r, int c)
{
    int Max = cnt;
    if (x + 1 <= r)
    {
        Max = max(Max, dfs(cnt + g[x + 1][y], x, y, r, c));
    }
    if (y + 1 <= c)
    {
        Max = max(Max, dfs(cnt + g[x][y + 1], x, y, r, c));
    }
    return Max;
}

int main()
{
    cin >> T;

    while (T--)
    {
        int r, c;
        cin >> r >> c;
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                cin >> g[i][j];

        int res = dfs(g[1][1], 1, 1, r, c);

        cout << res << endl;
    }
}
