#include <iostream>
#include <unordered_set>
using namespace std;

const int N = 10;
int g[N][N];
int n, m, k;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
unordered_set<int> s;

void dfs(int x, int y, int u, int sum)
{
    if (u == k)
    {
        if (!s.count(sum))
        {
            //cout << sum << endl;
            s.insert(sum);
            return;
        }
        return;
    }
    
    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m) continue;
        
        dfs(a, b, u + 1, sum * 10 + g[a][b]);
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
            
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dfs(i, j, 0, g[i][j]);
            
    
    cout << s.size() << endl;
    return 0;
}