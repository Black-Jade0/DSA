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
using mpivi = map<int, vi>;
using mpisi = map<int, si>;
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

    mpisi a;
    int l;
    int r;
    mpii track;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> l;
        cin >> r;
        a[l].insert(r);
        a[r].insert(l);
        track[l]++;
        track[r]++;
    }
    vpii damn;
    for (auto x : track)
    {
        damn.push_back({x.first, x.second});
    }
    sort(damn.begin(), damn.end(), [](const pii &a, const pii &b)
         { return a.second > b.second; });
    int first = damn[0].second;

    int ans = damn[0].second + damn[1].second - 2;
    int j = 0;
    while (j < 2)
    {
        int k = j + 1;
        while (k < damn.size())
        {
            if (a[damn[j].first].count(damn[k].first))
            {
                ans = max(ans, damn[j].second + damn[k].second - 2);
            }
            else
            {
                ans = max(ans, damn[j].second + damn[k].second - 1);
            }
            k++;
        }
        j++;
    }

    cout << ans << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll INP;
    cin >> INP;
    while (INP)
    {
        solve();
        INP--;
    }

    return 0;
}