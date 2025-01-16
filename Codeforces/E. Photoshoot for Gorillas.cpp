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
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    vi a(w);
    for (int i = 0; i < w; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    pqi p;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Approach is to find the number of times a particular block will be counted and store it

            // First approach is through observation:

            // p.push(1LL * min(min(k, n - k + 1), min(n - i, i + 1)) * min(min(k, m - k + 1), min(m - j, j + 1)));

            // This approach is through some efforts:
            // Lets talk in 1D, we have a block of train of len k and our track of len n
            // Now we need to find out when we start our train that is on the track covering first k blocks
            // and run it till it covers the last k blocks, how many times does a space block is used to keep different train blocks
            // Lets say a ith block
            // So we find out when the ith block will come in contact with our train (in respect of train)
            // It can have a initial contact at the ith block (i < k)
            // Or it can eventually come in contacct with our train at the kth block (k < i)
            // ---> min(k,i + 1);
            // Now we find the position of that block when the train stops or leave that block (from the front of the train, kth block)
            // It can be k, means the last block of train that was in contact of the train was the first block(kth from front)
            // ie (k < n - k + 1)
            // or the block that is in contact with the ith space when train stops
            // ir (k >= n - k + 1)
            // ---> k - min(n - i,k);
            // We subtract it and skadooosh

            p.push(1LL * (min(k, i + 1) - (k - min(n - i, k))) * (min(k, j + 1) - (k - min(m - j, k))));
        }
    }
    ll ans = 0;
    for (int i = 0; i < w; i++)
    {
        ans += (1LL * a[i] * p.top());
        p.pop();
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