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

int findlast(const vector<int> &vec, int target)
{
    auto it = upper_bound(vec.begin(), vec.end(), target);
    if (it == vec.begin() || *(it - 1) != target)
    {
        return -1;
    }
    return distance(vec.begin(), it - 1);
}

int getinverse(int base, int exp, int mod)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (1LL * result * base) % mod;
        }
        base = (1LL * base * base) % mod;
        exp /= 2;
    }
    return result;
}
int devidethisshit(int rem, int a, int mod)
{
    int ainverse = getinverse(a, mod - 2, mod);
    return (1LL * rem * ainverse) % mod;
}

void solve()
{
    int rem = 1;
    int n, q;
    int mod = 998244353;
    cin >> n >> q;
    vi asort(n);
    vi bsort(n);
    vpii t(q);
    fi(i, n)
    {
        cin >> asort[i];
    }
    fi(i, n)
    {
        cin >> bsort[i];
    }
    fi(i, q)
    {
        cin >> t[i].first;
        cin >> t[i].second;
    }
    vi a = asort;
    vi b = bsort;
    sort(asort.begin(), asort.end());
    sort(bsort.begin(), bsort.end());
    rem = min(asort[0], bsort[0]);
    for (int i = 1; i < n; i++)
    {
        rem = (1LL * rem * min(asort[i], bsort[i])) % mod;
    }
    cout << rem << " ";
    for (int i = 0; i < q; i++)
    {
        int index = t[i].second - 1;
        int num = 0;
        bool shit = false;
        if (t[i].first == 1)
        {
            num = a[index];
            a[index]++;
            index = findlast(asort, num);
            if (num < bsort[index])
            {
                shit = true;
            }
            asort[index]++;
        }
        else
        {
            num = b[index];
            b[index]++;
            index = findlast(bsort, num);
            if (num < asort[index])
            {
                shit = true;
            }
            bsort[index]++;
        }
        if (!shit)
        {
            cout << rem << " ";
            continue;
        }
        rem = devidethisshit(rem, num, mod);
        num++;
        rem = (1LL * rem * (num % mod)) % mod;
        cout << rem << " ";
    }
    cout << endl;
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