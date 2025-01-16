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
    int n, k;
    cin >> n >> k;
    vi a(n);
    mpii track;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        track[a[i]]++;
    }
    if (n - 1 <= k)
    {
        cout << 1 << endl;
        return;
    }
    
    vpii freq(track.begin(), track.end());
    sort(freq.begin(), freq.end(), [](pii &a, pii &b)
         {
             return a.second < b.second; 
         });

    int sum = 0;
    int index = 0;
    for (int i = 0; i < freq.size(); i++)
    {
        sum += freq[i].second;
        if (sum > k)
        {
            index = i;
            break;
        }
    }
    int remaining_pairs = freq.size() - index;
    cout << remaining_pairs << endl;
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