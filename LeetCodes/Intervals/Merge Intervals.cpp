#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        for (size_t i = 0; i < intervals.size(); i++)
        {
            vector<int> temp_interval = intervals[i];
            bool merged = false;
            for (size_t j = i + 1; j < intervals.size(); j++)
            {
                vector<int> check_interval = intervals[j];
                if (check_interval[0] >= temp_interval[0] && check_interval[1] <= temp_interval[1])
                {
                    intervals[j][0] = intervals[i][0];
                    intervals[j][1] = intervals[i][1];
                    merged = true;
                    break;
                }
                else if (check_interval[0] <= temp_interval[0] && check_interval[1] >= temp_interval[1])
                {
                    merged = true;
                    break;
                }
                else if (check_interval[0] <= temp_interval[1] && check_interval[1] >= temp_interval[1])
                {
                    intervals[j][0] = intervals[i][0];
                    merged = true;
                    break;
                }
                else if (check_interval[0] <= temp_interval[0] && check_interval[1] >= temp_interval[0])
                {
                    intervals[j][1] = intervals[i][1];
                    merged = true;
                    break;
                }
            }
            if (merged)
            {
                intervals.erase(intervals.begin() + i);
                i--;
            }
            else
            {
                continue;
            }
        }
        return intervals;
    }

    // Correct but TLE
    // Ofcourse u thought of sorting, yeah it does take less time

    vector<vector<int>> merge2(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        vector<vector<int>> merged;
        vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size(); ++i)
        {
            vector<int> interval = intervals[i];
            if (interval[0] <= prev[1])
            {
                prev[1] = max(prev[1], interval[1]);
            }
            else
            {
                merged.push_back(prev);
                prev = interval;
            }
        }
        merged.push_back(prev);
        return merged;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution a;
    vector<vector<int>> result = a.merge(intervals);
    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}