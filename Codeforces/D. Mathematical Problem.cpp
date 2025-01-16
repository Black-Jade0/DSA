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

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 2)
    {
        cout << stoi(s) << endl;
        return;
    }
    if (n >= 3)
    {
        if (s[0] - '0' == 0 || s[n - 1] - '0' == 0)
        {
            cout << 0 << endl;
            return;
        }
        if (n == 3 && s[1] - '0' == 0)
        {
            cout << min((s[0] - '0') * stoi(s.substr(1, 2)), (s[0] - '0') + stoi(s.substr(1, 2))) << endl;
            return;
        }
    }

    int sum = 0;
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] - '0' == 0)
        {
            cout << 0 << endl;
            return;
        }
        if (s[i] - '0' == 1)
        {
            one++;
        }
        sum += s[i] - '0';
    }
    int ans = intmax;
    sum -= one;
    for (int i = 0; i < n - 1; i++)
    {
        int a = sum - (s[i] - '0' + s[i + 1] - '0');
        if (s[i] - '0' == 1)
        {
            a++;
        }
        if (s[i + 1] - '0' == 1)
        {
            a++;
        }
        a += stoi(s.substr(i,2));
        ans = min(ans,a);
    }
    cout << ans << endl;
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