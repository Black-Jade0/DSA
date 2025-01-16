#include <iostream>
#include <vector>
#include <vector>

using namespace std;

class Solution
{
public:
    int countOfSubstrings(string word, int k)
    {
        int length = word.length();
        int count = 0;
        struct BoolObject
        {
            bool a;
            bool e;
            bool i;
            bool o;
            bool u;
        };
        BoolObject BoolObj = {false, false, false, false, false};

        for (size_t i = 0; i < length; i++)
        {
            char letter = word[i];
            int constant = 0;
            if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
            {
                if (letter == 'a')
                {
                    BoolObj.a = true;
                }
                else if (letter == 'e')
                {
                    BoolObj.e = true;
                }
                else if (letter == 'i')
                {
                    BoolObj.i = true;
                }
                else if (letter == 'o')
                {
                    BoolObj.o = true;
                }
                else if (letter == 'u')
                {
                    BoolObj.u = true;
                }
                if (BoolObj.a && BoolObj.e && BoolObj.i && BoolObj.o && BoolObj.u)
                {
                }
            }
            else
            {
                if (constant < k)
                {
                    constant++;
                }
                else
                {
                    
                }
                
            }
        }
    }
};

int main()
{
    // Your code goes here

    return 0;
}