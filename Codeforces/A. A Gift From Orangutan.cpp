#include <iostream>

using namespace std;

int Gift(int a[], int n)
{
    int min = 0;
    int max = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[max])
        {
            max = i;
        }
        if (a[i] < a[min])
        {
            min = i;
        }
    }

    return (a[max] - a[min]) * (n - 1);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << Gift(a, n) << endl;
    }

    return 0;
}
