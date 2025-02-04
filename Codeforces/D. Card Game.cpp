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
using spii = set<pii>;
using mpii = map<int, int>;
using mpci = map<char, int>;
using mpcl = map<char, ll>;
using mpsi = map<string, int>;
using mpsl = map<string, ll>;
using mpll = map<ll, ll>;
using mpii = map<int, int>;
using mpipii = map<int, pair<int, int>>;
using mpllpllll = map<ll, pair<ll, ll>>;
using mppiivi = map<pii, vi>;
using mppiimpii = map<pii, mpii>;
using pqi = priority_queue<int>;
using pqgi = priority_queue<int, vi, greater<int>>;
using mpcpqi = map<char, pqi>;
using mpcpqgi = map<char, pqgi>;
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
    char kaat;
    cin >> kaat;
    mpcpqgi a;
    for (int i = 0; i < 2 * n; i++)
    {
        string b;
        cin >> b;
        a[b[1]].push(b[0] - '0');
    }

    vs ans;
    for (auto &suit : a)
    {
        if (suit.first != kaat)
        {
            while (suit.second.size() >= 2)
            {
                ans.push_back(to_string(suit.second.top()) + suit.first);
                suit.second.pop();
                ans.push_back(to_string(suit.second.top()) + suit.first);
                suit.second.pop();
            }
        }
    }
    for (auto &suit : a)
    {
        if (suit.second.size() > 0 && suit.first != kaat)
        {
            ans.push_back(to_string(suit.second.top()) + suit.first);
            suit.second.pop();
            if (a[kaat].size() > 0)
            {
                ans.push_back(to_string(a[kaat].top()) + kaat);
                a[kaat].pop();
            }
            else
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
    while (a[kaat].size() > 0)
    {
        ans.push_back(to_string(a[kaat].top()) + kaat);
        a[kaat].pop();
        if (a[kaat].size() > 0)
        {
            ans.push_back(to_string(a[kaat].top()) + kaat);
            a[kaat].pop();
        }
        else
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    for (int i = 0; i < 2 * n; i += 2)
    {
        cout << ans[i] << " " << ans[i + 1] << endl;
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