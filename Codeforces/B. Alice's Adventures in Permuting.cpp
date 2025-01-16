#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pllll = pair<long long, long long>;
using vi = vector<int>;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
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
    ll n, b, c;
    cin >> n >> b >> c;
    if (n == 1)
    {
        cout << ((c == 0) ? 0 : 1) << endl;
        return;
    }
    if (b == 0 && c == 0)
    {
        cout << ((n == 2) ? 1 : -1) << endl;
        return;
    }
    if (b == 0)
    {
        if (c < n - 2)
        {
            cout << -1 << endl;
            return;
        }
        if (c < n)
        {
            cout << n - 1 << endl;
            return;
        }
        else
        {
            cout << n << endl;
            return;
        }
    }
    if (c >= n - 1)
    {
        cout << ((c == (n - 1)) ? (n - 1) : n);
        cout << endl;
        return;
    }

    ll x = ((1LL * (n - c - 1)) / b) + 1;
    cout << n - x << endl;
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