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
using si = set<int>;
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

// int makenum(int a, int k)
// {
//     int res;
//     if (a + k - 1 < 2 * k)
//     {
//         res = (1 << k) - 1;
//         res <<= 1LL * (2 * k) - a - k;
//         return res;
//     }
//     res = (1 << k) - 1;
//     res <<= (1LL * (2 * k) - a);
//     int help = (1 << (2 * k)) - 1;
//     res = help ^ res;
//     return res;
// }

// void solve()
// {
//     int n, k;
//     cin >> n >> k;
//     si a;
//     int num = intmin;
//     for (int i = 0; i < n; i++)
//     {
//         int b;
//         cin >> b;
//         a.insert(b % (2 * k));
//         num = max(num, b);
//     }

//     ll x = (1 << (2 * k)) - 1;

//     for (auto curr : a)
//     {
//         x = x & makenum(curr, k);
//     }
//     if (x == 0)
//     {
//         cout << -1 << endl;
//         return;
//     }
//     int shit = 0;
//     int msb = 0;
//     int i = 1;
//     ll result = 1LL * (num / (2 * k)) * (2 * k);

//     while (x)
//     {
//         if (x & 1 && result + ((2 * k) - i) >= num)
//         {
//             shit = i;
//         }
//         if (x & 1)
//         {
//             msb = i;
//         }
//         x >>= 1;
//         i++;
//     }
//     if (!shit)
//     {
//         result = result + (2 * k) + ((2 * k) - msb);
//     }
//     else
//     {
//         result = result + ((2 * k) - shit);
//     }
//     cout << result << endl;
//     return;
// }

// Not good for bigger k, as we are using a binary string of length k to compute our answer

const int N = 2e5 + 5;

int n, k, d[2 * N];

void solve()
{

    cin >> n >> k;
    int mx = -1;
    fill(d, d + 2 * k, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        assert(x >= 1);
        d[x % (2 * k)]++;
        mx = max(mx, x);
    }

    int cnt = 0;
    int ans = INT_MAX;
    for (int i = 0; i <= k - 2; i++)
    {
        cnt += d[i];
    }

    for (int l = 0, r = k - 1; l < 2 * k; l++, r++)
    {
        if (r >= 2 * k)
            r -= 2 * k;

        if (cnt += d[r]; cnt == n)
        {
            int wait = (r - mx) % (2 * k);
            // int wait = r - (mx % (2 * k));
            if (wait < 0)
                wait += 2 * k;
            ans = min(ans, mx + wait);
        }

        cnt -= d[l];
    }

    if (ans == INT_MAX)
    {
        ans = -1;
    }
    cout << ans << '\n';
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