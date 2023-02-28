#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int w[N];
struct Edge
{
    int l, r, sum;
} tree[4 * N];

void pushup(int u)
{
    tree[u].sum = tree[u * 2].sum + tree[u * 2 + 1].sum;
}

void bulid(int u, int l, int r)
{
    if (l == r)
        tree[u] = {l, r, w[l]};
    else
    {
        tree[u] = {l, r, 0};
        int mid = (l + r) >> 1;
        bulid(2 * u, l, mid), bulid(2 * u + 1, mid + 1, r);
        pushup(u);
    }
}

int query(int u, int l, int r)
{
    if (tree[u].l >= l && tree[u].r <= r)
        return tree[u].sum;

    int mid = (tree[u].l + tree[u].r) >> 1;
    int sum = 0;
    if (l <= mid)
        sum = query(u * 2, l, r);
    if (r > mid)
        sum += query(u * 2 + 1, l, r);

    return sum;
}

void motify(int u, int x, int v)
{
    if (tree[u].l == tree[u].r)
        tree[u].sum += v;
    
    else
    {
        int mid = (tree[u].l + tree[u].r) >> 1;
        if (x <= mid)
            motify(u * 2, x, v);
        else
            motify(u * 2 + 1, x, v);

        pushup(u);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    bulid(1, 1, n);

    while (m--)
    {
        int k, a, b;
        cin >> k >> a >> b;
        if (k == 0)
            cout << query(1, a, b) << endl;
        else
            motify(1, a, b);
    }

    return 0;
}