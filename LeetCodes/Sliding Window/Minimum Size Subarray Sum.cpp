#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        if (nums[0] >= target)
        {
            return 1;
        }
        if (nums.size() == 1)
        {
            return 0;
        }
        int result = nums.size();
        int first = 0;
        int second = 1;
        int sum = nums[0] + nums[1];
        while (first < nums.size() && second < nums.size())
        {
            if (sum < target)
            {
                second++;
                if (second == nums.size())
                {
                    break;
                }
                sum += nums[second];
            }
            else
            {
                if (result > second - first + 1)
                {
                    result = second - first + 1;
                }
                sum -= nums[first];
                first++;
            }
        }
        if (first == 0 && second == nums.size())
        {
            return 0;
        }
        return result;
    }
    int minSubArrayLen2(int target, vector<int> &nums)
    {
        int left = 0, min_sum = 0, min_len = nums.size(), sum = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                if (min_len >= (right - left + 1))
                {
                    min_len = right - left + 1;
                    min_sum = sum;
                }
                sum -= nums[left++];
            }
        }
        return (min_sum < target) ? 0 : min_len;
    }
};


int main()
{
    // Your code goes here

    return 0;
}