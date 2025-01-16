#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<char> get_alpha(char i)
    {
        vector<char> alpha;
        int a = i - '0';

        if (a >= 2 && a <= 6)
        {
            char first = (a - 2) * 3 + 'a';
            alpha.push_back(first);
            alpha.push_back(++first);
            alpha.push_back(++first);
        }
        else if (a == 7)
        {
            char first = 'p';
            alpha.push_back(first);
            alpha.push_back(++first);
            alpha.push_back(++first);
            alpha.push_back(++first);
        }
        else if (a == 8)
        {
            char first = 't';
            alpha.push_back(first);
            alpha.push_back(++first);
            alpha.push_back(++first);
        }
        else if (a == 9)
        {
            char first = 'w';
            alpha.push_back(first);
            alpha.push_back(++first);
            alpha.push_back(++first);
            alpha.push_back(++first);
        }

        return alpha;
    }

    void helper(vector<string> &ans, vector<vector<char>> &graph, string s, int i)
    {
        if (i >= graph.size())
        {
            ans.push_back(s);
            return;
        }

        for (size_t j = 0; j < graph[i].size(); j++)
        {
            s.push_back(graph[i][j]);
            helper(ans, graph, s, i + 1);
            s.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return {};
        }
        
        vector<vector<char>> graph;
        for (size_t i = 0; i < digits.size(); i++)
        {
            vector<char> alpha = get_alpha(digits[i]);
            graph.push_back(alpha);
        }
        vector<string> ans;
        helper(ans, graph, "", 0);
        return ans;
    }
};

int main()
{
    // Your code goes here

    return 0;
}