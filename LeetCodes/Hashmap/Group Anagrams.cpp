#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        if (strs.size() == 1)
        {
            vector<string> result_string;
            result_string.push_back(strs[0]);
            result.push_back(result_string);
            return result;
        }
        vector<unordered_map<char, int>> track_words;
        for (size_t i = 0; i < strs.size(); i++)
        {
            string strs_string = strs[i];
            bool found = false;
            int found_index = 0;
            for (size_t j = 0; j < track_words.size(); j++)
            {
                unordered_map<char, int> temp_track = track_words[j];
                int count_string = strs_string.size();
                for (size_t k = 0; k < strs_string.size(); k++)
                {
                    if (temp_track[strs_string[k]] > 0)
                    {
                        temp_track[strs_string[k]]--;
                        if (temp_track[strs_string[k]] == 0)
                        {
                            temp_track.erase(strs_string[k]);
                        }
                        count_string--;
                    }
                    else
                    {
                        break;
                    }
                }
                if (count_string == 0 && temp_track.size() == 0)
                {
                    found = true;
                    found_index = j;
                }
            }
            if (found)
            {
                result[found_index].push_back(strs[i]);
            }
            else
            {
                vector<string> result_string_array = {strs[i]};
                result.push_back(result_string_array);
                unordered_map<char, int> track_words_map;
                for (size_t j = 0; j < strs[i].size(); j++)
                {
                    track_words_map[strs[i][j]]++;
                }
                track_words.push_back(track_words_map);
            }
        }
        return result;
    }

    // Its correct, but TLE, use a sorted string as a key in hashmap
    // Lowers the time complexity

    vector<vector<string>> groupAnagrams2(vector<string> &strs)
    {
        unordered_map<string, vector<string>> anagram_map;
        vector<vector<string>> result;

        // Traverse through all words in strs
        for (const string &word : strs)
        {
            string sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end()); // Sort the word to get the key

            // Group the original word by the sorted key
            anagram_map[sorted_word].push_back(word);
        }

        // Collect all the grouped anagrams into the result vector
        for (auto &entry : anagram_map)
        {
            result.push_back(entry.second);
        }

        return result;
    }
};

int main()
{
    Solution a;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = a.groupAnagrams(strs);
    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}