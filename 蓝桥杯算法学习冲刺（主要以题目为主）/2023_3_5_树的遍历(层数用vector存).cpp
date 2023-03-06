#include <iostream>
#include <vector>
using namespace std;

const int N = 35;
int n;
int a[N], b[N], p[N];   //! a是后序，b是中序
vector<int> tree[N];

void build(int al, int ar, int bl, int br, int u)
{
    if (al > ar)
        return;

    int root = a[ar];
    int k = p[root];
    tree[u].push_back(root);

    build(al, k - 1 - bl + al, bl, k - 1, u + 1);
    build(k - bl + al, ar - 1, k + 1, br, u + 1);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        p[b[i]] = i;

    build(0, n - 1, 0, n - 1, 0);

    for (int i = 0; i < n; i++)
        for (auto x : tree[i])
            cout << x << " ";

    cout << endl;

    return 0;
}