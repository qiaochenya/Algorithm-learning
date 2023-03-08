#include <iostream>
#include <cstring>
using namespace std;

const int N = 25;
char g[N][N];
bool st[N][N];
int r, c;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int dfs(int x, int y)
{
    int cnt = 1;
    st[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= r || b < 0 || b >= c)
            continue;
        if (st[a][b])
            continue;
        if (g[a][b] == '#')
            continue;

        cnt += dfs(a, b);
    }

    return cnt;
}

int main()
{
    while (cin >> c >> r, r && c)
    {
        for (int i = 0; i < r; i++)
            cin >> g[i];

        int x, y;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (g[i][j] == '@')
                    x = i, y = j;

        int cnt = dfs(x, y);

        memset(st, false, sizeof st);
        cout << cnt << endl;
    }

    return 0;
}