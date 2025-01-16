#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int INP;
    cin >> INP;

    while (INP--)
    {
        int len, k;
        cin >> len >> k;

        vector<int> a(len);
        for (int i = 0; i < len; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int sum = 0;
        while (--len >= 0)
        {
            if (sum + a[len] <= k)
            {
                sum += a[len];
            }
            else
            {
                break;
            }
        }
        cout << k - sum << '\n';
    }
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, k;
//         cin >> n >> k;
//         vector<int> a(n);
//         for (auto &x : a)
//             cin >> x;
//         sort(a.begin(), a.end(), greater<int>());
//         int sum = 0;
//         for (auto &x : a)
//         {
//             if (sum + x <= k)
//                 sum += x;
//             else
//                 break;
//         }
//         cout << k - sum << '\n';
//     }
// }