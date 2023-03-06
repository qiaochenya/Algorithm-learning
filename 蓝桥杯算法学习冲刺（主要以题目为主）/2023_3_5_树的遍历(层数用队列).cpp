#include <iostream>
#include <queue>
using namespace std;

const int N = 35;
int n;
int a[N], b[N], p[N];
int l[N], r[N];

int bulid(int al, int ar, int bl, int br, int u)
{
    if (al > ar)
        return 0;
    int root = a[ar];
    int k = p[root];
    l[root] = bulid(al, k - 1 - bl + al, bl, k - 1, u + 1);
    r[root] = bulid(k - bl + al, ar - 1, k + 1, br, u + 1);

    return root;
}

void bfs()
{
    queue<int> q;
    q.push(a[n - 1]);
    while (q.size())
    {
        int t = q.front();
        q.pop();
        cout << t << " ";
        
        if (l[t])
            q.push(l[t]);
        if (r[t])
            q.push(r[t]);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        p[b[i]] = i;

    bulid(0, n - 1, 0, n - 1, 0);

    bfs();

    return 0;
}