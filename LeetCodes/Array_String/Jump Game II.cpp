#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int size = nums.size();
        int spawn = 0;
        int jumps_count = 0;
        for (; spawn < size - 1;)
        {
            int range = nums[spawn];
            if (range >= size - spawn - 1)
            {
                jumps_count++;
                break;
            }
            int max_fuel_index = spawn;
            for (int j = spawn + 1; j <= range + spawn && j < size; j++)
            {
                if (nums[j] + j > nums[max_fuel_index] + max_fuel_index)
                {
                    max_fuel_index = j;
                }
            }
            jumps_count++;
            spawn = max_fuel_index;
        }
        return jumps_count;
    }
};

int main()
{
    // Your code goes here
    vector<int> arr = {1, 2, 3};
    cout << arr.size() << endl;
    Solution object;
    if (object.jump(arr))
    {
        cout << endl;
        cout << "TRUE";
    }
    else
    {
        cout << endl;
        cout << "FALSE";
    }

    return 0;
}