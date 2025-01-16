#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int count = 0;
        int circle = n/2;
        for (; count < circle; count++)
        {
            for (size_t i = count; i < n - count - 1; i++)
            {
                int temp = matrix[count][i];
                matrix[count][i] = matrix[i][n - count - 1];
                matrix[i][n - count - 1] = temp;
            }
            for (size_t i = n - count - 1; i > count; i--)
            {
                int temp = matrix[n - count - 1][i];
                matrix[n - count - 1][i] = matrix[i][count];
                matrix[i][count] = temp;
            }
            for (size_t i = count; i < n - count - 1; i++)
            {
                int temp = matrix[count][i];
                matrix[count][i] = matrix[n - count - 1][n - i - 1];
                matrix[n - count - 1][n - i - 1] = temp;
            }
        }
        return;
    }
};

int main() {
    Solution a;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    a.rotate(matrix);
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}