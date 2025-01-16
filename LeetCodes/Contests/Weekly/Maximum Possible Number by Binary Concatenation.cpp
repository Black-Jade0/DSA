#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxGoodNumber(vector<int> &nums)
    {
        string binary = "";
        vector<string> binary_string;

        for (size_t i = 0; i < nums.size(); i++)
        {
            int single_binary = 0;
            int help = 1;
            while (nums[i] != 0)
            {
                int remainder = nums[i] % 2;
                nums[i] = nums[i] / 2;
                single_binary = single_binary + (remainder * help);
                help = help * 10;
            }
            binary_string[i] = to_string(single_binary);
        }
        string ans;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (i != j && j != k && i != k)
                    {
                        string con = binary_string[i] + binary_string[j] + binary_string[k];
                        if (con > ans)
                        {
                            ans = con;
                        }
                    }
                }
            }
        }
        int res = stoi(ans, nullptr, 2);
        return res;
    }
};

int main()
{
    vector<int> nums = {1, 11, 5};
    Solution a;
    int result = a.maxGoodNumber(nums);
    cout << result;
    return 0;
}