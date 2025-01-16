#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<char, int> map2;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == '.')
                    continue;
                if (map2.find(board[i][j]) != map2.end())
                    return false;
                map2[board[i][j]] = 1;
            }
            map2.clear();
        }

        map2.clear();
        for (int j = 0; j < board.size(); j++)
        {
            for (int i = 0; i < board.size(); i++)
            {
                if (board[i][j] == '.')
                    continue;
                if (map2.find(board[i][j]) != map2.end())
                    return false;
                map2[board[i][j]] = 1;
            }
            map2.clear();
        }

        map2.clear();
        int i = 0, m = 0;
        while (i < board.size() && m < board[0].size())
        {
            for (int k = i; k < i + 3; k++)
            {
                for (int j = m; j < m + 3; j++)
                {
                    if (board[k][j] == '.')
                        continue;
                    if (map2.find(board[k][j]) != map2.end())
                        return false;
                    map2[board[k][j]] = 1;
                }
            }
            i += 3;
            if (i >= board.size())
            {
                m += 3;
                i = 0;
            }
            map2.clear();
        }

        return true;
    }
};

int main()
{
    // Your code goes here

    return 0;
}