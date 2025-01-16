#include <iostream>
#include <vector>
#include <unordered_map>

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
    string solve(TreeNode *root, unordered_map<string, int> &mp, vector<TreeNode *> &ans)
    {
        //  MAKE A STRING OF ALL THE VALUES OF THE SUBTREE WITH HEAD ROOT = ROOT
        //  ADD IT TO THE MAP AND CHECKS IF THE INT VALUE IS 2, THAT MEANS THERE IS ANOTHER DUPLICATE SUBTREE
        //  YUP TIMECOMPLEXITY O(N^2)
        
        if (!root)
            return "";

        string str = to_string(root->val) + "," + solve(root->left, mp, ans) + "," + solve(root->right, mp, ans);
        mp[str]++;

        if (mp[str] == 2)
            ans.push_back(root);

        return str;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {

        unordered_map<string, int> mp;
        vector<TreeNode *> ans;
        solve(root, mp, ans);
        return ans;
    }
};

int main()
{
    // Your code goes here

    return 0;
}