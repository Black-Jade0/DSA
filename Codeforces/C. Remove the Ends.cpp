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
const char nl = '\n';
const int intmax = INT_MAX;
const int intmin = INT_MIN;
const ll llmax = LLONG_MAX;
const ll llmin = LLONG_MIN;

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vll b;
    ll cur = 0;
    for (int i = 0; i < n;)
    {
        cur = 0;
        while (i < n && a[i] < 0)
        {
            cur += a[i];
            i++;
        }
        if (cur != 0)
        {
            b.push_back(cur);
        }
        cur = 0;
        while (i < n && a[i] > 0)
        {
            cur += a[i];
            i++;
        }
        if (cur != 0)
        {
            b.push_back(cur);
        }
    }
    ll ans = 0;
    if (b[0] > 0)
    {
        ans += b[0];
        b.erase(b.begin());
    }
    if (b.size() > 0 && b[b.size() - 1] < 0)
    {
        ans -= b[b.size() - 1];
        b.erase(b.end() - 1);
    }
    if (b.size() == 0)
    {
        cout << ans << endl;
        return;
    }
    ll neg = 0;
    ll pos = 0;
    ll curr = 0;
    ll temp = 0;
    int i = 0;
    while (i < b.size())
    {
        temp += b[i];
        i += 2;
    }
    curr = -temp;
    neg = -temp;
    n = b.size();
    i = n - 1;
    temp = 0;
    while (i >= 0)
    {
        temp += b[i];
        i -= 2;
    }
    if (temp > curr)
    {
        curr = temp;
    }
    temp = 0;
    i = 1;
    while (i < n)
    {
        neg += b[i - 1];
        pos += b[i];
        if (curr < pos + neg)
        {
            curr = pos + neg;
        }
        i += 2;
    }
    cout << ans + curr << endl;
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