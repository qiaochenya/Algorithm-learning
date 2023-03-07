#include <iostream>
#include <queue>
#include <cstring>
#define x first
#define y second
using namespace std;

const int N = 210;
char op[N][N];
int t;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int dist[N][N];

int main()
{
    cin >> t;
    int r, c;
    
    while (t--)
    {
        pair<int, int> start, end;
        bool falge = false;
        cin >> r >> c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                cin >> op[i][j];
                if (op[i][j] == 'S')
                    start = {i, j};
                else if (op[i][j] == 'E')
                    end = {i, j};
            }
            
        queue<pair<int, int>> q;
        q.push(start);
        
        memset(dist, -1, sizeof dist);
        dist[start.first][start.second] = 0;
        
        while (q.size())
        {
            pair<int, int> t = q.front();
            q.pop();
            
            if (op[t.first][t.second] == 'E')
            {
                cout << dist[t.first][t.second] << endl;
                falge = true;
            }
            
            for (int i = 0; i < 4; i++)
            {
                int a = t.first + dx[i], b = t.second + dy[i];
                if (a < 0 || b < 0 || a >= r || b >= c || op[a][b] == '#' || dist[a][b] != -1) continue;
                
                q.push({a, b});
                dist[a][b] = dist[t.first][t.second] + 1;
            }
        }
        if (falge == false)
            cout << "oop!" << endl;
    }
}