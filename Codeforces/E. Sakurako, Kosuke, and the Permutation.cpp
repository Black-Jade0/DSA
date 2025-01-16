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

void solve(mpii &track)
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        track[a[i]] = i + 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == i + 1 || a[a[i] - 1] == i + 1)
        {
            continue;
        }
        int index_iplusplus = track[i+1] - 1;
        int curr = a[i];
        ans++;
        if (curr == index_iplusplus + 1 || a[curr - 1] == index_iplusplus + 1)
        {
            track[a[i]] = index_iplusplus + 1;
            track[a[index_iplusplus]] = i + 1;
            swap(a[i],a[index_iplusplus]);
        }
        else{
            int indexofindex = track[index_iplusplus + 1] - 1;
            track[a[i]] = indexofindex + 1;
            track[a[indexofindex]] = i + 1;
            swap(a[i],a[indexofindex]);
        }
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
    mpii track;
    while (INP--)
    {
        solve(track);
    }
    return 0;
}