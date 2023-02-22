#include <iostream>
using namespace std;

const int N = 1e5 + 10, INF = 1e6;
int a[N];
int n;

int main()
{
    cin >> n;
    int Min = INF, Max = -INF;
    while (n--)
    {
        string x;
        cin >> x;
        for (int i = 0; i < (int)x.size(); i++)
        {
            int t = x[i] - '0';
            a[t]++;
            Min = min(Min, t);
            Max = max(Max, t);
        }
           
    }
    int id1, id2;
    for (int i = Min; i <= Max; i++)
    {
        if (a[i] == 0)
            id1 = i;
        else if (a[i] == 2)
            id2 = i;
    }
    cout << id1 << " " << id2 << endl;
}