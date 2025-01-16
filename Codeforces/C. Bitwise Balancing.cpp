#include <bits/stdc++.h>
#include <cmath>

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
    ll a = 0, b, c, d;
    cin >> b >> c >> d;

    ll i = 0;
    while (d > 0 || b > 0 || c > 0)
    {
        if (d & 1)
        {
            if (!(b & 1) && (c & 1))
            {
                cout << -1 << endl;
                return;
            }
            else if (!(b & 1) && !(c & 1))
            {
                a += (1LL << i);
            }
        }
        else
        {
            if ((b & 1) && (c & 1))
            {
                a += (1LL << i);
            }
            else if (!(c & 1) && (b & 1))
            {
                cout << -1 << endl;
                return;
            }
        }
        i++;
        b >>= 1;
        c >>= 1;
        d >>= 1;
    }
    cout << a << endl;
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