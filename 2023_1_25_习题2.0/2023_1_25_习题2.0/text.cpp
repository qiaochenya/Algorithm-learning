#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
//queue<string>q;
//unordered_map<string, int>d;	//存状态到开始状态的距离
//
//int bfs(string start)
//{
//	string end = "12345678x";
//	//初始化
//	q.push(start);
//	d[start] = 0;	//开始状态到开始状态是0
//
//	int dx[4] = { 0,-1,0,1 }, dy[4] = {-1,0,1,0};
//
//	while (q.size())
//	{
//		string t = q.front();	//队头赋予
//		q.pop();	//弹出队头
//		int distance = d[t];
//
//		if (t == end) return distance;
//
//		int k = t.find('x');	//找x的位置
//		//将一维转化为3*3的位置
//		int x = k / 3, y = k % 3;
//		for (int i = 0; i < 4; i++)
//		{
//			int a = x + dx[i], b = y + dy[i];
//			if (a >= 0 && a < 3 && b >= 0 && b < 3)
//			{
//				swap(t[k], t[a * 3 + b]);
//
//				if (d.count(t) == 0)	//未被搜索过
//				{
//					d[t] = distance + 1;	//当前状态加1
//					q.push(t);
//				}
//				//恢复原状
//				swap(t[k], t[a * 3 + b]);
//			}
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	string start;
//	for (int i = 0; i < 9; i++)
//	{
//		char c;
//		cin >> c;
//		start += c;
//	}
//
//	cout << bfs(start) << endl;
//	return 0;
//}

//#include <cstdio>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N = 1e5 + 10;
//
//pair<int, int> a[N];
//int n;
//bool st[N];
//
//int main()
//{
//    scanf("%d", &n);
//    int k = n;
//    while (k--)
//    {
//        int x, y;
//        scanf("%d%d", &x, &y);
//        a[k] = { x, y };
//    }
//    sort(a, a + n);
//
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = i + 1; j < n; j++)
//        {
//
//            if (a[i].second > a[j].second)
//            {
//                if (st[i] == true && st[j] == false)
//                    ans++;
//                if (st[i] == false && st[j] == false)
//                {
//                    st[i] = true;
//                    st[j] = true;
//                    ans += 2;
//                }
//
//
//            }
//
//        }
//    }
//
//    cout << ans << endl;
//}


//#include <cstring>
//using namespace std;
//
//const int N = 1e5 + 10;
//int n, m;
//pair<int, int>g[N];
//int use[N];
//
//int dfs(int u, int x)
//{
//    x++;
//    if (x == m)
//    {
//        return g[u].first - g[u].second * use[u];
//        //use[u]--;
//    }
//    int res;
//    if (x != m)
//    {
//
//        int y = res = g[u].first - g[u].second * use[u];
//
//
//        for (int i = 0; i < n; i++)
//        {
//            use[i]++;
//            res = max(res, y + dfs(i, x));
//            use[i]--;
//        }
//    }
//    return res;
//}
//
//int main()
//{
//    memset(use, -1, sizeof(use));
//    scanf("%d%d", &n, &m);
//    for (int i = 0; i < n; i++)
//    {
//        int a, b;
//        scanf("%d%d", &a, &b);
//        g[i] = { a, b };
//    }
//    int res = 0;
//    for (int i = 0; i < n; i++)
//    {
//        use[i]++;
//        res = max(res, dfs(i, 0));
//        use[i]--;
//    }
//    cout << res << endl;
//    return 0;
//}

#include <iostream>
#include <cstring>
using namespace std;

const int N = 6;
char g[N][N], backup[N][N];
int n;
int dx[5] = { 0, -1, 0, 1, 0 }, dy[5] = { -1, 0, 1, 0, 0 };

void turn(int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        backup[a][b] ^= 1;
    }
}

int main()
{
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 5; i++) cin >> g[i];
        memcpy(backup, g, sizeof(g));
        int res = 114514, step = 0;

        for (int k = 0; k < 1 << 5; k++)
        {
            for (int i = 0; i < 5; i++)
            {
                if ((k >> i & 1) == 1)
                {
                    step++:
                    turn(0, i);
                }
            }

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (backup[i][j] == '0')
                    {
                        step++;
                        turn(i + 1, j);
                    }
                }
            }

            bool dark = false;
            for (int j = 0; j < 4; j++)
            {
                if (backup[4][j] == '0')
                {
                    dark = true;
                    break;
                }
            }
            if (dark == false)
                res = min(step, res);
        }
        if (res > 6) cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}