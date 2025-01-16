#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Recursive function to find the appropriate row
    int help1(vector<vector<int>> &matrix, int &target, int start, int end)
    {
        if (start > end)
        {
            return end; // Safely return the closest valid index
        }
        int a = (start + end) / 2;
        if (matrix[a][0] <= target && (a == matrix.size() - 1 || matrix[a + 1][0] > target))
        {
            return a; // Return current row if target could be here
        }
        else if (matrix[a][0] > target)
        {
            return help1(matrix, target, start, a - 1);
        }
        else
        {
            return help1(matrix, target, a + 1, end);
        }
    }

    // Recursive binary search within the row
    bool help2(vector<int> &arr, int &target, int start, int end)
    {
        if (start > end)
        {
            return false; // Base case for not found
        }
        int i = (start + end) / 2;
        if (arr[i] == target)
        {
            return true; // Target found
        }
        else if (arr[i] > target)
        {
            return help2(arr, target, start, i - 1);
        }
        else
        {
            return help2(arr, target, i + 1, end);
        }
    }

    // Main function to search the matrix
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return false; // Edge case for an empty matrix
        }

        if (matrix.size() == 1)
        {
            return help2(matrix[0], target, 0, matrix[0].size() - 1);
        }

        int a = help1(matrix, target, 0, matrix.size() - 1);
        if (a < 0 || a >= matrix.size())
        {
            return false; // Ensure the index is within bounds
        }

        return help2(matrix[a], target, 0, matrix[a].size() - 1);
    }
};

int main()
{
    // Your code goes here

    return 0;
}