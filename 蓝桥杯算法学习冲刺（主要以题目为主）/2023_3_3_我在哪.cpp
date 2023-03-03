#include <iostream>
using namespace std;

int main()
{
    int n;
    string str;
    cin >> n >> str;

    for (int k = 1; k <= n; k++)
    {
        bool falge = true;
        for (int i = 0; i + k - 1 < n; i++)
        {
            for (int j = i + 1; j + k - 1 < n; j++)
            {
                bool same = true;
                for (int h = 0; h < k; h++)
                {
                    if (str[i + h] != str[j + h])
                    {
                        same = false;
                        break;
                    }  
                }

                if (same == true)
                {
                    falge = false;
                    break;
                }
            }

            if (falge == false)
                break;
        }

        if (falge == true)
        {
            cout << k << endl;
            break;
        }
    }

    return 0;
}