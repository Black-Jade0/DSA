#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// class Solution
// {
// public:
    // static const int MOD = 1e9 + 7;
    // void calculate_length(int t, int &ans)
    // {
    //     if (t > 24)
    //     {
    //         ans++;
    //         calculate_length(t - 25, ans);
    //     }
    //     if (t > 25)
    //     {
    //         ans++;
    //         calculate_length(t - 26, ans);
    //     }
    //     return;
    // }
    // int lengthAfterTransformations(string s, int t)
    // {
    //     int result = 0;
    //     for (size_t i = 0; i < s.size(); i++)
    //     {
    //         int a = s[i] - 'a' + 1;
    //         int ans = 1;
    //         if (a + t > 26)
    //         {
    //             calculate_length(t - 26 + a - 1, ++ans);
    //         }
    //         result = result + ans;
    //     }
    //     return result % MOD;
    // }

    //  502 / 824 testcases passed
    //  ITS CORRECT I THINK, GIVING TLE AFTER THIS
    //  THE CURRENT SOLUTION :
    //  GIVES TLE ON THE LAST CASE.......LOL 
// };

class Solution
{
public:
    int lengthAfterTransformations(std::string s, int t)
    {
        std::unordered_map<std::string, int> cache;
        return helper(s, t, cache) % (1000000007);
    }

private:
    int helper(const std::string &s, int t, std::unordered_map<std::string, int> &cache)
    {
        std::string key = std::to_string(t) + ":" + s;
        if (cache.find(key) != cache.end())
        {
            return cache[key];
        }

        int ans = 0;
        for (char c : s)
        {
            if (c + t <= 'z')
            {
                ans += 1;
            }
            else
            {
                int new_t = t - ('z' + 1 - c);
                ans += helper("ab", new_t, cache);
                ans %= 1000000007;
            }
        }

        cache[key] = ans % 1000000007;
        return ans;
    }
};

int main()
{
    Solution a;
    int ans = a.lengthAfterTransformations("jqktcurgdvlibczdsvnsg", 7517);
    cout << ans;
    return 0;
}