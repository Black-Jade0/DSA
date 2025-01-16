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

void solve()
{
    int n;
    string s;
    cin >> s;
    n = s.size();
    cout << "1" << " " << n << " ";
    int fz = 0;
    while (s[fz] == '1')
    {
        fz++;
    }
    int len2 = n - fz;
    if (len2 == 0)
    {
        cout << 1 << " " << 1 << endl;
        return;
    }
    int l = 0;
    int count = 0;
    for (int i = 0; i < n - len2; i++)
    {
        if (s[i] == '1')
        {
            int temp = 0;
            int j = i;
            int k = fz;
            while (j < n && k < n && s[j] != s[k])
            {
                j++;
                k++;
                temp++;
            }
            if (temp > count)
            {
                count = temp;
                l = i;
            }
        }
    }
    int r = l + len2 - 1;
    if (r >= n)
    {
        r = n - 1;
    }
    cout << l + 1 << " " << r + 1 << endl;
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