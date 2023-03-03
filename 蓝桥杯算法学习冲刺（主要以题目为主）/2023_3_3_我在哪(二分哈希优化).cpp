#include <iostream>
#include <unordered_map>
using namespace std;

int n;
string str;

bool check(int mid)
{
    unordered_map<string, int> hash;
    for (int i = 0; i + mid - 1 < n; i++)
    {
        string s = str.substr(i, mid);
        if (hash[s] >= 1)
            return false;

        hash[s]++;
    }

    return true;
}

int main()
{
    cin >> n >> str;
    
    //! 二分
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << endl;

    return 0;
}