#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
public:
    pair<Node *, pair<bool, bool>> help(vector<vector<int>> &grid, int left, int right, int top, int bottom)
    {
        if (left == right)
        {
            return {new Node(grid[top][left], true), {grid[top][left], true}};
        }
        pair<Node *, pair<bool, bool>> first = help(grid, left, ((left + right) / 2), top, (top + bottom) / 2);
        pair<Node *, pair<bool, bool>> second = help(grid, ((left + right) / 2) + 1, right, top, (top + bottom) / 2);
        pair<Node *, pair<bool, bool>> third = help(grid, left, ((left + right) / 2), (top + bottom) / 2 + 1, bottom);
        pair<Node *, pair<bool, bool>> fourth = help(grid, ((left + right) / 2) + 1, right, (top + bottom) / 2 + 1, bottom);
        if (first.second.second && second.second.second && third.second.second && fourth.second.second &&
            first.second.first == second.second.first && first.second.first == third.second.first &&
            first.second.first == fourth.second.first)
        {
            return {new Node(first.second.first, true), {first.second.first, true}};
        }
        Node *root = new Node(true, false, first.first, second.first, third.first, fourth.first);
        return {root, {true, false}};
    }
    Node *construct(vector<vector<int>> &grid)
    {
        Node *root = new Node();
        bool val;
        bool is_leaf;
        pair<Node *, pair<bool, bool>> ans = help(grid, 0, grid.size() - 1, 0, grid.size() - 1);
        root = ans.first;
        return root;
    }
};

int main()
{
    // Your code goes here

    return 0;
}