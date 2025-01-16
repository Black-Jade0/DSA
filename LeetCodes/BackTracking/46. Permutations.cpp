#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    void helper(vector<int> &nums, set<int> &track, vector<int> &way_result,vector<vector<int>> &result)
    {
        if (track.size() == nums.size())
        {
            result.push_back(way_result);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (track.find(i) != track.end())
            {
                track.insert(i);
                way_result.push_back(nums[i]);
                helper(nums,track,way_result,result);
                way_result.pop_back();
                track.erase(i);
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        if (nums.size() == 1)
        {
            result.push_back({nums[0]});
            return result;
        }
        set<int> track;
        vector<int> way_result;
        helper(nums, track, way_result,result);
        return result;
    }
};

int main()
{
    // Your code goes here

    return 0;
}