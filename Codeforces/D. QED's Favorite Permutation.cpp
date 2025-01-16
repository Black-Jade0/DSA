#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool canSort(const vector<int> &p, const string &s)
{
    int n = p.size();
    vector<int> left, right;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'L')
            left.push_back(p[i]);
        else
            right.push_back(p[i]);
    }

    for (int i = 0; i < left.size(); ++i)
    {
        if (left[i] < i + 1)
        {
            return false;
        }
    }

    for (int i = 0; i < right.size(); ++i)
    {
        if (right[i] > n - i)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> p(n);
        string s;

        for (int i = 0; i < n; ++i)
        {
            cin >> p[i];
        }

        cin >> s;

        while (q--)
        {
            int index;
            cin >> index;

            if (s[index - 1] == 'L')
                s[index - 1] = 'R';
            else
                s[index - 1] = 'L';

            if (canSort(p, s))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
