#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int maxLength = 0;
        unordered_set<char> charSet;
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            while (charSet.count(s[right])) // No need to check twice
            {
                charSet.erase(s[left]); // Slide the window by erasing from left
                left++;
            }
            charSet.insert(s[right]);                     // Insert current character
            maxLength = max(maxLength, right - left + 1); // Update maxLength
        }

        return maxLength;
    }
};

int main()
{
    Solution sol;
    string s = "abcabcbb";
    cout << "Length of the longest substring: " << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}
