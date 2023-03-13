#include <cstdio>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
struct Edge
{
    int id, w;
};
vector<Edge> h[N];
int n;
int distanc[N];

void dfs(int u, int fa, int dist)
{
    distanc[u] = dist;
    for (int i = 0; i < (int)h[u].size(); i++)
    {
        if (h[u][i].id != fa)
        {
            dfs(h[u][i].id, u, dist + h[u][i].w);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        h[a].push_back({b, c});
        h[b].push_back({a, c});
    }
    //! 找树的直径先找一个点，dfs（），在通过这个点找另外一个点，dfs（），就会出现直径了
    dfs(1, -1, 0);

    int u = 1;
    for (int i = 1; i <= n; i++)
        if (distanc[u] < distanc[i])
            u = i;

    dfs(u, -1, 0);

    for (int i = 1; i <= n; i++)
        if (distanc[u] < distanc[i])
            u = i;

    long long s = distanc[u];
    printf("%lld\n", 10 * s + s * (s + 1) / 2);

    return 0;
}