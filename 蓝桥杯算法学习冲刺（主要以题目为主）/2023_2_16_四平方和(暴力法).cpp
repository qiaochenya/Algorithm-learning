//? 每个正整数都可以表示为至多4个正整数的平方和

#include <iostream>
#include <cmath>
using namespace std;

int n;

int main()
{
    cin >> n;
    for (int a = 0; a * a <= n; a++)    //! 1个数的平方最多就枚举 0 ~ 根号n 就可以了
        for (int b = a; b * b + a * a <= n; b++)    //! 要求字典序输出就直接让b = a就好了
            for (int c = b; c * c + b * b + a * a <= n; c++)
            {
                int t = n - c * c + b * b + a * a;
                int d = (int)sqrt(t);
                if (d * d == t)
                {
                    cout << a << " " << b << " " << c << " " << d << endl;
                    return 0;
                }
            }
}