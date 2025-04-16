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
using vpipii = vector<pair<int, pii>>;
using vpllll = vector<pair<long long, long long>>;
using pqi = priority_queue<int>;
using pqgi = priority_queue<int, vi, greater<int>>;
using pqpii = priority_queue<pii>;
using pqgpii = priority_queue<pii, vpii, greater<pii>>;
using si = set<int>;
using sll = set<ll>;
using ss = set<string>;
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
using mpgii = map<int, int, greater<int>>;
using mpipii = map<int, pair<int, int>>;
using mppiii = map<pair<int, int>, int>;
using mpgipii = map<int, pair<int, int>, greater<int>>;
using mpipipqgi = map<int, pair<int, pqgi>>;
using mpllpllll = map<long long, pair<long long, long long>>;
using mppiivi = map<pii, vi>;
using mppiimpii = map<pii, mpii>;

#define ilen(a) (int)a.size()
#define llen(a) (ll) a.size()
#define all(x) (x).begin(), (x).end()
#define svi(x) sort((x).begin(), (x).end())
#define sgvi(x) sort((x).begin(), (x).end(), greater<int>{})
#define sgvpii(x) sort((x).begin(), (x).end(), greater<pii>{})
#define fi(i, j, n) for (int i = j; i < n; i++)
#define fl(i, j, n) for (ll i = j; i < n; i++)
#define fla(i, a, b) for (ll i = (a); i <= (b); i++)
#define inc(n) \
    int n;     \
    cin >> n;
#define llnc(n) \
    ll n;       \
    cin >> n;
#define viac(n, a)                \
    vi a(n);                      \
    for (int i = 0; i < (n); i++) \
    {                             \
        cin >> a[i];              \
    }

#define vllac(n, a)              \
    vll a(n);                    \
    for (ll i = 0; i < (n); i++) \
    {                            \
        cin >> a[i];             \
    }

#define siac(n, a)                \
    si a;                         \
    int TEMP;                     \
    for (int i = 0; i < (n); i++) \
    {                             \
        cin >> TEMP;              \
        a.insert(TEMP);           \
    }

const char nl = '\n';
const int intmax = INT_MAX;
const int intmin = INT_MIN;
const ll llmax = LLONG_MAX;
const ll llmin = LLONG_MIN;
const ll mod = 998244353;

ll ans;
ll n;
ll m;
ll d;
mppiii track;

ll help(vs &a, ll i, ll j, ll f)
{
    ll curr = 0;
    if (i == 0 && f == 0)
    {
        return 1;
    }
    if (f == 1)
    {
        int temp1 = max(0LL, j - d);
        int temp2 = min(m - 1, j + d);
        while (temp1 <= temp2)
        {
            if (a[i][temp1] == 'X')
            {
                if (track.count({i, temp1}))
                {
                    curr = (curr + track[{i, temp1}]) % mod;
                }
                else
                {
                    curr = (curr + help(a, i, temp1, 0)) % mod;
                }
            }
            temp1++;
        }
    }
    else
    {
        int temp = sqrt(d * d - 1);
        int temp1 = j - temp;
        int temp2 = j + temp;
        while (temp1 <= temp2)
        {
            if (a[i - 1][temp1] == 'X')
            {
                curr = (curr + help(a, i - 1, temp1, 1)) % mod;
            }
            temp1++;
        }
    }
    if (f == 0)
    {
        track[{i, j}] = (curr % mod);
    }
    return curr;
}

void solve()
{
    cin >> n;
    cin >> m;
    cin >> d;
    vs a(n);
    ans = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    track.clear();
    for (ll i = 0; i < m; i++)
    {
        if (a[n - 1][i] == 'X')
        {
            ans = (ans + help(a, n - 1, i, 1)) % mod;
        }
    }
    cout << ans << endl;
    return;
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