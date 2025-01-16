#include <bits/stdc++.h>
#include <cmath>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pllll = pair<ll, ll>;
using vi = vector<int>;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vpii = vector<pair<int, int>>;
using vpllll = vector<pair<ll, ll>>;
using si = set<int>;
using mpii = map<int, int>;
using mpci = map<char, int>;
using mpcl = map<char, ll>;
using mpsi = map<string, int>;
using mpsl = map<string, ll>;
using mpll = map<ll, ll>;
using mpii = map<int, int>;
using mpipii = map<int, pair<int, int>>;
using mpllpllll = map<ll, pair<ll, ll>>;
using pqi = priority_queue<int>;
#define ilen(a) (int)a.size()
#define llen(a) (ll) a.size()
#define all(x) (x).begin(), (x).end()
#define fi(i, n) for (int i = 0; i < n; i++)
#define fl(i, n) for (ll i = 0; i < n; i++)
#define fla(i, a, b) for (ll i = (a); i <= (b); i++)
const char nl = '\n';
const int intmax = INT_MAX;
const int intmin = INT_MIN;
const ll llmax = LLONG_MAX;
const ll llmin = LLONG_MIN;

int makenum(int a, int k)
{
    int res;
    if (a + k - 1 < 2 * k)
    {
        res = (1 << k) - 1;
        res <<= (2 * k) - a - k;
        return res;
    }
    res = (1 << k) - 1;
    res <<= ((2 * k) - a);
    int help = (1 << (2 * k)) - 1;
    res = help ^ res;
    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    si a;
    int num = intmin;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        a.insert(b % (2 * k));
        num = max(num, b);
    }

    int x = (1 << (2 * k)) - 1;

    for (auto curr : a)
    {
        x = x & makenum(curr, k);
    }
    if (x == 0)
    {
        cout << -1 << endl;
        return;
    }
    int msb = 0;
    int i = 1;
    while (x)
    {
        if (x & 1)
        {
            msb = i;
        }
        x >>= 1;
        i++;
    }
    ll result = (2 * k) - msb;
    if (result == 0)
    {
        result--;
    }
    result = (1LL * (num / (2 * k)) * (2 * k)) + result;
    cout << result << endl;
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