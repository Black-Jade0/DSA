#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> result;

    void help(int open, int close, string &way_result)
    {
        if (open == 0 && close == 0)
        {
            result.push_back(way_result);
            return;
        }

        if (open > 0)
        {
            way_result.push_back('(');
            help(open - 1, close, way_result);
            way_result.pop_back();
        }

        if (close > open)
        {
            way_result.push_back(')');
            help(open, close - 1, way_result);
            way_result.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n)
    {
        string way_result;
        help(n, n, way_result);
        return result;
    }
};

int main()
{
    // Your code goes here

    return 0;
}