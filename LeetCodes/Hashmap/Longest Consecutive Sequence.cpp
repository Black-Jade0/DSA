#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.size() == 0)
        {
            return 0;
        }
        int length = 1;
        int max_length = 1;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                length++;
                if (length > max_length)
                {
                    max_length = length;
                }
            }
            else{
                length = 1;
            }
        }
        return max_length;
    }
};

int main()
{
    // Your code goes here

    return 0;
}