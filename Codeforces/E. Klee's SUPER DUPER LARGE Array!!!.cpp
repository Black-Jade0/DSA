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

ll val(ll mid, ll k, ll n)
{
    ll val1 = (mid + k - 1 + k) * mid / 2;
    ll val2 = (k + n - 1 + k) * n / 2 - val1;
    return val1 - val2;
}

void solve()
{

    ll n, k;
    cin >> n >> k;

    ll lo = 1, hi = n, curr = 1;

    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        ll diff = val(mid, k, n);

        if (diff < 0)
        {
            curr = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    ll diff1 = abs(val(curr, k, n));
    ll diff2 = abs(val(curr + 1, k, n));

    cout << min(diff1, diff2) << endl;
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