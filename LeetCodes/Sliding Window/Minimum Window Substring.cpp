#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> t_count;
        string result = "";
        if (s.empty() || t.empty() || s.length() < t.length())
        {
            cout << "lol";
            return result;
        }
        cout << "string t: ";
        for (size_t i = 0; i < t.size(); i++)
        {
            t_count[t[i]]++;
            cout << t[i];
        }
        cout << endl;
        for (int start = 0; start < s.size(); start++)
        {
            unordered_map<char, int> track;
            for (size_t t_char = start; t_char < s.size(); t_char++)
            {
                if (t_count.find(s[t_char]) != t_count.end())
                {
                    track[s[t_char]]++;
                    while (track[s[t_char]] > t_count[s[t_char]])
                    {
                        if (track.find(s[start]) != track.end() && track[s[start]] > 1)
                        {
                            start++;
                            track[s[start]]--;
                        }
                        else if (track.find(s[start]) == track.end())
                        {
                            start++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    bool all_done = true;
                    for (auto i = 0; i < t.size(); i++)
                    {
                        if (track[t[i]] < 1)
                        {
                            all_done = false;
                        }
                    }
                    if (all_done && (result.size() > t_char - start + 1 || result == ""))
                    {
                        result = s.substr(start, t_char - start + 1);
                        cout << "string s : ";
                        cout << s;
                        cout << endl;
                        cout << "result : ";
                        cout << result;
                    }
                }
            }
        }
        return result;
    }

    //SOMETHING WRONG WITH THE UPPER ONE (OFCOURSE MINE)
    //FROM LEETCODES SOL:

    std::string minWindow2(std::string s, std::string t)
    {
        if (s.empty() || t.empty() || s.length() < t.length())
        {
            return "";
        }

        std::vector<int> map(128, 0);
        int count = t.length();
        int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;
        for (char c : t)
        {
            map[c]++;
        }
        //INITIALISING ALL THE CHARS IN t TO 1

        while (end < s.length())
        {
            if (map[s[end]] > 0)
            {
                count--;
            }
            map[s[end]]--;
            end++;

            //Repeating untill the count is zero : 
            //meaning all the chars in t are now present
            //Therefore if count == 0, then all elements are present in the substring
            //Notice that the values of all the chars in t will be 0 in map
            //Rest all the chars value will go into negative and will never be > 0

            while (count == 0)
            {
                if (end - start < minLen)
                {
                    //updating the minLen it the previous substring length is bigger
                    startIndex = start;
                    minLen = end - start;
                }

                if (map[s[start]] == 0)
                {
                    count++;
                }
                map[s[start]]++;
                //value of any other char(not in t) will never be > 0
                start++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};

int main()
{
    Solution a;
    string b = "aa";
    string c = "aa";
    string result = a.minWindow(c, b);
    for (size_t start = 0; start < result.length(); start++)
    {
        cout << result[start];
        cout << endl;
    }
    return 0;
}