#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Define constraints
    const int t_max = 100;
    const int n_min = 2, n_max = 5;
    const int m_min = 1, m_max = 5;
    const int x_min = 1, x_max = 8;

    // Initialize random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist_t(1, t_max);
    uniform_int_distribution<> dist_n(n_min, n_max);
    uniform_int_distribution<> dist_m(m_min, m_max);
    uniform_int_distribution<> dist_x(x_min, x_max);

    // Generate random input
    int t = dist_t(gen);
    cout << t << endl;
    for (int i = 0; i < t; ++i)
    {
        int n = dist_n(gen);
        int m = dist_m(gen);
        int d = dist_x(gen);
        cout << n << " " << m << " " << d << endl;

        uniform_int_distribution<> char_gen(0, 1); // Randomly generate 'X' or '.'
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                cout << (char_gen(gen) ? 'X' : '.');
            }
            cout << endl;
        }
    }

    return 0;
}
