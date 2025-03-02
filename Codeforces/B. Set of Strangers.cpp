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
using si = set<int>;
using sll = set<ll>;
using spii = set<pii>;
using sti = stack<int>;
using qi = queue<int>;
using mpii = map<int, int>;
using mpllll = map<ll, ll>;
using mpgllll = map<ll, ll, greater<int>>;
using mpivi = map<int, vi>;
using mpci = map<char, int>;
using mpcl = map<char, ll>;
using mpcvi = map<char, vi>;
using mpsi = map<string, int>;
using mpsl = map<string, ll>;
using mpll = map<ll, ll>;
using mpii = map<int, int>;
using mpipii = map<int, pair<int, int>>;
using mpllpllll = map<long long, pair<long long, long long>>;
using mppiivi = map<pii, vi>;
using mppiimpii = map<pii, mpii>;
using pqi = priority_queue<int>;
using pqgi = priority_queue<int, vi, greater<int>>;
using pqpii = priority_queue<pii>;
using pqgpii = priority_queue<pii, vpii, greater<pii>>;
#define ilen(a) (int)a.size()
#define llen(a) (ll) a.size()
#define all(x) (x).begin(), (x).end()
#define fi(i, j, n) for (int i = j; i < n; i++)
#define fl(i, j, n) for (ll i = j; i < n; i++)
#define fla(i, a, b) for (ll i = (a); i <= (b); i++)
#define nc(n) \
    int n;    \
    cin >> n;
#define viac(a, n)                \
    vi a(n);                      \
    for (int i = 0; i < (n); i++) \
    {                             \
        cin >> a[i];              \
    }
const char nl = '\n';
const int intmax = INT_MAX;
const int intmin = INT_MIN;
const ll llmax = LLONG_MAX;
const ll llmin = LLONG_MIN;

void solve()
{
    nc(n);
    nc(m);
    vvi a(n, vi(m));
    fi(i, 0, n)
    {
        fi(j, 0, m)
        {
            cin >> a[i][j];
        }
    }
    map<int, set<pii>> track;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            track[a[i][j]].insert({i, j});
        }
    }
    spii t;
    for (auto x : track)
    {
        spii temp = x.second;
        bool done = false;
        for (auto y : temp)
        {
            if (temp.count({y.first - 1, y.second}) || temp.count({y.first + 1, y.second}) || temp.count({y.first, y.second + 1}) || temp.count({y.first, y.second - 1}))
            {
                t.insert({x.first, 2});
                done = true;
                break;
            }
        }
        if (!done)
        {
            t.insert({x.first, 1});
        }
    }
    ll ans = 0;
    if (t.size() == 1)
    {
        cout << 0 << endl;
        return;
    }
    bool lol = false;
    for (auto x : t)
    {
        ans += x.second;
        if (x.second == 2)
        {
            lol = true;
        }
    }
    if (lol)
    {
        cout << ans - 2 << endl;
        return;
    }
    else{
        cout << ans - 1 << endl;
        return; 
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll INT;
    cin >> INT;
    while (INT)
    {
        solve();
        INT--;
    }

    return 0;
}