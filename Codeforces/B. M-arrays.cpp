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
const ll mod = 1e9 + 7;

void solve()
{
    inc(n);
    inc(m);
    viac(n, a);
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] % m;
    }
    mpii track;
    for (int i = 0; i < n; i++)
    {
        track[a[i]]++;
    }
    ll ans = 0;
    ans += (track.count(0) > 0 ? 1 : 0);
    track.erase(0);
    if (!(m  & 1) && track.count(m / 2))
    {
        ans++;
        track.erase(m/ 2);
    }
    for (auto &x : track)
    {
        if (m - x.first < x.first && x.second > 0)
        {
            ans += x.second;
        }
        else if (x.second > 0)
        {
            if (track.count(m - x.first))
            {
                ans++;
                int temp = min(x.second, track[m - x.first]) + 1;
                x.second -= temp;
                track[m - x.first] -= temp;
            }
            if (x.second > 0)
            {
                ans += x.second;
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
    ll INT;
    cin >> INT;
    while (INT)
    {
        solve();
        INT--;
    }
    return 0;
}