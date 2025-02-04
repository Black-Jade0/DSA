#include <bits/stdc++.h>
#include <cmath>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pllll = pair<ll, ll>;
using vi = vector<int>;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vpii = vector<pair<int, int>>;
using vpllll = vector<pair<ll, ll>>;
using si = set<int>;
using spii = set<pii>;
using mpii = map<int, int>;
using mpgii = map<int, int, greater<int>>;
using mpci = map<char, int>;
using mpcl = map<char, ll>;
using mpsi = map<string, int>;
using mpsl = map<string, ll>;
using mpll = map<ll, ll>;
using mpii = map<int, int>;
using mpipii = map<int, pair<int, int>>;
using mpllpllll = map<ll, pair<ll, ll>>;
using mppiivi = map<pii, vi>;
using mppiimpii = map<pii, mpii>;
using pqi = priority_queue<int>;
using pqgi = priority_queue<int, vi, greater<int>>;
using mpcpqi = map<char, pqi>;
using mpcpqgi = map<char, pqgi>;
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

const int mod = 998244353;

ll dp[200005][2];
void solve()
{
    ll n;
    cin >> n;
    vll v;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v.push_back(a);
        dp[i][0] = dp[i][1] = 0;
    }
    if (n == 1)
    {
        if (v[0] == 0)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
        return;
    }
    map<vll, ll> odp;
    if (v[0] != 0)
    {
        dp[1][1] = 1;
        odp[{1, 1}] = 1;
    }
    else
    {
        dp[0][0] = 1;
        dp[1][1] = 1;
        odp[{0, 0}] = 1;
        odp[{1, 1}] = 1;
    }
    for (ll i = 1; i < n; i++)
    {
        map<vll, ll> ndp;
        ndp[{v[i], 0}] = (odp[{v[i], 0}] + odp[{v[i], 1}]) % mod;
        ndp[{v[i - 1] + 1, 1}] = odp[{v[i - 1], 0}];
        odp = ndp;
    }
    cout << (odp[{v[n - 2] + 1, 1}] + odp[{v[n - 1], 0}]) % mod << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}