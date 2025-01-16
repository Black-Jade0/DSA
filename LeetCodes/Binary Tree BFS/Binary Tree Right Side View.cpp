#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        if (!root)
        {
            return result;
        }
        queue<TreeNode *> que;
        que.push(root);
        vector<vector<int>> help;
        int index = 0;
        while (!que.empty())
        {
            int size = que.size();
            help.push_back({});
            for (size_t i = 0; i < size; i++)
            {
                TreeNode *temp = que.front();
                que.pop();
                help[index].push_back(temp->val);
                if (temp->left)
                {
                    que.push(temp->left);
                }
                if (temp->right)
                {
                    que.push(temp->right);
                }
            }
            index++;
        }
        for (size_t i = 0; i < help.size(); i++)
        {
            result.push_back(help[i][help[i].size() - 1]);
        }
        return result;
    }
};

int main()
{

    return 0;
}