#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        int n[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string s[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result;
        int i = 0;

        while (num > 0)
        {
            if (num >= n[i])
            {
                result += s[i];
                num -= n[i];
            }
            else
            {
                i++;
            }
        }

        return result;
    }
};

class Solution2
{
public:
    string intToRoman2(int num)
    {
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hrns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string ths[] = {"", "M", "MM", "MMM"};

        return ths[num / 1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
    }
};

int main()
{
    // Your code goes here

    return 0;
}