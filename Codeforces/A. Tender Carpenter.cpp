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
    vi a(n);
    fi(i, n)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            cout << "YES" << endl;
            return;
        }

        if (a[i] > a[i + 1])
        {
            if (2 * a[i + 1] > a[i])
            {
                cout << "YES" << endl;
                return;
            }
        }
        else
        {
            if (2 * a[i] > a[i + 1])
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    ll sum = a[0] + a[1];
    cout << "NO" << endl;
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