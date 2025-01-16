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
    void solve(TreeNode *root, int &total, int number)
    {
        if (!root)
        {
            return;
        }
        number = (number * 10) + root->val;
        if (!root->right && !root->left)
        {
            total = total + number;
        }
        solve(root->left, total, number);
        solve(root->right, total, number);
        return;
    }
    int sumNumbers(TreeNode *root)
    {
        int total = 0;
        if (!root)
        {
            return 0;
        }
        int number = 0;
        solve(root, total, number);
        return total;
    }
};

int main()
{
    TreeNode *a = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    return 0;
}