#include <iostream>
using namespace std;
int month_one[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month_two[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int x)
{
    bool is_two = false;

    //! 把年月日取出来
    int year = x / 10000;
    x %= 10000;
    int mon = x / 100;
    x %= 100;
    int day = x;

    if (day == 0)
        return false;

    if (mon <= 0 || mon > 12)
        return false;

    //! 判断是否为闰年
    if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)
        is_two = true;

    if (is_two == false)
    {
        if (day > month_one[mon])
            return false;
    }

    if (is_two == true)
    {
        if (day > month_two[mon])
            return false;
    }

    return true;

}

int main()
{
    int date1, date2;
    cin >> date1 >> date2;
    
    int res = 0;
    //! 直接枚举范围内的回文串
    for (int i = 1000; i <= 9999; i++)
    {
        int date = i, x = i;
        for (int i = 0; i < 4; i++) //! 
        {
            date = date * 10 + x % 10;
            x /= 10;
        }
        //! 首先判断是否在范围内，在判断是否是合法年份
        if (date1 <= date && date <= date2 && check(date))
            res++;
    }
    
    cout << res << endl;
    return 0;
}