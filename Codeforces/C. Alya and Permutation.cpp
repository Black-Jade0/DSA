#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pllll = pair<long long, long long>;
using vi = vector<int>;
using vs = vector<string>;
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

void help(int n)
{
    for (int i = 1; i < n - 4; i++)
    {
        cout << i << " ";
    }
    cout << n - 3 << " " << n - 4 << " " << n - 2 << " " << n - 1 << " " << n ;
    return;
}

void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 1)
    {
        cout << n << endl;
        help(n);
        cout << endl;
        return;
    }
    int a = 1;
    while (a * 2 <= n)
    {
        a *= 2;
    }
    cout << (a*2) - 1 << endl;
    int inverse = a - (n - a + 1);
    if (inverse < 5)
    {
        for (int i = 4; i < n - 1; i++)
        {
            cout << i << " ";
        }
        cout << n - 1 << " " << 1 << " " << 2 << " " << 3 << " " << n << endl;
        return;
    }
    for (int i = inverse + 1; i < n; i++)
    {
        cout << i << " ";
    }
    help(inverse);
    cout << " " << n << endl;
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