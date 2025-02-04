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
using mpci = map<char, int>;
using mpcl = map<char, ll>;
using mpsi = map<string, int>;
using mpsl = map<string, ll>;
using mpll = map<ll, ll>;
using mpii = map<int, int>;
using mpipii = map<int, pair<int, int>>;
using mpllpllll = map<long long, pair<long long, long long>>;
using mppiivi = map<pii, vi>;
using mppiimpii = map<pii, mpii>;
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

vll results;

void solve(vll &a)
{
    if (a.size() > 1)
    {
        vll diff(a.size() - 1);
        for (int i = 0; i < a.size() - 1; i++)
        {
            diff[i] = a[i + 1] - a[i];
        }
        ll diff_sum = accumulate(diff.begin(), diff.end(), 0LL);
        results.push_back(diff_sum);
        results.push_back(-diff_sum);
        solve(diff);
    }
    if (a.size() == 1)
    {
        results.push_back(a[0]);
        results.push_back(-a[0]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        results.clear();
        int n;
        cin >> n;
        vll a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        if (n == 1)
        {
            cout << a[0] << endl;
            continue;
        }

        results.push_back(accumulate(a.begin(), a.end(), 0LL));
        solve(a);
        cout << *max_element(results.begin(), results.end()) << endl;
    }

    return 0;
}