#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m , k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            int count = 0;
            while (i < n && s[i] == '0')
            {
                count++;
                if (count == m)
                {
                    result++;
                    count = 0;
                    i+= k;
                    continue;
                }
                i++;
            }
        }
    }
    cout << result << endl;
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