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
    int ans = 0;
    void help(TreeNode *root, int &k)
    {
        if (!root)
        {
            return;
        }
        help(root->left, k);
        k--;
        if (k == 1)
        {
            ans = root->val;
            return;
        }
        help(root->right, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        help(root, k);
        return ans;
    }
};

int main()
{
    // Your code goes here

    return 0;
}