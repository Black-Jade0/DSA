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
#define svi(a) sort(a.begin(), a.end())
#define svig(a) sort(a.begin(), a.end(), greater<int>{})
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
    llnc(n);
    llnc(m);
    vll b(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    vll check;
    svi(b);
    for (int i = 1; i < m; i++)
    {
        if (b[i] - b[i - 1] - 1 > 0)
        {
            check.push_back(b[i] - b[i - 1] - 1);
        }
    }
    if (n - b[m - 1] + b[0] - 1 > 0)
    {
        check.push_back(n - b[m - 1] + b[0] - 1);
    }

    svig(check);
    ll i = 0;
    ll j = 0;
    ll ans = 0;
    while (i < check.size())
    {
        ll temp = check[i];
        if (temp - j > 0)
        {
            ll tem = max(temp - j - 1, 1LL);
            ans += tem;
            if (tem == 1)
            {
                j += 2;
            }
            else
            {
                j += 4;
            }
        }
        i++;
    }
    cout << (n - ans) << endl;
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