#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxIncreasingSubarrays(vector<int> &nums)
    {
        int max_k = 0;
        int max_sorted = 0;
        int track = 0;
        if (nums.size() == 2 || nums.size() == 3)
        {
            return 1;
        }
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (i == nums.size() - 2 && nums[i] < nums[i + 1])
            {
                max_k = max(max_k, (i - track + 2) / 2);
            }
            else if(nums[i + 1] <= nums[i])
            {
                int sorted = i - track + 1;
                max_k = max(max_k,sorted/2);
                if (2 * (sorted) > max_k)
                {
                    for (int j = i + 1; j < nums.size() - 1; j++)
                    {
                        if (nums[j + 1] <= nums[j] )
                        {
                            max_k = max(max(sorted / 2, max_k), min(j - i, sorted));
                            break;
                        }
                        if (j + 1 == nums.size() - 1)
                        {
                            j++;
                            max_k = max(max(sorted / 2, max_k), min(j - i, sorted));
                            break;
                        }
                    }
                }
                track = i + 1;
            }
        }
        return max_k;
    }
};
int main()
{
    Solution a;
    vector<int> nums = {-18, -17, 12, 4};
    int ans = a.maxIncreasingSubarrays(nums);
    cout << ans;
    return 0;
}