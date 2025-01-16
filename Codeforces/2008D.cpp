#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> s;

    vector<bool> visited(n, false); 
    vector<int> result(n, 0);       

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            cout << result[i] << " ";
            continue; 
        }

        set<int> cycle; 
        int j = i;
        int count_black = 0;

        while (!cycle.count(j) && !visited[j])
        {
            cycle.insert(j);
            visited[j] = true;
            if (s[j] == '0')
            {
                count_black++;
            }
            j = a[j] - 1;
        }

        for (int x : cycle)
        {
            result[x] = count_black;
        }

        cout << count_black << " ";
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
