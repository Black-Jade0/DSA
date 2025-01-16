#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    set<pair<int, int>> mp;
    bool dfs(vector<vector<char>> &grid, int i, int j, int parent_i, int parent_j, int val)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != val)
        {
            return false;
        }
        if (grid[i][j] == val && mp.find({i, j}) != mp.end())
        {
            return true;
        }
        mp.insert({i, j});
        return (i - 1 != parent_i && dfs(grid, i - 1, j, i, j, val)) ||
               (i + 1 != parent_i && dfs(grid, i + 1, j, i, j, val)) ||
               (j - 1 != parent_j && dfs(grid, i, j - 1, i, j, val)) ||
               (j + 1 != parent_j && dfs(grid, i, j + 1, i, j, val));
    }
    bool containsCycle(vector<vector<char>> &grid)
    {
        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[0].size(); j++)
            {
                if (mp.find({i, j}) == mp.end())
                {
                    if (dfs(grid, i, j, -1, -1, grid[i][j]))
                    {
                        return true;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
        return false;
    }

    int vis[500][500];
    int n, m;
    vector<int> dr{-1, 0, 1, 0};
    vector<int> dc{0, 1, 0, -1};
    bool dfs2(vector<vector<char>> &grid, int i, int j, int p_i, int p_j, char ch)
    {
        if (vis[i][j])
            return true;
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++)
        {
            int r = i + dr[k];
            int c = j + dc[k];
            if (r == p_i && c == p_j)
                continue;
            if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == ch)
            {
                if (dfs2(grid, r, c, i, j, grid[r][c]))
                    return true;
            }
        }
        return false;
    }
    bool containsCycle2(vector<vector<char>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j])
                {
                    if (dfs(grid, i, j, -1, -1, grid[i][j]))
                        return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    // Your code goes here

    return 0;
}