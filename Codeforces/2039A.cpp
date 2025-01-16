#include <bits/stdc++.h>

using namespace std;

int main()
{
    int INP;
    cin >> INP;
    while (INP--)
    {
        int n;
        cin >> n;
        int help = 0;
        for (int i = 1; i <= n; i++)
        {
            cout << i + help++ << " ";
        }
    }
    return 0;
}