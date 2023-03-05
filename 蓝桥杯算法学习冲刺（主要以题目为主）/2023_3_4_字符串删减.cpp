#include <iostream>
using namespace std;

int n;
string str;

int main()
{
    cin >> n >> str;
    
    int ans = 0;
    for (int i = 0; i <= n - 2; )
    {
        //! 判断第一个字符是否为'x'如果不是就直接跳到下一个字符
        if (str[i] == 'x')
        {
            int cnt = 1;
            int j;
            //! 第二个指针开始动
            for (j = i + 1; j - i < 3; j++)
                if (str[j] == 'x') cnt++;
            
            //cout << i << " " << j << " " << cnt << endl;

            //! 判断这3个字符之间'x'的数量是多少
            if (cnt < 3) i = j - 1;
            
            //! j是向前错开一位的是-2
            else if (cnt == 3)  i = j - 2, ans++;
        }
        
        //! 直接跳到下一个字符
        else if (str[i] != 'x')
        {
            i++;
            continue;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}