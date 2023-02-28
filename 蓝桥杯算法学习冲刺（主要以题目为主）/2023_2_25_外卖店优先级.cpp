#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define x first
#define y second

const int N = 1e5 + 10;
pair<int, int> order[N];
int score[N], last[N];
bool st[N];
int n, m, T;

int main()
{
    cin >> n >> m >> T;
    for (int i = 0; i < m; i++)
        scanf("%d %d", &order[i].x, &order[i].y);

    sort(order, order + m);

    //! 枚举每一个订单已经排好序
    for (int i = 0; i < m;)
    {
        //! 找到这个时间段内相同id的数量
        int j = i;
        while (j < m && order[j] == order[i])
            j++;

        int t = order[i].x, id = order[i].y, cnt = j - i;   //! cnt就是数量

        i = j;
        
        //! 处理t时刻之前的内容
        score[id] -= t - last[id] - 1;
        score[id] = max(0, score[id]);
        if (score[id] <= 3)
            st[id] = false;

        //! 处理t时刻
        score[id] += cnt * 2;
        if (score[id] > 5)
            st[id] = true;

        //! 最后记得把last更新
        last[id] = t;
    }

    //! 还要处理之后的到T的内容
    for (int id = 1; id <= n; id++)
    {
        if (last[id] < T)
        {
            score[id] -= T - last[id];
            score[id] = max(0, score[id]);
        }
        if (score[id] <= 3)
            st[id] = false;
    }

    int res = 0;
    for (int id = 1; id <= n; id++)
    {
        if (st[id] == true)
            res++;
    }

    cout << res << endl;

    return 0;
}