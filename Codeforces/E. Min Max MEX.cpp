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
using usi = unordered_set<int>;
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
ll ans;

void solve()
{
    llnc(n);
    llnc(k);
    vllac(n, a);
    ll front = 0;
    ll back = (n / k) + 1;
    ll ans = -1;
    mpii fcheck;
    for (int i = 0; i < n; i++)
    {
        fcheck[a[i]]++;
    }
    ll help = 0;
    for (auto x : fcheck)
    {
        if (x.second < k)
        {
            break;
        }
        else
        {
            help = x.first;
        }
    }
    back = min(back, help + 1);
    while (front <= back)
    {
        ll mid = (front + back) / 2;
        ll i = 0;
        usi track;
        ll temp = k;
        while (i < n && temp > 0)
        {
            if (!track.count(a[i]) && a[i] < mid)
            {
                track.insert(a[i]);
            }
            if (track.size() == mid)
            {
                temp--;
                track.clear();
            }
            i++;
        }
        if (temp <= 0)
        {
            ans = max(ans, mid);
            front = mid + 1;
        }
        else
        {
            back = mid - 1;
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