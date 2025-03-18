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
using mpipipqi = map<int, pair<int, pqi>>;
using mpgipii = map<int, pair<int, int>, greater<int>>;
using mpllpllll = map<long long, pair<long long, long long>>;
using mppiivi = map<pii, vi>;
using mppiimpii = map<pii, mpii>;

#define ilen(a) (int)a.size()
#define llen(a) (ll) a.size()
#define all(x) (x).begin(), (x).end()
#define fi(i, j, n) for (int i = j; i < n; i++)
#define fll(i, j, n) for (ll i = j; i < n; i++)
#define fla(i, a, b) for (ll i = (a); i <= (b); i++)
#define inc(n) \
    int n;     \
    cin >> n;
#define llnc(n) \
    ll n;       \
    cin >> n;
#define viac(a, n)                \
    vi a(n);                      \
    for (int i = 0; i < (n); i++) \
    {                             \
        cin >> a[i];              \
    }
#define vllac(a, n)               \
    vll a(n);                     \
    for (int i = 0; i < (n); i++) \
    {                             \
        cin >> a[i];              \
    }
#define siac(a, n)                \
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
const int mod = 1e9 + 7;

void solve()
{
    inc(n);
    inc(k);
    viac(a, n);
    mpipipqi track;
    for (int i = 0; i < n; i++)
    {
        int last = track.count(a[i]) ? track[a[i]].first : -1;
        int curr = i - last - 1;
        if (curr > 0)
        {
            track[a[i]].second.push(curr);
        }
        track[a[i]].first = i;
    }
    int ans = intmax;
    for (auto &x : track)
    {
        int curr = n - x.second.first - 1;
        if (curr > 0)
        {
            x.second.second.push(curr);
        }
        int first = x.second.second.size() ? x.second.second.top() : 0;
        if (first)
        {
            x.second.second.pop();
        }
        first = first / 2;
        int second = x.second.second.size() ? x.second.second.top() : 0;
        ans = min(ans, max(first, second));
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