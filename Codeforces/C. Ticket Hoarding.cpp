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
    ll m, k;
    cin >> m >> k;
    vi b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    ll req = (1LL * k + m - 1) / m;
    vi a = b;
    sort(b.begin(), b.end());
    if (k <= m)
    {
        cout << b[0] * k << endl;
        return;
    }
    int gnum = b[req - 1];
    mpii days;
    for (int i = 0; i < req; i++)
    {
        days[b[i]]++;
    }
    int done = 0;
    int i = 0;
    ll ans = 0;
    while (i < n && k > 0)
    {
        if (days[a[i]])
        {
            days[a[i]]--;
            int temp = (gnum > a[i] ? m : (1LL * (k % m) ? (k % m) : m));
            ans += 1LL * (done + a[i]) * temp;
            done += temp;
            k -= temp;
        }
        i++;
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