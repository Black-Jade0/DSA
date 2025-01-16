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
    string s;
    cin >> s;

    int h1 = 0;
    int v1 = 0;
    int h2 = 0;
    int v2 = 0;
    string ans;

    bool toggle = false;
    bool h = false;
    bool r = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'N')
        {
            if (v1 == v2)
            {
                if (toggle)
                {
                    ans.append("R");
                    v1++;
                }
                else
                {
                    ans.append("H");
                    v2++;
                }
                toggle = !toggle;
            }

            else if (v1 < v2)
            {
                ans.append("R");
                v1++;
            }
            else
            {
                ans.append("H");
                v2++;
            }
        }
        else if (s[i] == 'S')
        {
            if (v1 == v2)
            {
                if (toggle)
                {
                    ans.append("R");
                    v1--;
                }
                else
                {
                    ans.append("H");
                    v2--;
                }
                toggle = !toggle;
            }
            else if (v1 > v2)
            {
                ans.append("R");
                v1--;
            }
            else
            {
                ans.append("H");
                v2--;
            }
        }
        else if (s[i] == 'E')
        {
            if (h1 == h2)
            {
                if (toggle)
                {
                    ans.append("R");
                    h1++;
                }
                else
                {
                    ans.append("H");
                    h2++;
                }
                toggle = !toggle;
            }
            else if (h1 < h2)
            {
                ans.append("R");
                h1++;
            }
            else
            {
                ans.append("H");
                h2++;
            }
        }
        else if (s[i] == 'W')
        {
            if (h1 == h2)
            {
                if (toggle)
                {
                    ans.append("R");
                    h1--;
                }
                else
                {
                    ans.append("H");
                    h2--;
                }
                toggle = !toggle;
            }
            else if (h1 > h2)
            {
                ans.append("R");
                h1--;
            }
            else
            {
                ans.append("H");
                h2--;
            }
        }

        if (h1 != 0 || v1 != 0)
        {
            r = true;
        }
        if (h2 != 0 || v2 != 0)
        {
            h = true;
        }
    }

    if (!h || !r)
    {
        cout << "NO" << endl;
        return;
    }

    if (v1 == v2 && h1 == h2)
    {
        cout << ans << endl;
        return;
    }
    else
    {
        cout << "NO" << endl;
        return;
    }
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