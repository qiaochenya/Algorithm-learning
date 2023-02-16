#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, maxh;
int h[N];

bool check(int mid)
{
    //! 每次变化都是 2E - h[k + 1]

    for (int i = 1; i <= n; i++)
    {
        mid = 2 * mid - h[i];
        if (mid < 0)
            return false;

        //! 如果过程中已经大过 maxh 的话，剩下 E 肯定单调递增直接返回 true 就行
        if (mid >= maxh)
            return true;
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        maxh = max(maxh, h[i]);
    }
    
    //! 二分找能量
    int l = 0, r = 1e5;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}