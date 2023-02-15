//?给定一个浮点数 n，求它的三次方根。
//?保留6位小数

#include <iostream>
using namespace std;

int main()
{
    double n;
    cin >> n;
    double l = -1e5, r = 1e5;
    while (r - l > 1e-8)    //!多取两位保证精度
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= n)
            r = mid;
        else
            l = mid;
    }
    printf("%lf\n", l);
}