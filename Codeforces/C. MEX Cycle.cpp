#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> result;
    for (int i = 0; i < n / 2; i++)
    {
        result.push_back(1);
        result.push_back(0);
    }
    if (n % 2 != 0)
    {
        result.push_back(2);
    }
    if (result[x - 1] == result[y - 1] && x != y)
    {
        if (n % 2 == 0)
        {
            result[x - 1] = 2;
        }
        else
        {
            if (x != n - 1 && x != 1)
            {
                result[x - 1] = 2;
                if (x == 2)
                {
                    result[0] = 0;
                    result[n - 1] = 1;
                }
            }
            else
            {
                result[y - 1] = 2;
                if (y == 2)
                {
                    result[0] = 0;
                    result[n - 1] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int INP;
    cin >> INP;
    while (INP--)
    {
        solve();
    }
    return 0;
}
