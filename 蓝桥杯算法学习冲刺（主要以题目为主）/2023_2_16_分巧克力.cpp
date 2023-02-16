//? 蓝桥杯真题——二分

#include <cstdio>
using namespace std;

const int N = 1e5 + 10;
int n, k;
int h[N], w[N];

bool check(int mid)
{
    int res = 0;    //! 计算按照这个mid这个尺寸可以切出多少巧克力

    for (int i = 0; i < n; i++)
    {
        res += (h[i] / mid) * (w[i] / mid); //! 记得加括号
        if (res >= k)   //! 满足就返回
            return true;
    }
    return false;   //! 枚举完所有还是不满足
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &h[i], &w[i]);

    //! 二分出切多大尺寸的巧克力
    int l = 1, r = 1e5; //! 题目说至少有1 * 1的巧克力会满足
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }

    printf("%d\n", l);

    return 0;
}