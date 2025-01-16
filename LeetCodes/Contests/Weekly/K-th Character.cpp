#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    char kthCharacter(int k)
    {
        string a = "a";
        for (; k > a.length();)
        {
            string b = "";
            for (size_t j = 0; j < a.length(); j++)
            {
                char temp = a[j] + 1;
                b.push_back(temp);
            }
            a.append(b);
        }
        if (k <= a.length())
            return a[k - 1];
        else
            return '\0';
    }
};

int main()
{
    // Your code goes here

    return 0;
}