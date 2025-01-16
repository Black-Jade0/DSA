#include <iostream>
#include <vector>
#include <queue>
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
    void helper(TreeNode *root, vector<vector<int>> &ans, int level)
    {
        if (root == nullptr)
            return;
        if (level == ans.size())
            ans.push_back({});
        ans[level].push_back(root->val);
        helper(root->left, ans, level + 1);
        helper(root->right, ans, level + 1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans = {};
        helper(root, ans, 0);
        for (int i = 1; i < ans.size(); i += 2)
        {
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }

    vector<vector<int>> zigzagLevelOrder2(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> ans;
        if (!root)
        {
            return ans;
        }
        q.push(root);
        int alt = 1;
        while (!q.empty())
        {
            vector<int> v;
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                TreeNode *temp = q.front();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
                v.push_back(temp->val);
                q.pop();
            }
            if (alt == -1)
            {
                reverse(v.begin(), v.end());
            }
            alt = alt * -1;
            ans.push_back(v);
        }
        return ans;
    }
};

int main()
{
    // Your code goes here

    return 0;
}