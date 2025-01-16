#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    pair<int, int> get_coordinates(vector<vector<int>> &board, int block)
    {
        int n = board.size();
        int row = n - 1 - (block - 1) / n;
        int col = (block - 1) % n;

        if ((n - 1 - row) % 2 != 0) // Handle zigzag
        {
            col = n - 1 - col;
        }
        return {row, col};
    }

    int get_block(vector<vector<int>> &board, int block)
    {
        if (block >= board.size() * board.size())
            return block;
        auto coordinates = get_coordinates(board, block);
        if (board[coordinates.first][coordinates.second] != -1)
            return board[coordinates.first][coordinates.second]; // Move via snake/ladder
        return block;
    }

    int traverse(vector<vector<int>> &board, int block, vector<bool> &visited, int moves)
    {
        if (block == board.size() * board.size())
            return moves;
        visited[block] = true;
        int min_moves = INT_MAX;

        for (int i = 1; i <= 6; ++i)
        {
            int next_block = block + i;
            if (next_block <= board.size() * board.size() && !visited[next_block])
            {
                next_block = get_block(board, next_block);
                if (!visited[next_block])
                    min_moves = min(min_moves, traverse(board, next_block, visited, moves + 1));
            }
        }
        visited[block] = false;
        return min_moves;
    }

    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        int result = traverse(board, 1, visited, 0);
        return (result == INT_MAX) ? -1 : result;
    }
};

class Solution
{
public:
    pair<int, int> get_coordinates(vector<vector<int>> &board, int block)
    {
        int n = board.size();
        int row = n - 1 - (block - 1) / n;
        int col = (block - 1) % n;

        if ((n - 1 - row) % 2 != 0) // Handle zigzag
        {
            col = n - 1 - col;
        }
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty())
        {
            auto [block, moves] = q.front();
            q.pop();

            if (block == n * n)
                return moves;

            for (int i = 1; i <= 6; ++i)
            {
                int next_block = block + i;
                if (next_block <= n * n)
                {
                    auto coordinates = get_coordinates(board, next_block);
                    int row = coordinates.first, col = coordinates.second;

                    if (board[row][col] != -1)
                        next_block = board[row][col];

                    if (!visited[next_block])
                    {
                        visited[next_block] = true;
                        q.push({next_block, moves + 1});
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    // Your code goes here

    return 0;
}