#include <cstdio>
using namespace std;

int is_one[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int is_two[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int year, int month, int day)
{
    bool falge = false;

    if (day == 0)
        return false;
    if (month == 0 || month > 12)
        return false;
    //! 判断是否时闰年
    if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)
        falge = true;
    
    if (falge == false)
    {
        if (day > is_one[month])
            return false;
    }

    if (falge == true)
    {
        if (day > is_two[month])
            return false;
    }

    return true;
}

int main()
{
    int a, b, c;
    //! scanf格式化输入，从这样的字符串中读数据
    scanf("%d/%d/%d", &a, &b, &c);

    for (int date = 19600101; date <= 20591231; date++)
    {
        int year = date / 10000, month = date % 10000 / 100, day = date % 100;
        //! 判断是否合法
        if (check(year, month, day) == true)
        {
            //! 判断是否满足要求
            if ((year % 100 == a && month == b && day == c) || 
                (month == a && day == b && year % 100 == c) ||
                (day == a && month == b && year % 100 == c))
                printf("%d-%02d-%02d\n", year, month, day);
        }
    }

    return 0;
}