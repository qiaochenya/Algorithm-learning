#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int a[N], tree[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        tree[i] += v;
    }
}

int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
    {
        res += tree[i];
    }

    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    //! 初始化
    for (int i = 1; i <= n; i++)
        add(i, a[i]);

    while (m--)
    {
        int k, x, y;
        cin >> k >> x >> y;

        if (k == 0)
            cout << query(y) - query(x - 1) << endl;
        else
        {
            add(x, y);
        }
    }

    return 0;
}