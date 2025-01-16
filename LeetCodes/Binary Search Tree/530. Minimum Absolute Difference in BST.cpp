#include <iostream>
#include <vector>

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
    // int solve(TreeNode *root, int ans)
    // {
    //     if (!root)
    //     {
    //         return ans;
    //     }
    //     int left = INT_MAX;
    //     if (root->left)
    //     {
    //         left = solve(root->left, root->val - root->left->val);
    //     }
    //     int right = INT_MAX;
    //     if (root->right)
    //     {
    //         right = solve(root->right, root->right->val - root->val);
    //     }
    //     return min(ans, left, right);
    // }
    // int getMinimumDifference(TreeNode *root)
    // {
    //     int ans = INT_MAX;
    //     if (!root)
    //     {
    //         return 0;
    //     }
    //     ans = solve(root, ans);
    //     return ans;
    // }
    

    // int solve(TreeNode *root, int ans)
    // {
    //     if (!root)
    //     {
    //         return ans;
    //     }

    //     // Recurse into the left and right subtrees
    //     ans = min(solve(root->left, ans), solve(root->right, ans));

    //     // Calculate the difference between current node and its left and right children if they exist
    //     if (root->left)
    //     {
    //         ans = min(ans, root->val - root->left->val);
    //     }
    //     if (root->right)
    //     {
    //         ans = min(ans, root->right->val - root->val);
    //     }

    //     return ans;
    // }

    // int getMinimumDifference(TreeNode *root)
    // {
    //     int ans = INT_MAX;
    //     if (!root)
    //     {
    //         return 0;
    //     }
    //     ans = solve(root, ans); // Start the recursive solution
    //     return ans;
    // }

    //  UPPER BOTH ARE CORRECT, BUT U NEED NOT TO FIND THE MINIMUM DIFFERENCE BETWEEN PARENT AND CHILD NODE, BUT ANY TWO NODES
    //  AND HERE ITS TALKING ABOUT THE PREORDER TRAVERSAL (DIFFERENCE BETWEEN ANY TWO ADJASCENT NUMBER) :

    int prevVal = -1;  // To store the value of the previous node in in-order traversal
    int ans = INT_MAX; // To store the minimum difference

    void solve(TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        // Traverse the left subtree
        solve(root->left);

        // Compute the difference with the previous node if it exists
        if (prevVal != -1)
        {
            ans = min(ans, root->val - prevVal);
        }

        // Update prevVal to the current node's value
        prevVal = root->val;

        // Traverse the right subtree
        solve(root->right);
    }

    int getMinimumDifference(TreeNode *root)
    {
        // Start the in-order traversal to find the minimum difference
        solve(root);
        return ans;
    }
};

int main()
{
    // Your code goes here

    return 0;
}