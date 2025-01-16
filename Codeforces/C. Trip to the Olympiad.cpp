#include <bits/stdc++.h>
#include <cmath>

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

void solve()
{
    int l, r;
    cin >> l >> r;

    int a = 0, b = 0, c = 0;
    for (int i = 29; i >= 0; i--)
    {
        //getting the most significant bit that is different in l and r
        if ((l ^ r) >> i & 1)
        {
            b |= 1 << i;
            a |= (1 << i) - 1;
            break;
        }
        //keeping the bits same as l before the upper one hits
        else
        {
            a |= l & (1 << i);
            b |= l & (1 << i);
        }
    }
    // what u did?
    // u find the msb that is different in l and r, now let the ith bit be different
    // what do u get from it?
    // ith bit of r is 1 and of l is 0, so u can just set this bit to 0 and all the following bits to 1 in b
    // note that it will always fell in the range, as in r, ith bit is 1 and even if all other are 0, it will still be smaller than this (0111 < 1000)
    // for a, set the ith bit to 1 and all other to 0, note that this will also fall in range
    // as the ith bit in l is 0 and even if all the following other are 1, then too it will be smaller then a.
    // so u got something like (a = blahhblahh.....01111... and b = blahhblahh....10000....)
    // got the biggest bit that can be different and all the following bits different too
    // so fuck the third number
    c = l;
    while (c == a || c == b)
    {
        c++;
    }

    cout << a << " " << b << " " << c << "\n";
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