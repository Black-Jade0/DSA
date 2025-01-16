#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pllll = pair<long long, long long>;
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vpii = vector<pair<int, int>>;
using vpllll = vector<pair<long long, long long>>;
using mpii = map<int, int>;
using mpci = map<char, int>;
using mpcl = map<char, ll>;
using mpsi = map<string, int>;
using mpsl = map<string, ll>;
using mpll = map<ll, ll>;
using mpii = map<int, int>;
using mpipii = map<int, pair<int, int>>;
using mpllpllll = map<long long, pair<long long, long long>>;
using pqi = priority_queue<int>;
#define ilen(a) (int)a.size()
#define llen(a) (ll) a.size()
#define all(x) (x).begin(), (x).end()
#define fi(i, n) for (int i = 0; i < n; i++)
#define fl(i, n) for (ll i = 0; i < n; i++)
#define fla(i, a, b) for (ll i = (a); i <= (b); i++)
const char nl = '\n';
const int intmax = INT_MAX;
const int intmin = INT_MIN;
const ll llmax = LLONG_MAX;
const ll llmin = LLONG_MIN;

void solve()
{
    int n, m;
    cin >> n >> m;
    vs a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vs layer(min(n, m) / 2, "");
    for (int i = 0; i < min(n, m) / 2; i++)
    {
        for (int j = i; j < m - i; j++)
        {
            layer[i].push_back(a[i][j]);
        }
        for (int j = i + 1; j < n - i; j++)
        {
            layer[i].push_back(a[j][m - i - 1]);
        }
        for (int j = m - i - 2; j >= i; j--)
        {
            layer[i].push_back(a[n - i - 1][j]);
        }
        for (int j = n - i - 2; j > i; j--)
        {
            layer[i].push_back(a[j][i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < min(n, m) / 2; i++)
    {
        string s = layer[i];
        string check = s.substr(0, 3);
        int l = s.length();
        for (int j = 0; j < l; j++)
        {
            check.push_back(s[(j + 3) % l]);
            if (check == "1543")
            {
                ans++;
            }
            check.erase(0,1);
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