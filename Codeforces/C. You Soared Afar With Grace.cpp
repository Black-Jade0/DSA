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

void solve()
{
    inc(n);
    viac(n, a);
    viac(n, b);
    int help = -1;
    if (n & 1)
    {
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i] && flag)
            {
                help = i;
                flag = false;
            }
            else if (a[i] == b[i])
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    if ((n & 1) && help == -1)
    {
        cout << -1 << endl;
        return;
    }
    spii temp;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] == b[i] && (n & 1)) || temp.count({b[i], a[i]}))
        {
            temp.erase({b[i], a[i]});
            continue;
        }
        else
        {
            temp.insert({a[i], b[i]});
        }
    }
    if (!temp.empty())
    {
        cout << -1 << endl;
        return;
    }
    mpii track;
    for (int i = 0; i < n; i++)
    {
        track[a[i]] = i;
    }
    vpii ans;
    if ((n & 1) && help != ((n + 1) / 2) - 1)
    {
        int h = a[help];
        a[help] = a[((n + 1) / 2) - 1];
        b[help] = b[((n + 1) / 2) - 1];
        a[((n + 1) / 2) - 1] = h;
        b[((n + 1) / 2) - 1] = h;
        track[h] = ((n + 1) / 2) - 1;
        track[a[help]] = help;
        ans.push_back({help + 1, (n + 1) / 2});
    }

    for (int i = 0; i < (n + 1) / 2; i++)
    {
        int first = a[i];
        int second = b[i];
        if (track[second] + 1 == n - i)
        {
            continue;
        }
        ans.push_back({track[second] + 1, n - i});
        // cout << track[b[i]] + 1 << " " << n - i << endl;
        int ind = track[second];
        int temp1 = a[ind];
        int temp2 = b[ind];
        a[ind] = a[n - i - 1];
        b[ind] = b[n - i - 1];
        a[n - i - 1] = temp1;
        b[n - i - 1] = temp2;
        track[second] = n - i - 1;
        track[a[ind]] = ind;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
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