#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pllll = pair<long long, long long>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vpii = vector<pair<int, int>>;
using vpllll = vector<pair<long long, long long>>;
using mpii = map<int, int>;
using mpci = map<char, int>;
using mpcl = map<char, ll>;
using mpsi = map<string, int>;
using mpsl = map<string, ll>;
using mpll = map<ll, ll>;
using mpii = map<int, int>;
using mpipii = map<int, pair<int, int>>;
using mpllpllll = map<long long, pair<long long, long long>>;
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
    int n, m, l;
    cin >> n >> m >> l;
    vpii hurdles(n);
    vpii powers(m);
    for (int i = 0; i < n; i++)
    {
        cin >> hurdles[i].first >> hurdles[i].second;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> powers[i].first >> powers[i].second;
    }
    pqi pouch;
    int power = 1;
    int prev = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int f = hurdles[i].first;
        int s = hurdles[i].second;
        int jump = s - f + 1;
        auto it = upper_bound(powers.begin(), powers.end(), make_pair(f, intmax));
        int index = it - powers.begin() - 1;
        int j = index;
        while (j >= prev)
        {
            pouch.push(powers[j].second);
            j--;
        }
        while (power <= jump && !pouch.empty())
        {
            ans++;
            power += pouch.top();
            pouch.pop();
        }
        if (!(power > jump))
        {
            cout << -1 << endl;
            return;
        }
        prev = index + 1;
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