#include <iostream>
#include <vector>

using namespace std;

// class Solution
// {
// public:
//     int maxSubarraySumCircular(vector<int> &nums)
//     {
//         int currsum = 0;
//         int max_sum = INT_MIN;
//         int start = 0;
//         for (int i = 0; i < (nums.size() * 2) - 1; i++)
//         {
//             int a = i % nums.size();
//             if (start % nums.size() == a && start < nums.size() && i >= nums.size())
//             {
//                 currsum -= nums[a];
//                 max_sum = max(max_sum, currsum);
//                 start++;
//                 while(nums[start % nums.size()] <=0){
//                     currsum -=nums[start];
//                     start++;
//                 }
//             }
//             currsum = currsum + nums[a];
//             max_sum = max(max_sum, currsum);
//             if (currsum <= 0)
//             {
//                 currsum = 0;
//                 start = i + 1;
//             }
//             if (start > nums.size())
//             {
//                 break;
//             }
//         }
//         return max_sum;
//     }
// };

//  ALMOST CORRECT BUT WRONG ANSWER IN 4 CASES, CANT KNOW AS THEY ARE TOOO BIG (TIERED)
//  LEARN A NEW METHOD

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();
        int max_sum = nums[0];
        int curr_max = nums[0];
        int total_sum = nums[0];
        int min_sum = nums[0];
        int curr_min = nums[0];

        // Iterate through the array to calculate max subarray sum and min subarray sum
        for (int i = 1; i < n; i++)
        {
            // Standard Kadane's algorithm for max subarray sum
            curr_max = max(nums[i], curr_max + nums[i]);
            max_sum = max(max_sum, curr_max);

            // Kadane's algorithm for min subarray sum
            curr_min = min(nums[i], curr_min + nums[i]);
            min_sum = min(min_sum, curr_min);

            // Total sum of the array
            total_sum += nums[i];
        }

        // If all numbers are negative, the max sum is the maximum single element
        if (max_sum < 0)
        {
            return max_sum;
        }

        // The result is the maximum of max_sum and (total_sum - min_sum)
        return max(max_sum, total_sum - min_sum);
    }
};

int main()
{
    Solution a;
    vector<int> b = {-5, -2, 5, 6, -2, -7, 0, 2, 8};
    int ans = a.maxSubarraySumCircular(b);
    cout << ans;
    return 0;
}