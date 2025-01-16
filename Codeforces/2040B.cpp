#include <bits/stdc++.h>

using namespace std;

int main()
{
    int INP;
    cin >> INP;
    while (INP--)
    {
        int n;
        cin >> n;
        int result = 1;
        int sum = 1;
        while (sum < n)
        {
            result++;
            sum = (sum + 1) * 2 ;
        }
        cout << result << endl;
    }
    return 0;
}