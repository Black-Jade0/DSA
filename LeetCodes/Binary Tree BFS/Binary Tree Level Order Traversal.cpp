#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>>ans;
    void DFS(TreeNode*root,int h){
        if(root==nullptr) return;
        if(h>=ans.size()) ans.emplace_back();
        ans[h].push_back(root->val);
        DFS(root->left,h+1);
        DFS(root->right,h+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        DFS(root,0);
        return ans;
    }
};

int main() {
    // Your code goes here

    return 0;
}