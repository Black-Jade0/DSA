#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // Helper function to compute maximum path sum
    int solve(TreeNode *root, int &result)
    {
        if (!root)
        {
            return 0;
        }

        // Recursively find the maximum path sum for left and right subtrees
        // We use max(0, ...) to discard any negative paths (because we don't want to add them to the result)
        int left = max(0, solve(root->left, result));
        int right = max(0, solve(root->right, result));

        // Calculate the current path sum including the root
        int currentPathSum = left + right + root->val;

        // Update the result if the current path sum is greater
        result = max(result, currentPathSum);

        // Return the maximum path sum including either the left or right subtree and the current node
        return root->val + max(left, right);
    }

    // Main function to find the maximum path sum in the binary tree
    int maxPathSum(TreeNode *root)
    {
        int result = INT_MIN; // Initialize result to a very small number
        solve(root, result);
        return result;
    }
};

int main()
{
    // Your code goes here

    return 0;
}