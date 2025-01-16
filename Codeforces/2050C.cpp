#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int sum = 0;
    int two_sum = 0;
    int three_sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        sum += s[i] - '0';
        if (s[i] - '0' == 2)
        {
            two_sum += 2;
        }
        if (s[i] - '0' == 3)
        {
            three_sum += 6;
        }
    }
    if (sum % 9 == 0)
    {
        cout << "YES" << endl;
        return;
    }
    int fire = 9 - (sum % 9);
    while (fire <= two_sum + three_sum)
    {
        if (fire % 2 != 0)
        {
            fire += 9;
            continue;
        }
        int temp_fire = fire;
        int temp_two = two_sum;
        int temp_three = three_sum;
        while (temp_three >= 6 && temp_fire >= 6)
        {
            temp_fire -= 6;
            temp_three -= 6;
        }
        while (temp_two >= 2 && temp_fire >= 2)
        {
            temp_fire -= 2;
            temp_two -= 2;
        }
        if (temp_fire == 0)
        {
            cout << "YES" << endl;
            return;
        }
        fire += 18;
    }
    cout << "NO" << endl;
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