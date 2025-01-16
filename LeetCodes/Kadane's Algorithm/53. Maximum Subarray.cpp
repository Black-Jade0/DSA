#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    //  KADANE ALGORITHM, IF THE CURRENT SUM IS NEGATIVE OR ITS MAKING THE NEXT NUMBER LOW
    //  THEN THERE IS NO NEED TO TAKE IT TO THE NEXT NUMBERS
    int maxSubArray(vector<int> &nums)
    {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};

int main()
{
    // Your code goes here

    return 0;
}