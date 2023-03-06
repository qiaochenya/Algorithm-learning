#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, d, k;
pair<int, int> record[N];
int cnt[N];
bool st[N];

int main()
{
    cin >> n >> d >> k;
    for (int i = 0; i < n; i++)
        scanf("%d%d", &record[i].first, &record[i].second);

    sort(record, record + n);

    for (int i = 0, j = 0; i < n; i++)
    {
        int id = record[i].second;
        cnt[id]++;
        
        while (record[i].first - record[i].first >= d)
        {
            cnt[record[j].second]--;
            j++;
        }

        if (cnt[id] > k)
            st[id] = true;
    }

    for (int i = 0; i <= 100000; i++)
        if (st[i])
            printf("%d\n", i);

    return 0;
}