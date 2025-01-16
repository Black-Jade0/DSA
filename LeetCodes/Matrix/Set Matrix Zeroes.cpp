#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        set<int> rows;
        set<int> cols;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for (auto i = rows.begin(); i != rows.end(); i++)
        {
            int row = *i;
            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                matrix[row][j] = 0;
            }
        }
        for (auto i = cols.begin(); i != cols.end(); i++)
        {
            int col = *i;
            for (size_t j = 0; j < matrix.size(); j++)
            {
                matrix[j][col] = 0;
            }
        }
        return;
    }
};

int main()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    Solution a;
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    a.setZeroes(matrix);
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}