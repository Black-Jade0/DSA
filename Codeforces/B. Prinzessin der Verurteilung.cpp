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
using vpipii = vector<pair<int, pii>>;
using vpllll = vector<pair<long long, long long>>;
using pqi = priority_queue<int>;
using pqgi = priority_queue<int, vi, greater<int>>;
using pqpii = priority_queue<pii>;
using pqgpii = priority_queue<pii, vpii, greater<pii>>;
using si = set<int>;
using sll = set<ll>;
using ss = set<string>;
using spii = set<pii>;
using sti = stack<int>;
using qi = queue<int>;
using mpii = map<int, int>;
using mpllll = map<ll, ll>;
using mpgllll = map<ll, ll, greater<int>>;
using mpivi = map<int, vi>;
using mpci = map<char, int>;
using mpcl = map<char, ll>;
using mpcvi = map<char, vi>;
using mpsi = map<string, int>;
using mpsl = map<string, ll>;
using mpll = map<ll, ll>;
using mpii = map<int, int>;
using mpgii = map<int, int, greater<int>>;
using mpipii = map<int, pair<int, int>>;
using mpgipii = map<int, pair<int, int>, greater<int>>;
using mpipipqgi = map<int, pair<int, pqgi>>;
using mpllpllll = map<long long, pair<long long, long long>>;
using mppiivi = map<pii, vi>;
using mppiimpii = map<pii, mpii>;

#define ilen(a) (int)a.size()
#define llen(a) (ll) a.size()
#define all(x) (x).begin(), (x).end()
#define s(x) sort((x).begin(), (x).end())
#define sg(x) sort((x).begin(), (x).end(), greater<int>{})
#define fi(i, j, n) for (int i = j; i < n; i++)
#define fl(i, j, n) for (ll i = j; i < n; i++)
#define fla(i, a, b) for (ll i = (a); i <= (b); i++)
#define inc(n) \
    int n;     \
    cin >> n;
#define llnc(n) \
    ll n;       \
    cin >> n;
#define viac(n, a)                \
    vi a(n);                      \
    for (int i = 0; i < (n); i++) \
    {                             \
        cin >> a[i];              \
    }

#define vllac(n, a)              \
    vll a(n);                    \
    for (ll i = 0; i < (n); i++) \
    {                            \
        cin >> a[i];             \
    }

#define siac(n, a)                \
    si a;                         \
    int TEMP;                     \
    for (int i = 0; i < (n); i++) \
    {                             \
        cin >> TEMP;              \
        a.insert(TEMP);           \
    }

const char nl = '\n';
const int intmax = INT_MAX;
const int intmin = INT_MIN;
const ll llmax = LLONG_MAX;
const ll llmin = LLONG_MIN;

ss help1()
{
    char a = 'a';
    ss ans;
    for (int i = 0; i < 26; i++)
    {
        string temp = string(1, char(a + i));
        ans.insert(temp);
    }
    return ans;
    for (int i = 0; i < 26; i++)
    {
        string b = string(1, char(a + i));
        for (int j = 0; j < 26; j++)
        {
            ans.insert(b + char(a + j));
        }
    }
    return ans;
}
ss help2()
{
    char a = 'a';
    ss ans;
    for (int i = 0; i < 26; i++)
    {
        string b = string(1, char(a + i));
        for (int j = 0; j < 26; j++)
        {
            ans.insert(b + char(a + j));
        }
    }
    return ans;
}
ss help3()
{
    char a = 'a';
    ss ans;
    for (int i = 0; i < 1; i++)
    {
        string b = string(1, char(a + i));
        for (int j = 0; j < 26; j++)
        {
            string c = b + char(a + j);
            for (int k = 0; k < 26; k++)
            {
                string temp = c + char(a + k);
                ans.insert(temp);
            }
        }
    }
    return ans;
}

const ss A = help1();
const ss B = help2();
const ss C = help3();

void solve()
{
    inc(n);
    string s;
    cin >> s;
    ss a = A;
    ss b = B;
    ss c = C;
    for (int i = 0; i < n; i++)
    {
        if (a.count(string(1, (s[i]))))
        {
            a.erase(string(1, s[i]));
        }
    }
    if (a.size() > 0)
    {
        cout << (*a.begin()) << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (b.count(s.substr(i, 2)))
        {
            b.erase(s.substr(i, 2));
        }
    }
    if (b.size() > 0)
    {
        cout << (*b.begin()) << endl;
        return;
    }
    for (int i = 0; i < n - 2; i++)
    {
        if (c.count(s.substr(i, 3)))
        {
            c.erase(s.substr(i, 3));
        }
    }
    cout << (*c.begin()) << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll INT;
    cin >> INT;
    while (INT)
    {
        solve();
        INT--;
    }
    return 0;
}