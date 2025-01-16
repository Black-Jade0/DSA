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
    bool solve(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&ans)
    {
        if (!root)
        {
            return false;
        }

        // Check if current node is p or q
        bool foundAtCurrent = (root == p) || (root == q);

        // Recurse into left and right subtrees
        bool left = solve(root->left, p, q, ans);
        bool right = solve(root->right, p, q, ans);

        // If current node is the LCA, i.e., both nodes found in left and right subtree,
        // or one in a subtree and the other is the current node
        if ((left && right) || (foundAtCurrent && (left || right)))
        {
            ans = root;
        }

        // Return true if p or q found in this subtree
        return foundAtCurrent || left || right;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ans = NULL;
        solve(root, p, q, ans);
        return ans;
    }

    TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return root;
        }
        if (root == p || root == q)
        {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root;
        return left ? left : right;
    }
};

int main()
{
    // Your code goes here

    return 0;
}