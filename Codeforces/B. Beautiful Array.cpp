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
using spii = set<pii>;
using mpii = map<int, int>;
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
    // ll n, k, b, s;
    // cin >> n >> k >> b >> s;
    // if (1LL * k * b > s)
    // {
    //     cout << -1 << endl;
    //     return;
    // }
    // ll first = ((1LL * b) / n) * k;
    // ll last = (((1LL * b) / n) * k) + (((1LL * b) % n) * k);
    // ll sumleft = s - (1LL * k * b);

    // if (1LL * (1LL * (n) * (k - 1)) - ((1LL * k * b) % n) < sumleft)
    // {
    //     cout << -1 << endl;
    //     return;
    // }
    // for (ll i = 0; i < n - 1; i++)
    // {
    //     cout << first + (sumleft <= (k - 1) ? sumleft : k - 1) << " ";
    //     sumleft -= (sumleft <= (k - 1) ? sumleft : k - 1);
    // }
    // cout << last + (sumleft <= (k - 1) ? sumleft : k - 1) << " ";
    // cout << endl;
    // return;

    // DONT KNOW WHATS WRONG, PROBABLY OUT OF BONDS ANYTHERE

    // IT WAS SIMPLE, JUST PUT THE FIRST ELEMENT AS K * B; THUS COMPLETING THE BEAUTY REQUIREMENT
    // THEN COMPLETE THE LEFT SUM

    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    vll a(n);
    a[0] = 1LL * k * b;
    s -= 1LL * k * b;
    if (s < 0)
        cout << "-1\n";
    else
    {
        for (int i = 0; i < n; ++i)
        {
            int now = min(k - 1, s);
            a[i] += now;
            s -= now;
        }
        if (s > 0)
            cout << "-1\n";
        else
        {
            for (int i = 0; i < n; ++i)
            {
                cout << a[i] << " ";
            }
            cout << "\n";
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int INP;
    cin >> INP;
    while (INP--)
    {
        solve();
    }
    return 0;
}