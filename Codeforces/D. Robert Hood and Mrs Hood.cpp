#include <bits/stdc++.h>
#include <cmath>

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
    int n, d, k;
    cin >> n >> d >> k;
    vi a(n + 2, 0);
    vi track(n + 2, 0);
    for (int i = 0; i < k; i++)
    {
        int j;
        cin >> j;
        a[j]++;
        track[j]++;
        int l;
        cin >> l;
        a[l + 1]--;
    }
    for (int i = 1; i < n + 2; i++)
    {
        a[i] += a[i -1];
        track[i] += track[i - 1];
    }
    
    int brother = intmin;
    int bindex = 0;
    int mother = intmax;
    int mindex = 0;

    for (int i = 1; i <= n - d + 1; i++)
    {
        int curr = a[i] + track[i + d - 1] - track[i];
        if (brother < curr)
        {
            brother = curr;
            bindex = i;
        }
        if (mother > curr)
        {
            mother = curr;
            mindex = i;
        }
    }

    cout << bindex << " " << mindex << endl;
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