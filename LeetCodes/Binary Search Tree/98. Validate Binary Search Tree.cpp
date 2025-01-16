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
    TreeNode *prev = NULL;
    bool isValidBST(TreeNode *root)
    {
        // static TreeNode *prev = NULL;
        if (root != NULL)
        {
            if (!isValidBST(root->left))
            {
                return false;
            }
            if (prev != NULL && root->val <= prev->val)
            {
                return false;
            }
            prev = root;

            return isValidBST(root->right);
        }
        else
        {
            return true;
        }
    }
};

//  KEEP IN MIND TO USE A CLASS MEMBER INSTEAD OF A STATIC VARIABLE, AS STATIC VARIABLE RETAINS ITS VALUE ACCROSS DIFFERENT INSTANCES OF CLASS
//  WHICH WE DONT WANT, WE JUST WANT IT TO RETAIN ITS VALUE ACROSS RECURSION (WHICH CAN BE DONE BY CLASS VARIABLE)

class Solution
{
public:
    TreeNode *prev = NULL; // `prev` is no longer static, as we don't want persistence across function calls

    bool isValidBST(TreeNode *root)
    {
        // Base case: if the node is null, it's valid
        if (root == NULL)
            return true;

        // Recursively check the left subtree
        if (!isValidBST(root->left))
            return false;

        // If the current node's value is less than or equal to the previous node's value, it's not a valid BST
        if (prev != NULL && root->val <= prev->val)
            return false;

        // Update prev to the current node
        prev = root;

        // Recursively check the right subtree
        return isValidBST(root->right);
    }
};

int main()
{
    // Your code goes here

    return 0;
}