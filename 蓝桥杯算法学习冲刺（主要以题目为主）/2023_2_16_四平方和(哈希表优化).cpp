#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;

unordered_map<int, pair<int, int>> s;
int n;

int main()
{
    cin >> n;

    //! 预处理c，d，到时候直接查表
    for (int c = 0; c * c <= n; c++)
        for (int d = c; d * d + c * c <= n; d++)
        {
            int t = c * c + d * d;
            if (s.count(t) == 0)    //! 只存第一个刚好是字典序
                s[t] = {c, d};  //! c++哈希表的操作
        }

    //! 找a，b
    for (int a = 0; a * a <= n; a++)
        for (int b = a; b * b + a * a <= n; b++)
        {
            int t = n - a * a - b * b;
            if (s.count(t) == 1) 
            {
                printf("%d %d %d %d\n", a, b, s[t].first, s[t].second);
                return 0;
            }
        }
}