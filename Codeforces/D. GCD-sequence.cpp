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

int help(vi a)
{
    int pre = __gcd(a[0], a[1]);
    for (int i = 1; i < a.size() - 1; i++)
    {
        int curr = __gcd(a[i], a[i + 1]);
        if (curr < pre)
        {
            return 0;
        }
        pre = curr;
    }
    return 1;
}
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    fi(i, n)
    {
        cin >> a[i];
    }
    int pre = __gcd(a[0], a[1]);
    int index =  -1;
    for (int i = 1; i < a.size() - 1; i++)
    {
        int curr = __gcd(a[i], a[i + 1]);
        if (curr < pre)
        {
            index = i;
            break;
        }
        pre = curr;
    }

    if (index == -1)
    {
        cout << "YES" << endl;
        return;
    }
    
    vi b = a, c = a, d = a;

    b.erase(b.begin() + index - 1);
    c.erase(c.begin() + index);
    d.erase(d.begin() + index + 1);

    if (help(b) || help(c) || help(d))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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