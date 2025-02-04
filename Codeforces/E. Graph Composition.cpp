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

vi f(200005), g(200005), u(200005), v(200005);
int n, m1, m2;

int putf(int x)
{
    if (x == f[x])
    {
        return x;
    }
    else
    {
        return f[x] = putf(f[x]);
    }
}
int putg(int x)
{
    if (x == g[x])
    {
        return x;
    }
    else
    {
        return g[x] = putg(g[x]);
    }
}

void solve()
{
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= n; i++)
    {
        f[i] = g[i] = i;
    }
    for (int i = 1; i <= m1; i++)
    {
        cin >> u[i] >> v[i];
    }
    for (int i = 1; i <= m2; i++)
    {
        int x, y;
        cin >> x >> y;
        g[putg(x)] = putg(y);
    }
    int ans = 0;
    for (int i = 1; i <= m1; i++)
    {
        if (putg(u[i]) != putg(v[i]))
        {
            ans++;
        }
        else{
            f[putf(u[i])] = putf(v[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans += (f[i] == i) - (g[i] == i);
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