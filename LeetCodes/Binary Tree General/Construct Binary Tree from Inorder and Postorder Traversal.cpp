#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
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
    void mapping(vector<int> inorder, unordered_map<int, int> &mp)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
    }

    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int &index, int orderStart, int orderEnd, int n, unordered_map<int, int> &mp)
    {
        if (index < 0 || orderStart > orderEnd)
        {
            return NULL;
        }

        int element = postorder[index--];
        TreeNode *root = new TreeNode(element);
        int pos = mp[element];

        root->right = solve(inorder, postorder, index, pos + 1, orderEnd, n, mp);
        root->left = solve(inorder, postorder, index, orderStart, pos - 1, n, mp);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> mp;
        mapping(inorder, mp);
        int n = inorder.size();
        int postOrderIndex = n - 1;
        return solve(inorder, postorder, postOrderIndex, 0, n - 1, n, mp);
    }
};

int main() {
    // Your code goes here

    return 0;
}