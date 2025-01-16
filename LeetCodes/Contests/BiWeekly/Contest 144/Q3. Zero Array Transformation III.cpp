#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

// class Solution
// {
// public:
//     int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
//     {
//         int n = nums.size();
//         int ans = 0;
//         vector<int> freq(n + 1, 0);
//         for (int i = 0; i < queries.size(); i++)
//         {
//             int left = queries[i][0];
//             int right = queries[i][1];
//             freq[left] -= 1;
//             freq[right + 1] += 1;
//         }
//         int curr = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             curr += freq[i];
//             nums[i] += curr;
//             if (nums[i] > 0)
//             {
//                 return -1;
//             }
//         }
//         vector<int> help = nums;
//         for (int i = 0; i < queries.size(); i++)
//         {
//             int left = queries[i][0];
//             int right = queries[i][1];
//             bool done = true;
//             for (int j = left; j <= right; j++)
//             {
//                 help[j]++;
//                 if (help[j] > 0)
//                 {
//                     help = nums;
//                     done = false;
//                     break;
//                 }
//             }
//             if (done)
//             {
//                 ans++;
//             }
//             nums = help;
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
    {
        multiset<int> pool;
        multiset<int> used;
        sort(queries.begin(), queries.end(), [](vector<int> &a, vector<int> &b)
             {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] > b[1]; });

        int cur = 0;
        int j = 0;
        int sol = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (used.size() && *used.begin() == i)
            {
                cur--;
                used.erase(used.begin());
            }
            while (pool.size() && *pool.begin() == i)
            {
                pool.erase(pool.begin());
            }
            while (cur < nums[i] && (j < queries.size() && queries[j][0] <= i || pool.size()))
            {
                if (j < queries.size() && queries[j][0] == i && pool.size())
                {
                    auto p = *pool.rbegin();
                    auto q = queries[j];
                    if (p > q[1])
                    {
                        used.insert(p);
                        pool.erase(prev(pool.end()));
                    }
                    else
                    {
                        used.insert(q[1] + 1);
                        j++;
                    }
                }
                else if (pool.size())
                {
                    auto p = *pool.rbegin();
                    used.insert(p);
                    pool.erase(prev(pool.end()));
                }
                else if (j < queries.size() && queries[j][0] <= i)
                {
                    auto q = queries[j];
                    used.insert(q[1] + 1);
                    j++;
                }
                cur++;
                sol++;
            }
            if (cur < nums[i])
                return -1;

            while (j < queries.size() && queries[j][0] == i)
            {
                pool.insert(queries[j][1] + 1);
                j++;
            }
        }
        return queries.size() - sol;
    }
};

class Solution
{
public:
    int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> prefix(n + 1);
        sort(begin(queries), end(queries));
        priority_queue<pair<int, int>> pq;
        int j = 0;
        int res = queries.size();
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                prefix[i] += prefix[i - 1];
            while (j < queries.size() && queries[j][0] <= i)
            {
                pq.push({queries[j][1], queries[j][0]});
                ++j;
            }
            while (!pq.empty() && pq.top().first >= i && nums[i] + prefix[i] > 0)
            {
                auto [r, l] = pq.top();
                pq.pop();
                prefix[i]--;
                prefix[r + 1]++;
                --res;
            }

            if (nums[i] + prefix[i] > 0)
                return -1;
        }
        return res;
    }
};

int main()
{
    // Your code goes here

    return 0;
}