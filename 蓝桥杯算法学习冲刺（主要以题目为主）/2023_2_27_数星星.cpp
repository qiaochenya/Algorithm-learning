#include <stdio.h>
using namespace std;

const int N = 32010;
int n;
int tree[N], level[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int v)
{
    for (int i = x; i <= N; i += lowbit(i))
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
    scanf("%d", &n);
    int cnt = n;
    while (cnt--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x++;
        level[query(x)]++;
        add(x, 1);
    }

    for (int i = 0; i < n; i++)
        printf("%d\n", level[i]);

    return 0;
}