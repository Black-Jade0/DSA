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
using spii = set<pii>;
using mpii = map<int, int>;
using mpgii = map<int, int, greater<int>>;
using mpci = map<char, int>;
using mpcl = map<char, ll>;
using mpsi = map<string, int>;
using mpsl = map<string, ll>;
using mpll = map<ll, ll>;
using mpii = map<int, int>;
using mpipii = map<int, pair<int, int>>;
using mpllpllll = map<ll, pair<ll, ll>>;
using mppiivi = map<pii, vi>;
using mppiimpii = map<pii, mpii>;
using pqi = priority_queue<int>;
using pqgi = priority_queue<int, vi, greater<int>>;
using mpcpqi = map<char, pqi>;
using mpcpqgi = map<char, pqgi>;
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

const int mod = 998244353;

void solve()
{
    int n;
    int m;
    cin >> n >> m;
    mpii a;
    mpii b;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a[temp]++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        b[temp]++;
    }
    for (auto &x : b)
    {
        if (a[x.first] > 0)
        {
            int t = min(x.second, a[x.first]);
            x.second -= t;
            a[x.first] -= t;
        }
    }

    vector<int> to_erase;
    for (auto &x : a)
    {
        if (x.second == 0)
        {
            to_erase.push_back(x.first);
        }
    }
    for (int key : to_erase)
    {
        a.erase(key);
    }

    to_erase.clear();
    for (auto &x : b)
    {
        if (x.second == 0)
        {
            to_erase.push_back(x.first);
        }
    }
    for (int key : to_erase)
    {
        b.erase(key);
    }

    if (b.begin() == b.end() && a.begin() == a.end())
    {
        cout << "Yes" << endl;
        return;
    }
    if (a.begin() == a.end() || b.begin() == b.end())
    {
        cout << "No" << endl;
        return;
    }
    int first;
    int second;
    while (b.begin() != b.end() && b.begin()->first > a.begin()->first)
    {
        first = b.begin()->first;
        second = b.begin()->second;
        b[first / 2] = second;
        b[(first + 1) / 2] += second;
        b.erase(first);
        if (a[first / 2] > 0)
        {
            int t = min(a[first / 2], b[first / 2]);
            if (a[first / 2] == t)
            {
                a.erase(first / 2);
            }
            else
            {
                a[first / 2] -= t;
            }
            if (b[first / 2] == t)
            {
                b.erase(first / 2);
            }
            else
            {
                b[first / 2] -= t;
            }
        }
        else
        {
            a.erase(first / 2);
        }
        if (a[(first + 1) / 2] > 0)
        {
            int t = min(a[(first + 1) / 2], b[(first + 1) / 2]);
            if (a[(first + 1) / 2] == t)
            {
                a.erase((first + 1) / 2);
            }
            else
            {
                a[(first + 1) / 2] -= t;
            }
            if (b[(first + 1) / 2] == t)
            {
                b.erase((first + 1) / 2);
            }
            else
            {
                b[(first + 1) / 2] -= t;
            }
        }
        else
        {
            a.erase((first + 1) / 2);
        }
    }

    if (b.begin() == b.end() && a.begin() == a.end())
    {
        cout << "Yes" << endl;
        return;
    }
    else
    {
        cout << "No" << endl;
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