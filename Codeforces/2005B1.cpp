#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, q;
    int x, y;
    int place;
    cin >> n >> m >> q;
    cin >> x >> y;
    cin >> place;
    if (x > y)
    {
        swap(x,y);
    }
    int ans = 0;
    if (place < x && place < y)
    {
        cout << x - 1 << endl;
        return;
    }
    else if (place > x && place < y){
        cout << abs(y - x)/2 << endl;
        return;
    }
    else{
        cout << n - y << endl;
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