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
using mpcll = map<char, ll>;
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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    int m = 26;
    if (n % 2 == 0)
    {
        int maxodd = intmin;
        int maxeve = intmin;
        vi odd(26, 0);
        vi even(26, 0);
        fi(i, n)
        {
            int b = s[i] - 'a';
            if (i % 2)
            {
                odd[b]++;
            }
            else
            {
                even[b]++;
            }
        }
        fi(i, m)
        {
            maxodd = max(maxodd, odd[i]);
            maxeve = max(maxeve, even[i]);
        }
        cout << n - maxodd - maxeve << endl;
        return;
    }
    vi suffodd(m, 0), suffeven(m, 0), preodd(m, 0), preeven(m, 0);
    fi(i, n)
    {
        int b = s[i] - 'a';
        if (i % 2)
        {
            suffodd[b]++;
        }
        else
        {
            suffeven[b]++;
        }
    }
    ll ans = llmax;
    fi(i, n)
    {
        int b = s[i] - 'a';
        if (i % 2)
        {
            suffodd[b]--;
        }
        else
            suffeven[b]--;
        int maxodd = intmin;
        int maxeven = intmin;
        fi(i, m)
        {
            int x = preeven[i] + suffodd[i];
            int y = preodd[i] + suffeven[i];
            maxeven = max(maxeven, x);
            maxodd = max(maxodd, y);
        }
        if (i % 2)
        {
            preodd[b]++;
        }
        else
            preeven[b]++;
        ans = min(ans, n - maxeven - maxodd);
    }
    cout << ans << endl;
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