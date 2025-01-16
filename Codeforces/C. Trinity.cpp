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
    track.clear();
    int n;
    cin >> n;
    vi a(n);
    fi(i, n)
    {
        cin >> a[i];
        track[a[i]]++;
    }
    sort(a.begin(), a.end());
    int i = 0;
    pii segment = {0, 0};
    int maxl = 0;
    int sum = a[0] + a[1];
    int prev = 0;
    while (maxl <= n - i && i < n - 1)
    {
        sum = a[i] + a[i + 1];
        if (sum == prev)
        {
            i++;
            continue;
        }
        auto it = lower_bound(a.begin(), a.end(), sum);
        if (it == a.end())
        {
            if (n - i > maxl)
            {
                segment.first = i;
                segment.second = n;
                maxl = n - i;
            }
            break;
        }
        int index = it - a.begin();
        if (index - i  > maxl)
        {
            segment.first = i;
            segment.second = index;
            maxl =  index - i;
        }
        i++;
        prev = sum;
    }
    cout << n - maxl << endl;
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