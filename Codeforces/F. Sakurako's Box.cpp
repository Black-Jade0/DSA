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
using mpii = map<int, int>;
using mpci = map<char, int>;
using mpcl = map<char, ll>;
using mpsi = map<string, int>;
using mpsl = map<string, ll>;
using mpll = map<ll, ll>;
using mpii = map<int, int>;
using mpipii = map<int, pair<int, int>>;
using mpllpllll = map<ll, pair<ll, ll>>;
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

const int mod = 1e9 + 7;

ll calc(ll num, int exp)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp & 1)
        {
            result = (1LL * result * num) % mod;
        }
        num = (1LL * num * num) % mod;
        exp /= 2;
    }
    return result;
}

void solve()
{
    ll sum = 0;
    ll sqsum = 0;

    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum = (sum + a[i]) % mod;
        sqsum = (sqsum + ((1LL * a[i] * a[i]) % mod)) % mod;
    }

    sum = (1LL * sum * sum) % mod;

    ll diff = (sum - sqsum + mod) % mod;

    ll deno = (1LL * n * (n - 1)) % mod;
    deno = calc(deno, mod - 2);

    ll ans = (1LL * diff * deno) % mod;
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