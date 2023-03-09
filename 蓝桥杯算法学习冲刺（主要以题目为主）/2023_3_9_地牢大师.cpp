#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct point
{
    int x, y, z;
};
const int N = 110;
char g[N][N][N];
int dist[N][N][N];
point q[N * N * N];
int z, x, y;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int bfs(point start)
{
    int hh = 0, tt = 0;
    q[0] = start;
    memset(dist, -1, sizeof dist);
    dist[start.x][start.y][start.z] = 0;

    while (hh <= tt)
    {
        point t = q[hh++];


        for (int i = 0; i < 6; i++)
        {
            int a = t.x + dx[i], b = t.y + dy[i], c = t.z + dz[i];

            if (a < 0 || a >= x || b < 0 || b >= y || c < 0 || c >= z)
                continue;
            if (g[c][a][b] == '#')
                continue;
            if (dist[a][b][c] != -1)
                continue;

            dist[a][b][c] = dist[t.x][t.y][t.z] + 1;
            if (g[c][a][b] == 'E')
                return dist[a][b][c];

            q[++tt] = {a, b, c};
        }
    }

    return -1;
}

int main()
{
    while (cin >> z >> x >> y, x || y || z)
    {
        point start;
        for (int k = 0; k < z; k++)
            for (int i = 0; i < x; i++)
            {
                cin >> g[k][i];
                for (int j = 0; j < y; j++)
                    if (g[k][i][j] == 'S')
                        start = {i, j, k};
            }
        //cout << start.x << start.y << start.z << endl;
        int distance = bfs(start);

        if (distance == -1)
            cout << "Trapped!" << endl;
        else
            printf("Escaped in %d minute(s).\n", distance);
    }

    return 0;
}