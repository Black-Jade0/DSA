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

string ans;
int n, m, k;
char a, b;
void solve()
{
    cin >> n >> m >> k;
    ans.clear();

    if (n == 0)
    {
        if (m > k)
        {
            cout << "-1\n";
            return;
        }
        ans.assign(m, '1');
        cout << ans << '\n';
        return;
    }

    if (m == 0)
    {
        if (n > k)
        {
            cout << "-1\n";
            return;
        }
        ans.assign(n, '0');
        cout << ans << '\n';
        return;
    }

    if (n > m)
    {
        a = '0';
        b = '1';
    }
    else
    {
        a = '1';
        b = '0';
    }

    int x = max(n, m);
    int y = min(n, m);

    if (x - y > k || k > x)
    {
        cout << "-1" << endl;
        return;
    }

    ans.append(k, a);

    x -= k;
    int i = x;

    while (i--)
    {
        ans += b;
        ans += a;
    }

    y -= x;
    if (y > 0)
        ans.append(y, b);

    cout << ans << endl;
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