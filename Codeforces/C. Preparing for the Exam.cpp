#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> list(m);
    set<int> known;
    string ans;
    for (int i = 0; i < m; i++)
    {
        cin >> list[i];
    }
    for (int i = 0; i < k; i++)
    {
        int inp;
        cin >> inp;
        known.insert(inp);
    }
    if (k < n-1)
    {
        for (int i = 0; i < m; i++)
        {
            ans.push_back('0');
        }
        cout << ans << endl;
        return;
    }
    if (k == n)
    {
        for (int i = 0; i < m; i++)
        {
            ans.push_back('1');
        }
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < m; i++)
    {
        if (known.count(list[i]))
        {
            ans.push_back('0');
        }
        else{
            ans.push_back('1');
        }
    }
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