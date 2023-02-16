#include <cstdio>
#include <iostream>
using namespace std;

const int N = 5010;
int a[N][N], s[N][N];
int n, r;

int main()
{
    scanf("%d%d", &n, &r);

    while (n--)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        a[x + 1][y + 1] = w;
    }

    for (int i = 1; i <= 5000; i++)
        for (int j = 1; j <= 5000; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];

    int res = 0;
    for (int x2 = 1; x2 <= 5000; x2++)
        for (int y2 = 1; y2 <= 5000; y2++)
        {
            int x1 = max(1, x2 - r + 1);
            int y1 = max(1, y2 - r + 1);
            res = max(res, s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
        }
    printf("%d\n", res);
    return 0;
}