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

// void solve()
// {
//     int n;
//     cin >> n;
//     vpii a(n);
//     mpii equalp;
//     fi(i, n)
//     {
//         cin >> a[i].first >> a[i].second;
//         if (a[i].first == a[i].second)
//         {
//             equalp[a[i].first]++;
//         }
//     }
//     string ans = "";
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i].first == a[i].second)
//         {
//             if (equalp[a[i].first] > 1)
//             {
//                 ans.push_back('0');
//             }
//             else
//             {
//                 ans.push_back('1');
//             }
//             continue;
//         }
//         bool valid = true;
//         for (int j = a[i].first; j <= a[i].second; j++)
//         {
//             if (equalp[j] <= 0)
//             {
//                 valid = false;
//                 break;
//             }
//         }
//         if (valid)
//             ans.push_back('0');
//         else
//             ans.push_back('1');
//     }
//     cout << ans << endl;
//     return;
// }

// TLE

void solve()
{
    int n;
    cin >> n;
    vpii a(n);
    mpii equalp;
    vi track((2 * n) + 1, 0);
    fi(i, n)
    {
        cin >> a[i].first >> a[i].second;
        if (a[i].first == a[i].second)
        {
            equalp[a[i].first]++;
            track[a[i].first] = 1;
        }
    }
    for (int i = 2; i < (2 * n) + 1; i++)
    {
        track[i] += track[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i].first == a[i].second)
        {
            cout << ((equalp[a[i].first] > 1) ? "0" : "1");
        }
        else
        {
            cout << ((track[a[i].second] - track[a[i].first - 1] >= a[i].second - a[i].first + 1) ? "0" : "1");
        }
    }
    cout << endl;
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