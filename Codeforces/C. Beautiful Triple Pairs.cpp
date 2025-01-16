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
    int n;
    cin >> n;
    vi a(n);
    fi(i, n)
    {
        cin >> a[i];
    }
    mppiimpii dfor;
    mppiimpii dback;
    mppiimpii tin;

    for (int i = 0; i < n - 2; i++)
    {
        dfor[{a[i], a[i + 1]}][a[i + 2]]++;
    }
    for (int i = 1; i < n - 1; i++)
    {
        dback[{a[i], a[i + 1]}][a[i - 1]]++;
    }
    for (int i = 0; i < n - 2; i++)
    {
        tin[{a[i], a[i + 2]}][a[i + 1]]++;
    }

    ll ans = 0;
    for (auto x : dfor)
    {
        if (x.second.size() > 1)
        {
            int i = 0;
            for (auto y : x.second)
            {
                ans += y.second * i;
                i += y.second;
            }
        }
    }
    for (auto x : dback)
    {
        if (x.second.size() > 1)
        {
            int i = 0;
            for (auto y : x.second)
            {
                ans += y.second * i;
                i += y.second;
            }
        }
    }
    for (auto x : tin)
    {
        if (x.second.size() > 1)
        {
            int i = 0;
            for (auto y : x.second)
            {
                ans += y.second * i;
                i += y.second;
            }
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