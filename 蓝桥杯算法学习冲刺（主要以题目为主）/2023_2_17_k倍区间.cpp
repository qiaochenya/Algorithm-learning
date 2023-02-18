//? 前缀和加上取模优化

#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, k;
long long s[N], cnt[N];

int main()
{
    cin >> n >> k;

    //! 求前缀和
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    long long int res = 0;
    cnt[0] = 1; //! 如果一个数本身是k的倍数那么它本身就是一个答案
    
    for (int i = 1; i <= n; i++)
    {
        res += cnt[s[i] % k];
        cnt[s[i] % k]++;
    }
    cout << res << endl;
    return 0;
}