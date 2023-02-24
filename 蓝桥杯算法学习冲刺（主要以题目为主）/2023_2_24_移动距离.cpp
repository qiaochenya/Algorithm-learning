#include <iostream>
using namespace std;

int main()
{
    int w, n, m;
    cin >> w >> n >> m;
    //! 将其当成二维数组的下标可以少一些判断
    n--, m--;

    int x1, x2, y1, y2;

    x1 = n / w, x2 = m / w;
    y1 = n % w, y2 = m % w;
    
    //! 当奇数行时
    if (x1 % 2 != 0)
        y1 = w - 1 - y1;
    if (x2 % 2 != 0)
        y2 = w - 1 - y2;

    cout << abs(x1 - x2) + abs(y1 - y2) << endl;

    return 0;
}