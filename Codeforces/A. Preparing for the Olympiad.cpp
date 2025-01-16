#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> m(n), s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (m[i] > s[i + 1])
        {
            ans += m[i] - s[i + 1];
        }
    }
    ans += m[n - 1];
    cout << ans << endl;
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