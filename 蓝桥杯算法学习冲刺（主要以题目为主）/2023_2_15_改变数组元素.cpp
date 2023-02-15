#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e5 + 10;
int T;
int b[N];   //差分数组

int main()
{
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        memset(b, 0, (n + 1) * 4);  //防止超时
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            x = min(x, i);  //如果x过大就把所有全变为1
            int l = i - x + 1, r = i;
            b[l]++, b[r + 1]--; //差分操作
        }
        //求回前缀和
        for (int i = 1; i <= n; i++)
            b[i] += b[i - 1];
        for (int i = 1; i <= n; i++)
            cout << !!b[i] << " ";
        cout << endl;
    }
    return 0;
}