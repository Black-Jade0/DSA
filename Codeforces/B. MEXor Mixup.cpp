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
using si = set<int>;
using spii = set<pii>;
using mpii = map<int, int>;
using mpivi = map<int, vi>;
using mpci = map<char, int>;
using mpcl = map<char, ll>;
using mpcvi = map<char, vi>;
using mpsi = map<string, int>;
using mpsl = map<string, ll>;
using mpll = map<ll, ll>;
using mpii = map<int, int>;
using mpipii = map<int, pair<int, int>>;
using mpllpllll = map<long long, pair<long long, long long>>;
using mppiivi = map<pii, vi>;
using mppiimpii = map<pii, mpii>;
using pqi = priority_queue<int>;
using pqgi = priority_queue<int, vi, greater<int>>;
using pqpii = priority_queue<pii>;
using pqgpii = priority_queue<pii, vpii, greater<pii>>;
#define ilen(a) (int)a.size()
#define llen(a) (ll) a.size()
#define all(x) (x).begin(), (x).end()
#define fi(i, j, n) for (int i = j; i < n; i++)
#define fl(i, j, n) for (ll i = j; i < n; i++)
#define fla(i, a, b) for (ll i = (a); i <= (b); i++)
const char nl = '\n';
const int intmax = INT_MAX;
const int intmin = INT_MIN;
const ll llmax = LLONG_MAX;
const ll llmin = LLONG_MIN;

void solve(vi &help)
{
    int a, b;
    cin >> a >> b;

    ll ans = a;
    int num = help[a - 1];

    if (num != b && (num ^ a) != b)
    {
        ans++;
    }
    else if (num != b && (num ^ a) == b)
    {
        ans += 2;
    }
    cout << ans << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vi help((3 * pow(10, 5)));
    ll j = 0;
    for (int i = 0; i < help.size(); i++)
    {
        j = j ^ i;
        help[i] = j;
    }

    int INP;
    cin >> INP;
    while (INP--)
    {
        solve(help);
    }
    return 0;
}