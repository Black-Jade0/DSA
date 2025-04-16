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
    inc(q);
    ll sum = 0;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int prim = -1;
    mpii b;
    fi(i, 0, q)
    {
        int temp1;
        int temp2;
        cin >> temp1;
        cin >> temp2;
        if (temp1 == 2)
        {
            b.clear();
            prim = temp2;
            sum = 1LL * prim * n;
            cout << sum << endl;
        }
        else
        {
            int temp3;
            cin >> temp3;
            if (b.find(temp2) != b.end())
            {
                sum -= b[temp2];
            }
            else
            {
                if (prim > 0)
                {
                    sum -= prim;
                }
                else
                {
                    sum -= a[temp2 - 1];
                }
            }
            sum += temp3;
            b[temp2] = temp3;
            cout << sum << endl;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // ll INT;
    // cin >> INT;
    // while (INT)
    // {
    solve();
    // INT--;
    // }

    return 0;
}