#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pllll = pair<long long, long long>;
using vi = vector<int>;
using vll = vector<ll>;
using vvpii = vector<vector<int>>;
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
    vpii a(n);
    fi(i, n)
    {
        cin >> a[i].first;
    }
    fi(i, n)
    {
        cin >> a[i].second;
    }
    vpii left;
    vpii right;
    int sum = 0;
    fi(k, n)
    {
        if (a[k].first >= a[k].second)
        {
            left.push_back(a[k]);
            sum += a[k].first;
        }
        else
        {
            right.push_back(a[k]);
            sum += a[k].second;
        }
    }
    int left_max = intmin;
    int right_max = intmin;
    fi(k, left.size())
    {
        if (left[k].second > left_max)
        {
            left_max = left[k].second;
        }
    }
    fi(k, right.size())
    {
        if (right[k].first > right_max)
        {
            right_max = right[k].first;
        }
    }
    sum += max(left_max,right_max);
    cout << sum << endl;
    return;
}

// 6
// 1 2  0 -4 -1 1
// 1 2 -1 -3  2 4

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