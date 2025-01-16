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

bool comp(pii p1, pii p2)
{
    if (p1.second < p2.second)
        return true;
    else if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    else
        return false;
}
void solve()
{
    int n;
    cin >> n;
    vi va(n), vb(n), vc(n);
    ll tot = 0;
    fi(i, n)
    {
        cin >> va[i];
        tot += va[i];
    }
    fi(i, n)
    {
        cin >> vb[i];
    }
    fi(i, n)
    {
        cin >> vc[i];
    }
    vector<pii> vpa, vpb, vpc;
    tot = (tot + 2) / 3;
    // cout<<tot<<nl;
    int i = 0, index = 0;
    ll sum = 0;
    while (i < n)
    {
        sum += va[i];
        if (sum >= tot)
        {
            while (sum >= tot && index < n)
            {
                sum -= va[index];
                index++;
            }
            vpa.push_back({index, i + 1});
        }
        i++;
    }
    i = 0, index = 0, sum = 0;
    while (i < n)
    {
        sum += vb[i];
        if (sum >= tot)
        {
            while (sum >= tot && index < n)
            {
                sum -= vb[index];
                index++;
            }
            vpb.push_back({index, i + 1});
        }
        i++;
    }
    i = 0, index = 0, sum = 0;
    while (i < n)
    {
        sum += vc[i];
        if (sum >= tot)
        {
            while (sum >= tot && index < n)
            {
                sum -= vc[index];
                index++;
            }
            vpc.push_back({index, i + 1});
        }
        i++;
    }
    // Manual
    pii f = *vpa.begin(), last = *(vpb.end() - 1);
    for (auto it : vpc)
    {
        if (it.first > f.second && it.second < last.first)
        {
            cout << 1 << " " << f.second << " " << last.first << " " << n << " " << f.second + 1 << " " << last.first - 1 << nl;
            return;
        }
    }
    f = *vpa.begin(), last = *(vpc.end() - 1);
    for (auto it : vpb)
    {
        if (it.first > f.second && it.second < last.first)
        {
            cout << 1 << " " << f.second << " " << f.second + 1 << " " << last.first - 1 << " " << last.first << " " << n << nl;
            return;
        }
    }
    f = *vpb.begin(), last = *(vpc.end() - 1);
    for (auto it : vpa)
    {
        if (it.first > f.second && it.second < last.first)
        {
            cout << f.second + 1 << " " << last.first - 1 << " " << 1 << " " << f.second << " " << last.first << " " << n << nl;
            return;
        }
    }
    f = *vpb.begin(), last = *(vpa.end() - 1);
    for (auto it : vpc)
    {
        if (it.first > f.second && it.second < last.first)
        {
            cout << last.first << " " << n << " " << 1 << " " << f.second << " " << f.second + 1 << " " << last.first - 1 << nl;
            return;
        }
    }
    f = *vpc.begin(), last = *(vpa.end() - 1);
    for (auto it : vpb)
    {
        if (it.first > f.second && it.second < last.first)
        {
            cout << last.first << " " << n << " " << f.second + 1 << " " << last.first - 1 << " " << 1 << " " << f.second << nl;
            return;
        }
    }
    f = *vpc.begin(), last = *(vpb.end() - 1);
    for (auto it : vpa)
    {
        if (it.first > f.second && it.second < last.first)
        {
            cout << f.second + 1 << " " << last.first - 1 << " " << last.first << " " << n << " " << 1 << " " << f.second << nl;
            return;
        }
    }
    cout << -1 << nl;
    return;
}

void solve1()
{
    int n;
    cin >> n;
    vector<vi> val(3, vector<int>(n + 1));
    vector<vi> pf(3, vector<int>(n + 1));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> val[i][j];
            pf[i][j] = pf[i][j - 1] + val[i][j];
        }
    }

    bool ok = 0;
    vi perm = {0, 1, 2};
    int comp = (pf[perm[0]][n] + 2) / 3;
    for (int i = 0; i < 6; i++)
    {
        int cur = 1;
        while (cur <= n && pf[perm[0]][cur] < comp)
            cur++;
        for (int j = cur + 1; j < n; j++)
        {
            if (pf[perm[1]][j] - pf[perm[1]][cur] >= comp && pf[perm[2]][n] - pf[perm[2]][j] >= comp)
            {
                vpii ans(3);

                ans[perm[0]] = {1, cur};
                ans[perm[1]] = {cur + 1, j};
                ans[perm[2]] = {j + 1, n};

                for (auto x : ans)
                    cout << x.first << ' ' << x.second << ' ';
                cout << '\n';
                ok = 1;
                break;
            }
        }
        if (ok)
            break;
        next_permutation(perm.begin(), perm.end());
    }

    if (!ok)
        cout << -1 << '\n';
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