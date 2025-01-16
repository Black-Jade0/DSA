#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] % 10 == 1)
                {
                    // CONDITIONS

                    // Excluding last column
                    if ((j + 1) < board[0].size())
                    {
                        board[i][j + 1] += 10;
                        // Excluding first column (vertical work is left (horizontal right side done with above line)) - rest all handeled
                        if ((j - 1) >= 0)
                        {
                            board[i][j - 1] += 10;
                            if ((i + 1) < board.size())
                            {
                                for (size_t k = -1; k < 2; k++)
                                {
                                    board[i + 1][j + k] += 10;
                                }
                            }
                            if ((i - 1) >= 0)
                            {
                                for (size_t k = -1; k < 2; k++)
                                {
                                    board[i - 1][j + k] += 10;
                                }
                            }
                        }
                        // Handeling first column
                        else
                        {
                            if ((i + 1) < board.size())
                            {
                                board[i + 1][j] += 10;
                                board[i + 1][j + 1] += 10;
                            }
                            if ((i - 1) >= 0)
                            {
                                board[i - 1][j] += 10;
                                board[i - 1][j + 1] += 10;
                            }
                        }
                    }
                    // Handeling last column
                    else
                    {
                        board[i][j - 1] += 10;
                        if ((i + 1) < board.size())
                        {
                            board[i + 1][j] += 10;
                            board[i + 1][j - 1]  += 10;
                        }
                        if ((i - 1) >= 0)
                        {
                            board[i - 1][j] += 10;
                            board[i - 1][j - 1] += 10;
                        }
                    }
                }
            }
        }

        // Updating the cells to next stage

        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                int element = board[i][j];
                if (element % 10 == 0 && element / 10 == 3)
                {
                    board[i][j] = 1;
                }
                else if (element % 10 == 1 && element / 10 < 2)
                {
                    board[i][j] = 0;
                }
                else if (element % 10 == 1 && element / 10 < 4)
                {
                    board[i][j] = 1;
                }
                else
                {
                    board[i][j] = 0;
                }
            }
        }
        return;
    }
    void gameOfLife2(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        // Step 1: Update the board using encoded values
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] % 10 == 1) // Cell alive?
                {
                    for (int di = -1; di <= 1; di++)
                    {
                        for (int dj = -1; dj <= 1; dj++)
                        {
                            if (di == 0 && dj == 0)
                                continue; // Current cell skipped

                            int ni = i + di;
                            int nj = j + dj;

                            // Neighbour present?
                            if (ni >= 0 && ni < m && nj >= 0 && nj < n)
                            {
                                board[ni][nj] += 10;
                            }
                        }
                    }
                }
            }
        }

        // Updating the cells to next stage

        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                int element = board[i][j];
                if (element % 10 == 0 && element / 10 == 3)
                {
                    board[i][j] = 1;
                }
                else if (element % 10 == 1 && element / 10 < 2)
                {
                    board[i][j] = 0;
                }
                else if (element % 10 == 1 && element / 10 < 4)
                {
                    board[i][j] = 1;
                }
                else
                {
                    board[i][j] = 0;
                }
            }
        }
        return;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    a.gameOfLife(board);
    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}