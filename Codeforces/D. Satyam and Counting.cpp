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

void solve()
{
    int n;
    cin >> n;

    set<int> one;
    set<int> zero;
    int a;
    int b;
    int count = 0;
    int cross = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        cin >> b;
        if (one.count(a) || zero.count(a))
        {
            count++;
        }
        if (b)
        {
            if (zero.count(a - 1) && zero.count(a + 1))
            {
                cross++;
            }
            if (zero.count(a - 1) && one.count(a - 2))
            {
                cross++;
            }
            if (zero.count(a + 1) && one.count(a + 2))
            {
                cross++;
            }
            one.insert(a);
        }
        else
        {
            if (one.count(a - 1) && one.count(a + 1))
            {
                cross++;
            }
            if (one.count(a - 1) && zero.count(a - 2))
            {
                cross++;
            }
            if (one.count(a + 1) && zero.count(a + 2))
            {
                cross++;
            }
            zero.insert(a);
        }
    }

    ll ans = (1LL * count * (one.size() - 1)) + (1LL * count * (zero.size() - 1)) + cross;
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