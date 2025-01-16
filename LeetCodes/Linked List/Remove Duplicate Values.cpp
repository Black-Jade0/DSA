#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int size = nums.size();
        int k = 0;
        int duplicate = 0;
        int a = 0;
        for (int i = 1; i < size; i++)
        {
            if (nums[i - 1] == nums[i])
            {
                duplicate++;
                if (duplicate <= 1)
                {
                    a++;
                    nums[a] = nums[i];
                    k++;
                }
            }
            else
            {
                a++;
                nums[a] = nums[i];
                k++;
                duplicate = 0;
            }
        }
        k++;
        return k;
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 2, 3, 4, 4, 5, 5, 5, 5};
    Solution sol;
    int k = sol.removeDuplicates(nums);
    cout << k;
    cout << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}