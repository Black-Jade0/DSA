#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> stringSequence(string target)
    {
        vector<string> result;
        string help;
        for (size_t i = 0; i < target.size(); i++)
        {
            help.push_back('a');
            while (help[i] != target[i])
            {
                result.push_back(help);
                help[i]++;
            }
            result.push_back(help);
        }
        return result;
    }
};

int main()
{
    // Your code goes here

    return 0;
}