#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int res = n;    //! 表示可以喝多少瓶

    while (n >= 3)
    {
        res += n / 3;
        n = (n / 3) + (n % 3);  //! 瓶盖数量等于当前瓶的数量除以 3 加上足以换一瓶饮料剩下的瓶盖
    }

    cout << res << endl;
}