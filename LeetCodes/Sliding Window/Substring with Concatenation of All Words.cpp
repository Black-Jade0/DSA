#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> result;
        int left = 0;
        bool track_first = false;
        bool first_tracked = false;
        vector<bool> words_bool(words.size(), false);

        for (size_t right = 0; right < s.length();)
        {
            int words_iterator = 0;
            while (!track_first && words_iterator < words.size())
            {
                if (words[words_iterator][0] == s[right] && !words_bool[words_iterator])
                {
                    track_first = true;
                    if (!first_tracked)
                    {
                        left = right;
                        first_tracked = true;
                    }
                }
                words_iterator++;
            }
            if (!track_first)
            {
                right = left + 1;
                first_tracked = false;
                for (size_t i = 0; i < words_bool.size(); i++)
                {
                    words_bool[i] = false;
                }
            }
            while (track_first && words_iterator > 0 && !words_bool[words_iterator - 1])
            {
                words_iterator--;
                int a = 0;
                for (; a < words[words_iterator].length() && right < s.length();)
                {
                    if (s[right] == words[words_iterator][a])
                    {
                        a++;
                        right++;
                    }
                    else
                    {
                        first_tracked = false;
                        left = right;
                        for (size_t i = 0; i < words_bool.size(); i++)
                        {
                            words_bool[i] = false;
                        }
                        track_first = false;
                        break;
                    }
                }
                if (a == words[words_iterator].length())
                {
                    words_bool[words_iterator] = true;
                    track_first = false;
                }
            }
            int words_bool_all_true = true;
            for (size_t i = 0; i < words_bool.size(); i++)
            {
                if (!words_bool[i])
                {
                    words_bool_all_true = false;
                }
            }
            if (words_bool_all_true)
            {
                right = left + 1;
                first_tracked = false;
                result.push_back(left);
                track_first = false;
                fill(words_bool.begin(), words_bool.end(), false);
            }
        }
        return result;
    }

    //USED A POINT: ALL THE ELEMENTS IN WORDS VECTOR ARE OF SAME LENGTH
    //UNORDERED_MAP

    vector<int> findSubstring2(string s, vector<string> &words)
    {
        unordered_map<string, int> words_count;
        for (int i = 0; i < words.size(); i++)
            words_count[words[i]]++;

        int n = s.length();
        int wordsize = words.size();
        int len = words[0].size();
        vector<int> ans;
        for (int i = 0; i < len; i++)
        {
            int start = i, count = 0;
            unordered_map<string, int> mp;
            for (int j = i; j <= n - len; j += len)
            {
                string word = s.substr(j, len);
                if (words_count.find(word) != words_count.end())
                {
                    mp[word]++;
                    count++;

                    while (mp[word] > words_count[word])
                    {
                        string leftword = s.substr(start, len);
                        mp[leftword]--;
                        count--;
                        start += len;
                    }
                    if (count == wordsize)
                        ans.push_back(start);
                }
                else
                {
                    mp.clear();
                    count = 0;
                    start = j + len;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<string> b = {"foo", "bar"};
    string c = "barfoothefoobarman";
    vector<int> result = a.findSubstring(c, b);
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i];
        cout << endl;
    }

    return 0;
}