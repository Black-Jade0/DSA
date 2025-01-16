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
    void flatten(TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        // If the left subtree exists
        if (root->left)
        {
            // Store the original right subtree
            TreeNode *temp = root->right;

            // Move the left subtree to the right
            root->right = root->left;
            root->left = NULL; // Clear the left subtree

            // Recursively flatten the new right subtree (which was the left subtree)
            flatten(root->right);

            // Find the rightmost node of this newly flattened subtree
            TreeNode *rightMost = root;
            while (rightMost->right)
            {
                rightMost = rightMost->right;
            }

            // Attach the original right subtree
            rightMost->right = temp;
        }

        // Flatten the right subtree
        flatten(root->right);
    }
};

int main()
{
    // Your code goes here

    return 0;
}