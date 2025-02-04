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
using mpgii = map<int, int, greater<int>>;
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

const int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    mpii track;
    int damn = 0;
    int f = 0;
    int s = 0;
    fi(i, n)
    {
        cin >> a[i];
        track[a[i]]++;
        if (track[a[i]] > 1 && !damn)
        {
            damn = a[i];
            track.erase(a[i]);
        }
        else if (damn && track[a[i]] > 1)
        {
            f = a[i];
            s = a[i];
        }
    }
    if (!damn)
    {
        cout << -1 << endl;
        return;
    }
    
    if (f && s && damn)
    {
        cout << f << " " << s << " " << damn << " " << damn << endl;
        return;
    }
    auto it = track.begin();
    int prev = it->first;
    it++;
    for (; it != track.end(); it++)
    {
        if (it->first < prev + (2 * damn))
        {
            f = prev;
            s = it->first;
            break;
        }
        prev = it->first;
    }

    if (f && s && damn && min(f, s) + (2 * damn) > max(f, s))
    {
        cout << f << " " << s << " " << damn << " " << damn << endl;
    }
    else
    {
        cout << -1 << endl;
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