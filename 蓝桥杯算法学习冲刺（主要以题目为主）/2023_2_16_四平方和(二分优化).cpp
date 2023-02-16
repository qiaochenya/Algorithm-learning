#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 2500000;   //! c，d有平方种组合
int n, m;
struct Sum
{
    int sum, c, d;
    bool operator< (const Sum &w)const
    {
        if (sum != w.sum)
            return sum < w.sum;
        else if (c != w.c)
            return c < w.c;
        else if (d != w.d)
            return d < w.d;
    }
}sun[N];

int main()
{
    scanf("%d", &n);

    //! 枚举c和d
    for (int c = 0; c * c <= n; c++)
        for (int d = c; d * d + c * c <= n; d++)
            sun[m++] = {c * c + d * d, c, d};

    sort(sun, sun + m);

    //! 枚举a和b
    for (int a = 0; a * a <= n; a++)
        for (int b = a; a * a + b * b <= n; b++)
        {
            int t = n - a * a - b * b;
            int l = 0, r = m - 1;
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (sun[mid].sum >= t)
                    r = mid;
                else
                    l = mid + 1;
            }
            if (sun[l].sum == t) 
            {
                printf("%d %d %d %d\n", a, b, sun[l].c, sun[l].d);
                return 0;
            }
        }
        
    return 0;
}
