#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<int> result;
    void help(Node *root)
    {
        for (int i = 0; i < root->children.size(); i++)
        {
            help(root->children[i]);
        }
        result.push_back(root->val);
    }

    vector<int> postorder(Node *root)
    {
        if (!root)
        {
            return {};
        }
        help(root);
        return result;
    }
};

int main()
{
    // Your code goes here

    return 0;
}