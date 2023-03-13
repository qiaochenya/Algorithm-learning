#include <iostream>
#include <cmath>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N], b[N];

//差分的插入操作
void insert(int l ,int r, int x)
{
    b[l] += x;
    b[r + 1] -= x;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], insert(i, i, a[i]);
    
    long long neg = 0, pos = 0; // neg是负数，pos是正数
    
    //只需把差分数组后面的2 ~ n全部变成0，那么原数组就是全为a[1]的数组
    for (int i = 2; i <= n; i++)
    {
        if (b[i] < 0) neg -= b[i];  //负数减去变正数减少取绝对值操作
        else if (b[i] > 0) pos += b[i];
    }
    
    //首先贪心第一种操作去掉了所有正数或者负数，只剩下正数或负数，只能进行2，3操作abs(pos - neg)即剩下的操作数
    cout << min(pos, neg) + abs(pos - neg) << endl;
    
    //第一种操作固定，就2操作会改变a[1]了，而两种操作是等价的可以互相代替即可以全为2，或者全为3，也可以2，3混杂
    //就得到结果数abs(pos - neg) + 1
    cout << abs(pos - neg) + 1 << endl;
    
    return 0;
}