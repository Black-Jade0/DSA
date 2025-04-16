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
    inc(n);
    vs a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int p = a[i][j] - '0';
            int q = a[j][n - i - 1] - '0';
            int r = a[n - i - 1][n - j - 1] - '0';
            int s = a[n - j - 1][i] - '0';
            ll temp = p + q + r + s;
            if (p + q + r + s == 0 || p + q + r + s == 4)
            {
                continue;
            }
            else if (temp == 1 || temp == 3)
            {
                ans++;
            }
            else
            {
                ans += 2;
            }
        }
    }
    if (n & 1)
    {
        for (int i = 0; i < n / 2; i++)
        {
            int p = a[i][n / 2] - '0';
            int q = a[n / 2][i] - '0';
            int r = a[n / 2][n - i - 1] - '0';
            int s = a[n - i - 1][n / 2] - '0';
            ll temp = p + q + r + s;
            if (temp == 0 || temp == 4)
            {
                continue;
            }
            else if (temp == 1 || temp == 3)
            {
                ans++;
            }
            else
            {
                ans += 2;
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