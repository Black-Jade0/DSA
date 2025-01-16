#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &p)
    {
        sort(p.begin(), p.end());
        int lastpoint = p[0][1];
        int ans = 1;
        for (auto point : p)
        {
            if (point[0] > lastpoint)
            {
                ans++;
                lastpoint = point[1];
            }
            lastpoint = min(point[1], lastpoint);
        }
        return ans;
    }
};

int main()
{
    return 0;
}