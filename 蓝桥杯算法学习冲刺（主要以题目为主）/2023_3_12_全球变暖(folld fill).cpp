#include <cstdio>
#include <queue>
using namespace std;

const int N = 1010;
int n;
queue<pair<int, int>> q;
char g[N][N];
bool st[N][N];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int i, int j, int &total, int &boand)
{
    q.push({i, j});
    st[i][j] = true;

    while (q.size())
    {
        pair<int, int> t = q.front();
        q.pop();
        total++;    //! 每个元素都对应一个陆地

        bool is_boand = false;  //! 判断是否靠近海

        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];

            if (x < 0 || x >= n || y < 0 || y >= n)
                continue;
            if (st[x][y])
                continue;
            if (g[x][y] == '.')
            {
                is_boand = true;
                continue;
            }
            
            st[x][y] = true;
            q.push({x, y});
        }

        if (is_boand)   //! 靠近海就加一
            boand++;
    }
}   

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", g[i]);

    int cnt = 0;    //! 表示被淹没的岛屿的数量
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!st[i][j] && g[i][j] == '#')
            {
                int total = 0, boand = 0;
                bfs(i, j, total, boand);
                if (total == boand) //! 总的格子数和靠海数相同就完全被淹没
                    cnt++;
            }

    printf("%d\n", cnt);

    return 0;
}