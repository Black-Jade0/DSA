#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        if (intervals.size() == 0)
        {
            intervals.push_back(newInterval);
            return intervals;
        }

        int insert_index = 0;
        int upper_value = newInterval[1];
        int lower_value = newInterval[0];

        // Find the position to insert newInterval
        while (insert_index < intervals.size() && lower_value >= intervals[insert_index][0])
        {
            insert_index++;
        }

        // Insert if no overlap with the previous one
        if (insert_index == 0 || lower_value > intervals[insert_index - 1][1])
        {
            intervals.insert(intervals.begin() + insert_index, newInterval);
        }
        else
        {
            // Merge with previous interval
            insert_index--;
        }

        // Check if no overlap with next interval
        if (insert_index == intervals.size() - 1 || upper_value < intervals[insert_index + 1][0])
        {
            intervals[insert_index][1] = max(upper_value, intervals[insert_index][1]);
            return intervals;
        }

        // Merge intervals as needed
        int i = insert_index + 1;
        while (i < intervals.size() && intervals[i][0] <= upper_value)
        {
            i++;
        }

        intervals[insert_index][1] = max(upper_value, intervals[i - 1][1]);
        intervals.erase(intervals.begin() + insert_index + 1, intervals.begin() + i);
        return intervals;
    }

    // Upper one (our) cant handle edges correctly 
    // OK BOTH ARE CORRECT NOW

    vector<vector<int>> insert2(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();

        while (i < n && intervals[i][1] < newInterval[0])
        {
            result.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        while (i < n)
        {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    Solution a;
    vector<int> b = {4, 8};
    vector<vector<int>> result = a.insert(intervals, b);
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