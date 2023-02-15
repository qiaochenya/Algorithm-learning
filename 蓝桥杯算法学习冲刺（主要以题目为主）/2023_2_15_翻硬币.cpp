//递推题目，类似于开关一类的题

#include <iostream>
#include <cstring>
using namespace std;

const int N = 110;
char start[N], aim[N];  //开始数组和目标数组

void trun(int x)
{
    if (start[x] == '*')
        start[x] = 'o';
    else
        start[x] = '*';
}

int main()
{
    cin >> start >> aim;
    int len = strlen(start);
    int cnt = 0;

    //由于答案唯一就不用判断最后一个相不相同
    for (int i = 0; i < len; i++)
    {
        if (start[i] != aim[i])
        {
            trun(i), trun(i + 1);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}