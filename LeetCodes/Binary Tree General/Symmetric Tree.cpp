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
    bool isSymmetric_help(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
        {
            return true;
        }
        if ((p && !q) || (!p && q) || p->val != q->val || !isSymmetric_help(p->left, q->right) || !isSymmetric_help(p->right, q->left))
        {
            return false;
        }
        return true;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        else if (isSymmetric_help(root->left, root->right))
        {
            return true;
        }
        return false;
    }
};

int main()
{
    // Your code goes here

    return 0;
}