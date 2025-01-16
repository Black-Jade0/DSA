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
    void help(vector<int> &nums, int start, int end, TreeNode **root)
    {
        if (start > end)
        {
            return;
        }
        int mid = (start + end) / 2;
        (*root) = new TreeNode(nums[mid]);
        help(nums, start, mid - 1, &((*root)->left));
        help(nums, mid + 1, end, &((*root)->right));
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode *root = nullptr;
        help(nums, 0, nums.size() - 1, &root);
        return root;
    }
};

int main()
{
    // Your code goes here

    return 0;
}