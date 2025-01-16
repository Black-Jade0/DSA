#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pllll = pair<long long, long long>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
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
#define ilen(a) (int)a.size()
#define llen(a) (ll) a.size()
#define all(x) (x).begin(), (x).end()
#define fi(i,n) for(int i = 0; i < n; i++)
#define fl(i, n) for (ll i = 0; i < n; i++)
#define fla(i, a, b) for (ll i = (a); i <= (b); i++)
const char nl = '\n';
const int intmax = INT_MAX;
const int intmin = INT_MIN;
const ll llmax = LLONG_MAX;
const ll llmin = LLONG_MIN;

void solve()
{
    int n, k;
    cin >> n >> k;
    vpllll a(n);
    long long ans = 0;
    mpllpllll track;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        track[a[i].first].first++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].second;
        track[a[i].second].second++;
    }
    int negative = 0;
    int no = 0;
    long long temp = 0;
    pllll prev = {0, 0};
    for (auto var : track)
    {
        negative += prev.first - prev.second;
        no += prev.second;
        prev = var.second;
        if (negative > k)
        {
            continue;
        }
        temp = var.first * (n - no);
        ans = max(ans,temp);
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