#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> que;
        vector<int> help1 = {-1, 0, 1, 0};
        vector<int> help2 = {0, 1, 0, -1};
        int fresh = 0;
        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    que.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        if (fresh == 0)
        {
            return 0;
        }

        int time = 0;
        while (!que.empty())
        {
            int size = que.size();
            for (size_t i = 0; i < size; i++)
            {
                pair<int, int> temp = que.front();
                que.pop();
                for (size_t j = 0; j < 4; j++)
                {
                    int first = temp.first + help1[j];
                    int second = temp.second + help2[j];
                    if (first < 0 || first >= grid.size() || second < 0 || second >= grid[0].size())
                    {
                        continue;
                    }
                    if (grid[first][second] == 1)
                    {
                        que.push({first, second});
                        grid[first][second] = 2;
                        fresh--;
                    }
                }
            }
            time++;
        }
        if (fresh == 0)
        {

            return time - 1;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    // Your code goes here

    return 0;
}