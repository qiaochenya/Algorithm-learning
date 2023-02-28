#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;
int n, m;
int w[N];
struct edge
{
    int l, r, maxv;
} tree[N * 4];

void pushup(int u)
{
    tree[u].maxv = max(tree[u * 2].maxv, tree[u * 2 + 1].maxv);
}

void bulid(int u, int l, int r)
{
    if (l == r)
        tree[u] = {l, r, w[l]};

    else
    {
        tree[u] = {l, r, 0};
        int mid = (l + r) >> 1;
        bulid(u * 2, l, mid), bulid(u * 2 + 1, mid + 1, r);
        pushup(u);
    }
}

int query(int u, int l ,int r)
{
    if (tree[u].l >= l && tree[u].r <= r)
        return tree[u].maxv;

    int maxv = INT_MIN;
    int mid = (tree[u].l + tree[u].r) >> 1;
    if (l <= mid)
        maxv = query(u * 2, l, r);
    if (r > mid)
        maxv = max(maxv, query(u * 2 + 1, l, r));

    return maxv;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    bulid(1, 1, n);


    int l, r;
    while (m--)
    {
        
        scanf("%d%d", &l, &r);
        printf("%d\n", query(1, l, r));
    }
    return 0;
}
