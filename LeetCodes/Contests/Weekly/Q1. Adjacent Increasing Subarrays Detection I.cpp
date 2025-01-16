#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool hasIncreasingSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        for (int front = 0; front <= n - 2 * k; front++)
        {
            bool found = true;
            // Check the first subarray of length k
            for (int i = front; i < front + k - 1; i++)
            {
                if (nums[i + 1] <= nums[i])
                {
                    found = false;
                    break;
                }
            }

            // Check the second subarray of length k starting at front + k
            if (found)
            {
                for (int i = front + k; i < front + 2 * k - 1; i++)
                {
                    if (nums[i + 1] <= nums[i])
                    {
                        found = false;
                        break;
                    }
                }
            }

            if (found)
            {
                return true;
            }
        }

        // If no increasing subarrays are found, return false
        return false;
    }
};

int main() {
    // Your code goes here

    return 0;
}