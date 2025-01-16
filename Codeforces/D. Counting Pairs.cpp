#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<vector<int>>;
using vlll = vector<vector<ll>>;
using mpii = map<int, int>;
using mpci = map<char, int>;
using mpcl = map<char, ll>;
using mpsi = map<string, int>;
using mpsl = map<string, ll>;
using mpll = map<ll, ll>;
#define ilen(a) (int)a.size()
#define llen(a) (ll) a.size()
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repr(i, a, b) for (ll i = (a); i <= (b); i++)
const char nl = '\n';
const int intmax = INT_MAX;
const int intmin = INT_MIN;
const ll llmax = LLONG_MAX;
const ll llmin = LLONG_MIN;

//TLE
void solve()
{
    int n;
    long long x, y;
    cin >> n >> x >> y;
    vector<long long> a(n);
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int ans = 0;
    sort(a.begin(), a.end());
    int i = 0;
    int j = n - 1;
    long long lower = sum - y;
    long long upper = sum - x;
    while (i < j)
    {
        int pair_sum = a[i] + a[j];
        if (pair_sum >= lower && pair_sum <= upper)
        {
            ans++;
            int temp = i + 1;
            while (a[temp] + a[j] >= lower && a[temp] + a[j] <= upper && temp < j)
            {
                ans++;
                temp++;
            }
            j--;
        }
        else if (pair_sum < lower)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << ans << endl;
    return;
}

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        ll x, y;
        cin >> n >> x >> y;
        vi vec(n);
        ll sum = 0;
        for (auto &it : vec)
        {
            cin >> it;
            sum += it;
        }
        sort(all(vec));
        ll llimit = sum - y;
        ll rlimit = sum - x;
        ll count = 0;
        rep(i, n)
        {
            ll r = rlimit - vec[i];
            ll l = llimit - vec[i];
            auto ubound = upper_bound(vec.begin() + i + 1, vec.end(), r);
            auto lbound = lower_bound(vec.begin() + i + 1, vec.end(), l);
            ubound--;
            if (ubound >= lbound)
            {
                count += ubound - lbound + 1;
            }
        }
        cout << count << nl;
    }
    return 0;
}
