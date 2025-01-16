#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {

        int low = 0;

        int high = nums.size() - 1;

        int mid = 0;
        if (target <= nums[0])
        {
            return 0;
        }

        while (high >= low)
        {

            if (target == nums[mid])
            {
                return mid;
            }
            else if (target > nums[mid])
            {
                low = mid + 1;
            }
            else if (target < nums[mid])
            {
                high = mid - 1;
            }
            mid = (low + high) / 2;
        }

        return mid + 1;
    }
};

int main() {
    // Your code goes here

    return 0;
}