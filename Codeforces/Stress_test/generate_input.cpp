#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Define constraints
    const int t_max = 100;
    const int n_min = 1, n_max = 20;
    const int k_min = 2, k_max = 10;
    const int num_min = 1, num_max = 100; // Range for the numbers

    // Initialize random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist_t(1, t_max);
    uniform_int_distribution<> dist_n(n_min, n_max);
    uniform_int_distribution<> dist_k(k_min, k_max);
    uniform_int_distribution<> dist_num(num_min, num_max);

    // Generate random input
    int t = dist_t(gen); // Random number of test cases
    vector<pair<int, int>> test_cases;
    vector<vector<int>> numbers;

    for (int i = 0; i < t; ++i)
    {
        int n = dist_n(gen); // Random n
        int k = dist_k(gen); // Random k
        test_cases.emplace_back(n, k);

        // Generate n random numbers in the range [1, 100]
        vector<int> nums;
        for (int j = 0; j < n; ++j)
        {
            nums.push_back(dist_num(gen));
        }
        numbers.push_back(nums);
    }

    // Print the input
    cout << test_cases.size() << endl; // Print the number of test cases
    for (int i = 0; i < test_cases.size(); ++i)
    {
        const auto &[n, k] = test_cases[i];
        cout << n << " " << k << endl; // Print n and k
        for (int num : numbers[i])
        {
            cout << num << " "; // Print n numbers
        }
        cout << endl;
    }

    return 0;
}
