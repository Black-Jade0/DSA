#include <iostream>
#include <vector>
#include <set>

using namespace std;

// class Solution
// {
// public:
//     vector<int> help1 = {2, -1, 2, 1, -2, -1, -2, 1, 2};
//     void helper(int &n, int &result, set<int> &row_track, set<int> &col_track, set<int> &cross_track1, set<int> &cross_track2, int i, int j, int count)
//     {
//         if (count < 0 || i < 0 || i >= n || j < 0 || j >= n || row_track.find(i) != row_track.end() || col_track.find(j) != col_track.end() || cross_track1.find(j - i) != cross_track1.end() || cross_track2.find(j + i) != cross_track2.end())
//         {
//             return;
//         }
//         count--;
//         if (count == 0)
//         {
//             result++;
//             return;
//         }
//         row_track.insert(i);
//         col_track.insert(j);
//         cross_track1.insert(j - i);
//         cross_track2.insert(j + i);
//         for (int k = 0; k < 8; k++)
//         {
//             helper(n, result, row_track, col_track, cross_track1, cross_track2, i + help1[k], j + help1[k + 1], count);
//         }
//         row_track.erase(i);
//         col_track.erase(j);
//         cross_track1.erase(j - i);
//         cross_track2.erase(j + i);
//         return;
//     }
//     int totalNQueens(int n)
//     {
//         int result = 0;
//         if (n == 1)
//         {
//             return 1;
//         }

//         set<int> row_track;
//         set<int> col_track;
//         set<int> cross_track2;
//         set<int> cross_track1;
//         for (int i = 0; i < n; i++)
//         {
//             helper(n, result, row_track, col_track, cross_track1, cross_track2, i, 0, n);
//         }
//         return result/2;
//     }
// };

//  THE PROBLEM IS THAT WITH THIS METHOD IT CANNOT BE BACKTRACKED CORRECTLY, U COMPLETED A SOLUTION AND THEN BACKTRACKED
//  AND GOT TO ANOTHER NODE, AND THEN U MAKE THE AGAIN SAME ROUND THAT U HAVE ALREADY COUNTED, IN SOME CASES U CAN MAKE THE ROUND FROM DIFFERENT NODES
//  WHILE IN SOME U CANT, SO U CANT HELP IT

class Solution
{
public:
    void helper(int n, int &result, set<int> &col_track, set<int> &cross_track1, set<int> &cross_track2, int row)
    {
        // If we've placed queens in all rows
        if (row == n)
        {
            result++;
            return;
        }

        for (int col = 0; col < n; col++)
        {
            // Check if placing a queen here would cause a conflict
            if (col_track.find(col) != col_track.end() || cross_track1.find(row - col) != cross_track1.end() || cross_track2.find(row + col) != cross_track2.end())
            {
                continue;
            }

            // Place queen and add tracking information
            col_track.insert(col);
            cross_track1.insert(row - col);
            cross_track2.insert(row + col);

            // Recurse to place queens in the next row
            helper(n, result, col_track, cross_track1, cross_track2, row + 1);

            // Backtrack by removing the queen
            col_track.erase(col);
            cross_track1.erase(row - col);
            cross_track2.erase(row + col);
        }
    }

    int totalNQueens(int n)
    {
        int result = 0;
        set<int> col_track;    // Tracks used columns
        set<int> cross_track1; // Tracks major diagonals
        set<int> cross_track2; // Tracks minor diagonals
        helper(n, result, col_track, cross_track1, cross_track2, 0);
        return result;
    }
};

int main()
{
    // Your code goes here

    return 0;
}