#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
    int binarytodecimal(string binary)
    {
        int decimal = 0;
        int n = binary.size();
        for (int i = 0; i < n; ++i)
        {
            decimal += pow(2, i);
        }
        return decimal;
    }
    int smallestNumber(int n)
    {
        int a = (log(n) / log(2)) / 1;
        a++;
        string s = "";
        for (int i = 0; i < a; i++)
        {
            s.push_back('1');
        }
        return binarytodecimal(s);
    }
};

int main()
{
    // Your code goes here

    return 0;
}