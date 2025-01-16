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
    int n;
    cin >> n;
    cout << "? 0" << endl;
    cout.flush();
    int a, b;
    cin >> a;
    string s = "0";
    if (!a)
    {
        string sn(n, '1');
        cout << "! " << sn << endl;
        return;
    }
    b = 1;
    while ((a || b) && s.length() < n)
    {
        cout << "? " << '0' + s << endl;
        cout.flush();
        cin >> a;
        if (!a)
        {
            cout << "? " << '1' + s << endl;
            cout.flush();
            cin >> b;
        }

        if (a)
        {
            s = '0' + s;
        }
        else if (b)
        {
            s = '1' + s;
        }
    }
    if (s.length() == n)
    {
        cout << "! " << s << endl;
        cout.flush();
        return;
    }
    while (s.length() != n)
    {
        cout << "? " << s + '0' << endl;
        cout.flush();
        cin >> a;
        if (a)
        {
            s = s + '0';
        }
        else
        {
            s = s + '1';
        }
    }
    cout << "! " << s << endl;
    cout.flush();
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