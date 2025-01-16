#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        int plus = ((numRows - 2) * 2) + 2;
        int plus_help = plus;
        string result;
        for (size_t i = 0; i < numRows; i++)
        {
            int j = i;
            while (j < s.length())
            {
                if (plus == plus_help || plus_help == 0)
                {
                    result.push_back(s[j]);
                }
                else
                {
                    result.push_back(s[j]);
                    if (j + plus_help < s.length())
                    {
                        result.push_back(s[j + plus_help]);
                    }
                }
                j += plus;
            }
            plus_help -= 2;
        }
        return result;
    }
};

int main()
{
    Solution a;
    string b = a.convert("A", 1);
    cout << b;
    return 0;
}