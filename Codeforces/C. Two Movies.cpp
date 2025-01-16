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

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    fi(i, n)
    {
        cin >> a[i];
    }
    fi(i, n)
    {
        cin >> b[i];
    }
    int asum = 0;
    int bsum = 0;
    int pos = 0;
    int neg = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            asum += a[i];
        }
        else if (a[i] < b[i])
        {
            bsum += b[i];
        }
        else
        {
            if (a[i] == 0)
            {
                continue;
            }
            else if (a[i] == 1)
            {
                pos++;
            }
            else if (a[i] == -1)
            {
                neg++;
            }
        }
    }
    if (asum < bsum)
    {
        if (pos > bsum - asum)
        {
            pos -= bsum - asum;
            asum = bsum;
        }
        else
        {
            asum += pos;
            pos = 0;
        }
    }
    else if (bsum < asum)
    {
        if (pos > asum - bsum)
        {
            pos -= asum - bsum;
            bsum = asum;
        }
        else
        {
            bsum += pos;
            pos = 0;
        }
    }
    if (asum == bsum && pos)
    {
        asum += (pos / 2);
        bsum += (pos / 2);
        if (pos & 1)
        {
            asum++;
        }
        pos = 0;
    }

    if (asum < bsum)
    {
        if (neg > bsum - asum)
        {
            neg -= bsum - asum;
            bsum = asum;
        }
        else
        {
            bsum -= neg;
            neg = 0;
        }
    }
    else if (bsum < asum)
    {
        if (neg > asum - bsum)
        {
            neg -= asum - bsum;
            asum = bsum;
        }
        else
        {
            asum -= neg;
            neg = 0;
        }
    }
    if (asum == bsum && neg)
    {
        asum -= (neg / 2);
        bsum -= (neg / 2);
        if (neg & 1)
        {
            asum--;
        }
        neg = 0;
    }

    cout << min(asum,bsum) << endl;
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