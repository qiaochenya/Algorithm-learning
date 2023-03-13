#include <iostream>
using namespace std;

const int mod = 9901;
int A, B;

//快速幂
int qmi(int a, int k)
{
   int res = 1;
   a %= mod;
   while (k)
   {
       if (k & 1) res = res * a % mod;
       a = a * a % mod;
       k >>= 1;
   }
   
   return res;
}

int sum(int p, int k)
{
    if (k == 0) return 1;
    //奇数项，把它转化为偶数项才可以套公式
    if (k % 2 == 0) return (p % mod * sum(p, k - 1) + 1) % mod;
    //分治
    return (1 + qmi(p, k / 2 + 1)) * sum(p, k / 2) % mod;
}

int main()
{
    cin >> A >> B;
    
    int res = 1;
    
    //求质因数
    for (int i = 2; i * i <= A; i++)
    {
        if (A % i == 0)
        {
            int s = 0;
            while (A % i == 0)
            {
                s++;
                A /= i;
            }
            res = res * sum(i, B * s) % mod;
        }
    }
    
    //不要漏这项，最后还剩自己
    if (A > 1) res = res * sum(A, B) % mod;
    if (A == 0) res = 0;
    
    cout << res << endl;
    
    return 0;
}