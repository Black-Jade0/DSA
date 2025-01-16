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

void check(int i, int j, int &n, int &m, vs &a, vvb &track, int &sum, char prev)
{
    if (i < 0 || j < 0 || i >= n || j >= m || !track[i][j] || a[i][j] != prev)
    {
        return;
    }
    sum--;
    track[i][j] = false;
    check(i - 1, j, n, m, a, track, sum, 'D');
    check(i, j - 1, n, m, a, track, sum, 'R');
    check(i + 1, j, n, m, a, track, sum, 'U');
    check(i, j + 1, n, m, a, track, sum, 'L');
    return;
}

void help(int i, int j, int &n, int &m, vs &a, vvb &track, int &sum)
{
    sum--;
    track[i][j] = false;
    check(i - 1, j, n, m, a, track, sum, 'D');
    check(i, j - 1, n, m, a, track, sum, 'R');
    check(i + 1, j, n, m, a, track, sum, 'U');
    check(i, j + 1, n, m, a, track, sum, 'L');
    return;
}

bool help2(int i, int j, int &n, int &m, vs &a, vvb &track)
{
    if (i < 0 || i >= n || j < 0 || j >= m || !track[i][j])
    {
        return true;
    }
    return false;
}

void finalcheck(int i, int j, int &n, int &m, vs &a, vvb &track, int &sum)
{
    if (help2(i - 1, j, n, m, a, track) &&
        help2(i + 1, j, n, m, a, track) &&
        help2(i, j - 1, n, m, a, track) &&
        help2(i, j + 1, n, m, a, track))
    {
        sum--;
        track[i][j] = false;
    }
    return;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vs a(n);
    int sum = n * m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vvb track(n, vb(m, true));
    for (int i = 0; i < m; i++)
    {
        if (a[0][i] == 'U')
        {
            help(0, i, n, m, a, track, sum);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i][m - 1] == 'R')
        {
            help(i, m - 1, n, m, a, track, sum);
        }
    }
    for (int i = m - 1; i >= 0; i--)
    {
        if (a[n - 1][i] == 'D')
        {
            help(n - 1, i, n, m, a, track, sum);
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i][0] == 'L')
        {
            help(i, 0, n, m, a, track, sum);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (track[i][j])
            {
                finalcheck(i, j, n, m, a, track, sum);
            }
        }
    }
    cout << sum << endl;
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