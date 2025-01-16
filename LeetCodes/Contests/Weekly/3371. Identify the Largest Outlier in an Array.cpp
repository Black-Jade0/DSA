#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int getLargestOutlier(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            sum += nums[i];
        }
        int result_index = nums.size() - 2;
        int last = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            sum -= nums[i];
            if (sum == last)
            {
                return nums[i];
            }
            sum += nums[i];
        }
        return last;
    }
};

int main()
{
    // Your code goes here

    return 0;
}