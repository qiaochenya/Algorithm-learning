#include <iostream>
using namespace std;

bool dfs(int m, int p, int q)
{
    if (m == 0)
        return true;
    if (m >= q && dfs(m - q, p, q) == true)
        return true;
    if (m >= p && dfs(m - p, p, q) == true)
        return true;
    return false;
}

int main()
{
    int p, q;
    cin >> p >> q;
    int res;
    for (int i = 1; i <= 1000; i++)
    {
        if (dfs(i, p, q) == false)
            res = i;
    }
    cout << res << endl;
    return 0;
}