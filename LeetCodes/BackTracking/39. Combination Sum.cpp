#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void helper(vector<int> candidates, vector<vector<int>> &result, vector<int> &way_result, int target,int start)
    {
        if (target == 0)
        {
            result.push_back(way_result);
            return;
        }
        if (target < 0)
        {
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            way_result.push_back(candidates[i]);
            helper(candidates, result, way_result, target - candidates[i],i);
            way_result.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> way_result;
        helper(candidates, result, way_result, target,0);
        return result;
    }
};

int main()
{
    // Your code goes here

    return 0;
}