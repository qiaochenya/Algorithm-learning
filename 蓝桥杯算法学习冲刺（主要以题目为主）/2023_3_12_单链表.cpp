#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int he[N], ne[N], idx = 1;
int h = -1;

void head(int x)
{
    he[idx] = x;
    ne[idx] = h;
    h = idx++;
}

void add(int u, int x)
{
    he[idx] = x;
    ne[idx] = ne[u];
    ne[u] = idx++;
}

void del(int u)
{
    if (u == 0)
    {
        h = ne[h];
        return;
    }
    
    ne[u] = ne[ne[u]];
}

int main()
{
    int M;
    cin >> M;
    
    while (M--)
    {
        char op;
        cin >> op;
        
        if (op == 'H')
        {
            int x;
            cin >> x;
            head(x);
        }
        else if (op == 'D')
        {
            int u;
            cin >> u;
            del(u);
        }
        else 
        {
            int k, x;
            cin >> k >> x;
            add(k, x);
        }
    }
    
    for (int i = h; i != -1; i = ne[i])
        cout << he[i] << " ";
        
    cout << endl;
    
    return 0;
}