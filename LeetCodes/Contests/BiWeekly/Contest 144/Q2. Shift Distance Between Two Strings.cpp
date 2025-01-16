#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long shiftDistance(string s, string t, vector<int> &nextCost, vector<int> &previousCost)
    {
        long long totalCost = 0;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            int startChar = s[i] - 'a';
            int targetChar = t[i] - 'a';

            int forwardSteps = (targetChar - startChar + 26) % 26;
            long long forwardCost = 0;
            for (int j = 0; j < forwardSteps; j++)
            {
                forwardCost += nextCost[(startChar + j) % 26];
            }

            int backwardSteps = (startChar - targetChar + 26) % 26;
            long long backwardCost = 0;
            for (int j = 0; j < backwardSteps; j++)
            {
                backwardCost += previousCost[(startChar - j + 26) % 26];
            }

            totalCost += min(forwardCost, backwardCost);
        }

        return totalCost;
    }
};

int main() {
    // Your code goes here

    return 0;
}