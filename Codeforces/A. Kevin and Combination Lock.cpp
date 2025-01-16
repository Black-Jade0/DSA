#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int x;
        cin >> x;
        bool found = false;
        while (x >= 33)
        {
            if (x % 33 == 0)
            {
                cout << "YES\n";
                found = true;
                break;
            }
            else
            {
                string num = to_string(x);
                string updated = "";
                int count = 0;

                for (int i = 0; i < num.size(); ++i)
                {
                    if (count == 2)
                        break;

                    if (i < num.size() - 1 && num[i] == '3' && num[i + 1] == '3')
                    {
                        count++;
                        i++;
                    }
                    else
                    {
                        updated += num[i];
                    }
                }
                x = stoi(updated);
            }
        }
        if (!found)
        {
            cout << "NO\n";
        }
    }
    return 0;
}
