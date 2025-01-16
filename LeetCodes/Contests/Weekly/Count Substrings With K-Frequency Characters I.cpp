#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s, int k)
    {
        if (s.size() == 0 || k == 0)
            return 0;
        int n = s.size();
        if (k == 1)
        {
            return ((n * (n + 1)) / 2); // all substrings are valid, total number of substrings = n*(n+1)/2
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            map<char, int> mpp;
            for (int j = i; j < n; j++)
            {
                mpp[s[j]]++;
                bool isValid = false;
                for (auto &[charKey, freq] : mpp)
                {
                    if (freq >= k)
                    {
                        isValid = true;
                        break;
                    }
                }
                if (isValid)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main() {
    // Your code goes here

    return 0;
}