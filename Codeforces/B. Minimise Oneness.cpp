#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        s += '1';
        for (int i = 0; i < n - 1; ++i)
        {
            s += '0';
        }

        cout << s << endl;
    }

    return 0;
}
