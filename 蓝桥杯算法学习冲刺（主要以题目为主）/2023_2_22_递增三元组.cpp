#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], c[N];
int n;

int main()
{
    cin >> n;
    //! 直接把a和c改成每个数出现次数数组
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }

    //! b就是正常的数组，用来枚举
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        c[x]++;
    }
    
    //! 处理前缀和
    for (int i = 0; i <= (int)1e5; i++)
    {
        a[i] += a[i - 1];
        c[i] += c[i - 1];
    }

    long long int res = 0;    
    for (int i = 0; i < n; i++)
    {
        int A, C;
        A = a[b[i] - 1];
        //cout << c[(int)1e5] << " " << c[b[i]] << endl;
        
        C = c[(int)1e5] - c[b[i]];
        //cout << A << " " << C << endl;

        res += (long long)A * C;
    }
    cout << res << endl;
}
