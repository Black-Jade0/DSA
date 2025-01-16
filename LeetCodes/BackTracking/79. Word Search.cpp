#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool result = false;
    vector<int> helper = {-1, 0, 1, 0, -1};

    void help(int i, int j, vector<vector<char>> &board, string &word, int word_index)
    {
        if (word_index == word.size())
        {
            result = true;
            return;
        }

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[word_index] || result)
        {
            return;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        for (int k = 0; k < 4; k++)
        {
            help(i + helper[k], j + helper[k + 1], board, word, word_index + 1);
        }

        board[i][j] = temp;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0] && !result)
                {
                    help(i, j, board, word, 0);
                }
            }
        }
        return result;
    }
};

int main()
{
    // Your code goes here

    return 0;
}