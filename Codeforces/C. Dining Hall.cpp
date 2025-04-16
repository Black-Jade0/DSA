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
#define s(x) sort((x).begin(), (x).end())
#define sg(x) sort((x).begin(), (x).end(), greater<int>{})
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

spii track;

void t1(pii &i)
{
    if ((i.first - 1) % 3 == 0 && (i.second - 1) % 3 == 0)
    {
        int ti = (i.first - 1) / 3;
        int tj = (i.second - 1) / 3;
        if (tj == 0)
        {
            i.second = (3 * ti) + 2;
            i.first = 1;
        }
        else
        {
            ti++;
            tj--;
            i.first = (3 * ti) + 1;
            i.second = (3 * tj) + 1;
        }
    }
    else if ((i.first - 1) % 3 == 0 && (i.second - 2) % 3 == 0)
    {
        i.first++;
        i.second = max(1, i.second - 3);
    }
    else if ((i.first - 2) % 3 == 0 && (i.second - 1) % 3 == 0)
    {
        int ti = (i.first - 1) / 3;
        int tj = (i.second - 1) / 3;
        if (i.second == 1)
        {
            tj = ti + 1;
            ti = 0;
            i.first = (3 * ti) + 1;
            i.second = (3 * tj) + 1;
        }
        else
        {
            ti++;
            tj--;
            i.first = (3 * ti) + 1;
            i.second = (3 * tj) + 2;
        }
    }
    else
    {
        i.second += 2;
    }
    if (track.count(i))
    {
        t1(i);
    }
    else
    {
        track.insert(i);
    }
    return;
}

void t2(pii &j)
{
    int ti = (j.first - 1) / 3;
    int tj = (j.second - 1) / 3;
    if (tj == 0)
    {
        tj = ti + 1;
        ti = 0;
        j.second = (3 * tj) + 1;
        j.first = 1;
    }
    else
    {
        ti++;
        tj--;
        j.first = (3 * ti) + 1;
        j.second = (3 * tj) + 1;
    }
    if (track.count(j))
    {
        t2(j);
    }
    else
    {
        track.insert(j);
    }
    return;
}

void solve()
{
    inc(n);
    viac(n, a);
    track.clear();
    pii i = {1, 1};
    pii j = {1, 1};
    cout << i.first << " " << i.second << endl;
    track.insert({1, 1});
    for (int k = 1; k < n; k++)
    {
        if (a[k] == 1)
        {
            t1(i);
            cout << i.first << " " << i.second << endl;
        }
        else
        {
            t2(j);
            cout << j.first << " " << j.second << endl;
        }
    }
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