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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() >= 1 && inorder.size() >= 1)
        {
            TreeNode *root = new TreeNode(preorder[0]);
            int i = 0;
            int a = preorder[0];
            while (inorder[i] != a)
            {
                i++;
            }
            vector<int> sub_preorder1(preorder.begin() + 1, preorder.begin() + i + 1);
            vector<int> sub_inorder1(inorder.begin(), inorder.begin() + i);
            vector<int> sub_preorder2(preorder.begin() + i + 1, preorder.end());
            vector<int> sub_inorder2(inorder.begin() + i + 1, inorder.end());
            root->left = buildTree(sub_preorder1, sub_inorder1);
            root->right = buildTree(sub_preorder2, sub_inorder2);
            return root;
        }
        else
        {
            return NULL;
        }
    }
};

int main()
{
    // Your code goes here

    return 0;
}