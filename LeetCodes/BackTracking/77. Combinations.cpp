#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void helper(vector<vector<int>> &result, int n, int k, int curr, vector<int> &way_result)
    {
        if (way_result.size() == k)
        {
            result.push_back(way_result);
            return;
        }
        for (int i = curr; i <= n; i++)
        {
            way_result.push_back(i);
            helper(result, n, k, i + 1, way_result);
            way_result.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        if (k == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                result.push_back({i});
            }
            return result;
        }
        if (n == k)
        {
            result.push_back({});
            for (int i = 1; i <= n; i++)
            {
                result[0].push_back(i);
            }
            return result;
        }
        vector<int> way_result;
        helper(result, n, k, 1, way_result);
        return result;
    }
};

int main()
{
    // Your code goes here

    return 0;
}