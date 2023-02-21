#include <iostream>
using namespace std;

const int N = 1e5 + 10, INF = 1e8;
int n;
int a[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int res = 0;
    //! 枚举左端点
    for (int i = 0; i < n; i++)
    {
        int Max = -INF, Min = INF;
        //! 枚举右端点
        for (int j = i; j < n; j++)
        {
            Max = max(Max, a[j]);
            Min = min(Min, a[j]);
            if (Max - Min == j - i)
                res++;
        }
    }

    cout << res << endl;
    return 0;
}