#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        if (matrix.empty())
            return result;
        int i = 0;
        int j = 0;
        int rounds = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        if (m == 1)
        {
            for (size_t a = 0; a < n; a++)
            {
                result.push_back(matrix[a][0]);
            }
            return result;
        }

        int x;
        if (n % 2 == 0)
        {
            x = (n / 2) - 1;
        }
        else
        {
            x = m - (n / 2) - 1;
        }
        int y = n / 2;
        while (i != x && j != y)
        {
            for (; j < m - rounds; j++)
            {
                result.push_back(matrix[i][j]);
            }
            j--;
            i++;
            for (; i < n - rounds; i++)
            {
                result.push_back(matrix[i][j]);
            }
            i--;
            j--;
            for (; j >= rounds; j--)
            {
                result.push_back(matrix[i][j]);
            }
            j++;
            i--;
            rounds++;
            for (; i >= rounds; i--)
            {
                result.push_back(matrix[i][j]);
            }
            i++;
            j++;
        }
        while (j < m - rounds)
        {
            result.push_back(matrix[i][j]);
            j++;
        }

        return result;
    }

    // OUR IS WRONG
    // Cant handle all the values for m and n
    // Actually our approach is wrong, cant go with that condition in while loop
    // As we have to handle 3 different type of conditions after the while loop
    // First condition is true but second not.....like

    vector<int> spiralOrder2(vector<vector<int>> &matrix)
    {
        vector<int> result;
        if (matrix.empty())
            return result;

        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (top <= bottom && left <= right)
        {
            for (int j = left; j <= right; j++)
                result.push_back(matrix[top][j]);
            top++;

            for (int i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--;

            if (top <= bottom)
            {
                for (int j = right; j >= left; j--)
                    result.push_back(matrix[bottom][j]);
                bottom--;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++;
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> a = {{1, 2}, {3, 4}};
    Solution s;
    vector<int> result = s.spiralOrder(a);
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i];
        cout << endl;
    }
    return 0;
};