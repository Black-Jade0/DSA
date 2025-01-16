#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int size = nums.size();
        int spawn = 0;
        int i = 1;
        int fuel = nums[spawn];
        for (; i < size && fuel > 0; i++)
        {
            fuel--;
            if (fuel <= nums[i])
            {
                spawn = i;
                fuel = nums[spawn];
            }
        }
        cout << i;
        if (i == size)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    // Your code goes here
    vector<int> arr = {1, 2, 3};
    cout << arr.size() << endl;
    Solution object;
    if (object.canJump(arr))
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