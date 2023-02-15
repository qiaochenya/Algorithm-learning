//蓝桥杯真题 —— 开关问题

//第一步 枚举从0 ~ 2的16次方 - 1的所有方案
//第二步 按照这个方案来操作所有开关
//第三步 判断是否成功 —— 记录方案

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 5;
char g[N][N], backup[N][N];

//将二维转化为一维
int get(int x, int y)
{
    return x * 4 + y;   //常用
}

//变单独
void turn_one(int x, int y)
{
    if (backup[x][y] == '+')
        backup[x][y] = '-';
    else
        backup[x][y] = '+';
}

//把十字全变了
void turn_all(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        turn_one(x, i);
        turn_one(i, y);
    }
    turn_one(x, y); //变了两次再来一次
}

int main()
{
    for (int i = 0; i < 4; i++)
        cin >> g[i];

    //记录答案
    vector<pair<int, int>> ans;

    for (int op = 0; op < 1 << 16; op++)
    {
        memcpy(backup, g, sizeof(g));
        vector<pair<int, int>> temp;

        //进行操作
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
                if (op >> get(i, j) & 1)
                {
                    temp.push_back({i, j});
                    turn_all(i, j);
                }
            }
        
        //判断是否成功
        bool all_open = true;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (backup[i][j] == '+')
                {
                    all_open = false;
                    break;
                }
        
        if (all_open == true)
        {
            if (ans.empty() || ans.size() > temp.size())    //是否为空和是否是最小值
                ans = temp;
        }
    }

    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i.first + 1 << " " << i.second + 1 << endl;

    return 0;
}