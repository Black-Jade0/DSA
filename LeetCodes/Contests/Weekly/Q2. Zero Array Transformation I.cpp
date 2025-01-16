#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> diff(n + 1, 0); // Difference array

        // Mark the start and end + 1 for each range in the difference array
        for (int i = 0; i < queries.size(); i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            diff[start] -= 1;
            if (end + 1 < n)
            {
                diff[end + 1] += 1;
            }
        }

        // Apply the difference array to modify the nums array
        int currentDecrement = 0;
        for (int i = 0; i < n; i++)
        {
            currentDecrement += diff[i];
            nums[i] += currentDecrement;
        }

        // Check if all elements in nums are <= 0
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{

    return 0;
}