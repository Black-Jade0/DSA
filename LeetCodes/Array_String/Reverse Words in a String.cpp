#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        bool a = true;
        string result;
        string temp_result;
        while (s[0] == ' ' && a)
        {
            s.erase(0, 1);
        }
        while (s[s.length() - 1] == ' ' && a)
        {
            s.erase(s.length() - 1, 1);
        }
        a = false;

        for (size_t i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
            {
                temp_result.push_back(s[i]);
            }
            else if (s[i - 1] != ' ')
            {
                temp_result.append(result.begin(), result.end());
                result.clear();
                result.push_back(' ');
                result.append(temp_result.begin(), temp_result.end());
                temp_result.clear();
            }
            continue;
        }
        temp_result.append(result.begin(), result.end());
        result.clear();
        result.push_back(' ');
        result.append(temp_result.begin(), temp_result.end());
        temp_result.clear();
        result.erase(0, 1);
        return result;
    }
};

int main()
{
    Solution a;
    string b = a.reverseWords("  jainam  is playing");
    cout << 0;
    cout << b;
    cout << 0;
    return 0;
}