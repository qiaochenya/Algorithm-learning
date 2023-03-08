#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int b[N], n, cnt;
bool st[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    for (int i = 1; i <= n; i++)
        if (st[i] == false)
        {
            cnt++;
            for (int j = i; st[j] == false; j = b[j])
            {
                st[j] = true;

            }
        }

    cout << n - cnt << endl;

    return 0;
}