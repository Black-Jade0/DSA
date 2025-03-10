#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *dfs(Node *cur, unordered_map<Node *, Node *> &mp)
    {
        vector<Node *> neighbour;
        Node *clone = new Node(cur->val);
        mp[cur] = clone;
        for (auto it : cur->neighbors)
        {
            if (mp.find(it) == mp.end())
            {
                neighbour.push_back(dfs(it, mp));
            }
            else
                neighbour.push_back(mp[it]);
        }
        clone->neighbors = neighbour;
        return clone;
    }
    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> mp;
        if (node == NULL)
            return NULL;
        if (node->neighbors.size() == 0) // if only one node present no neighbors
        {
            Node *clone = new Node(node->val);
            return clone;
        }
        return dfs(node, mp);
    }
};

int main()
{
    // Your code goes here

    return 0;
}