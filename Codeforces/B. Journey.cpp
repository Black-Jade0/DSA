#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int sum = a + b + c;
    int div = n / sum;
    int left = n % sum;
    if (left == 0)
    {
        cout << (3 * div) << endl;
        return;
    }
    if (left > a + b)
    {
        cout << (3 * div) + 3 << endl;
        return;
    }
    if (left > a)
    {
        cout << (3 * div) + 2 << endl;
        return;
    }
    else
    {
        cout << (3 * div) + 1 << endl;
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