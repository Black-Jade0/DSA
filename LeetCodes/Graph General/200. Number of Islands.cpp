#include <iostream>
#include <vector>

using namespace std;

// class Solution
// {
// public:
//     int numIslands(vector<vector<char>> &grid)
//     {
//         int island = 0;
//         for (size_t i = 0; i < grid.size(); i++)
//         {
//             for (size_t j = 0; j < grid[0].size(); j++)
//             {
//                 if (grid[i][j] == '1')
//                 {
//                     if (i == 0 && j == 0)
//                     {
//                         if (grid[0][0] == '1')
//                         {
//                             island++;
//                         }
//                     }
//                     else if (j > 0 && i > 0)
//                     {
//                         if (grid[i][j - 1] != '1' && grid[i - 1][j] != '1')
//                         {
//                             island++;
//                         }
//                     }
//                     else if (j > 0)
//                     {
//                         if (grid[0][j - 1] != '1')
//                         {
//                             island++;
//                         }
//                     }
//                     else
//                     {
//                         if (grid[i - 1][0] != '1')
//                         {
//                             island++;
//                         }
//                     }
//                 }
//             }
//         }
//         return island;
//     }
// };

//  NOPE NOPE IT WONT DO, U ARE NOT CHECKING ALL THE CASES, WHAT IS ITS LIKE:
//  1   0   0
//  1   0   1
//  1   1   1
//  THE 1 AT (1,2) WILL BE CONSIDERED AS A NEW ISLAND (WRONG)

class Solution
{
public:
    void desolve(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
        {
            return;
        }
        grid[i][j] = '0';
        desolve(grid, i - 1, j);
        desolve(grid, i, j - 1);
        desolve(grid, i + 1, j);
        desolve(grid, i, j + 1);
        return;
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int island = 0;
        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    island++;
                    desolve(grid, i, j);
                }
            }
        }
        return island;
    }
};

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    Solution a;
    int result = a.numIslands(grid);
    cout << result;

    return 0;
}