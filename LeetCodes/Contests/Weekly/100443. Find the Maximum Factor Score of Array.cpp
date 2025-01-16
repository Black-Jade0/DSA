#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#include <vector>
#include <algorithm> // For std::max
#include <numeric>   // For gcd
using namespace std;

class Solution
{
public:
    long long maxScore(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0] * nums[0];

        long long max_product = 0;

        // Try removing each element one by one
        for (size_t i = 0; i < nums.size(); i++)
        {
            long long curr_g = 0;
            long long curr_l = 1;

            for (size_t j = 0; j < nums.size(); j++)
            {
                if (i == j)
                {
                    continue; // Skip the removed element
                }
                curr_g = gcd(curr_g, nums[j]);
                curr_l = (curr_l * nums[j]) / gcd(curr_l, nums[j]);
            }
            max_product = max(max_product, curr_g * curr_l);
        }

        // Calculate g * l without removing any element
        long long curr_g = 0;
        long long curr_l = 1;
        for (size_t i = 0; i < nums.size(); i++)
        {
            curr_g = gcd(curr_g, nums[i]);
            curr_l = (curr_l * nums[i]) / gcd(curr_l, nums[i]);
        }
        max_product = max(max_product, curr_g * curr_l);

        return max_product;
    }

private:
    // Custom GCD function for long long types
    long long gcd(long long a, long long b)
    {
        while (b != 0)
        {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main()
{
    // Your code goes here

    return 0;
}