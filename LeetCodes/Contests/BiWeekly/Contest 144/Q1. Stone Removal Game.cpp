#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canAliceWin(int n)
    {
        if (n < 10)
        {
            return false;
        }

        bool ans = false;
        int a = 10;
        while (n > 0)
        {
            n -= a;
            a--;
            if (n < 0)
            {
                return ans;
            }
            ans = !ans;
        }
        return ans;
    }
};

int main()
{
    // Your code goes here

    return 0;
}