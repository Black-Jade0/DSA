#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    set<pair<int, int>> trace;
    void trace_all(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == 'X' || trace.count({i, j}) == 1)
        {
            return;
        }
        trace.insert({i, j});
        trace_all(board, i - 1, j);
        trace_all(board, i, j - 1);
        trace_all(board, i, j + 1);
        trace_all(board, i + 1, j);
        return;
    }
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        int i;
        for (i = 0; i < n; i++)
        {
            if (board[0][i] == 'O')
            {
                trace_all(board, 0, i);
            }
        }
        for (i = 0; i < n; i++)
        {
            if (board[m - 1][i] == 'O')
            {
                trace_all(board, m - 1, i);
            }
        }
        for (i = 1; i < m - 1; i++)
        {
            if (board[i][0] == 'O')
            {
                trace_all(board, i, 0);
            }
        }
        for (i = 1; i < m - 1; i++)
        {
            if (board[i][n - 1] == 'O')
            {
                trace_all(board, i, n - 1);
            }
        }
        for ( i = 0; i < board.size(); i++)
        {
            fill(board[i].begin(),board[i].end(),'X');
        }
        for (auto i = trace.begin(); i != trace.end(); i++)
        {
            board[i->first][i->second] = 'O';
        }
        return;
    }
};

int main()
{
    // Your code goes here

    return 0;
}