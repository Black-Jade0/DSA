#include <bits/stdc++.h>

using namespace std;

int main()
{
    int INP;
    cin >> INP;
    while (INP--)
    {
        int n, k;
        cin >> n >> k;
        int help = 1;
        int help2 = n;
        for (int i = 1; i <= n; i++)
        {
            if (i % k == 0)
            {
                cout << help++;
            }
            else
            {
                cout << help2--;
            }
        }
        cout << '\n';
    }
    return 0;
}

