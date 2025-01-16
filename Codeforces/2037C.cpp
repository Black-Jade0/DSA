#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n < 5)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n;)
    {
        if (i == 5)
        {
            i += 2;
            continue;
        }
        cout << i << " ";
        i += 2;
    }
    cout << 5 << " ";
    cout << 4 << " ";
    for (int i = 2; i <= n;)
    {
        if (i == 4)
        {
            i+= 2;
            continue;
        }
        cout << i << " ";
        i += 2;
    }
    cout << endl;
    return;
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