#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> result;
        int result_index = 0;
        int words_done = 0;
        int left_space = 0;
        for (size_t i = 0; i < words.size();)
        {
            int booked = 0;
            result.push_back("");
            for (; booked < maxWidth && i < words.size(); i++)
            {
                int words_size = words[i].size();
                if (booked == 0)
                {
                    booked = words_size;
                }
                else if (booked + words[i].length() + 1 <= maxWidth)
                {
                    booked += words_size + 1;
                }
                else
                {
                    break;
                }
            }
            left_space = maxWidth - booked;
            int numWordsInLine = i - words_done;
            int a = left_space % (numWordsInLine == 1 ? 1 : numWordsInLine - 1);
            for (; words_done < i; words_done++)
            {
                if (result[result_index].length() == 0)
                {
                    result[result_index].append(words[words_done]);
                    if (numWordsInLine == 1)
                    {
                        result[result_index].append(string(maxWidth - result[result_index].length(), ' '));
                    }
                }
                else
                {
                    for (size_t j = 0; j < left_space / (numWordsInLine == 1 ? 1 : numWordsInLine - 1); j++)
                    {
                        result[result_index].push_back(' ');
                    }
                    if (a > 0)
                    {
                        result[result_index].push_back(' ');
                        a--;
                    }
                    result[result_index].push_back(' ');
                    result[result_index].append(words[words_done]);
                }
            }
            result_index++;
        }
        string &lastLine = result.back();
        for (size_t i = 1; i < lastLine.length(); i++)
        {
            if (lastLine[i] == ' ' && lastLine[i - 1] == ' ')
            {
                lastLine.erase(i, 1);
                i--;
            }
        }
        if (lastLine.length() < maxWidth)
        {
            lastLine.append(string(maxWidth - lastLine.length(), ' '));
        }

        return result;
    }
};

int main()
{
    Solution a;
    vector<string> b = {"What", "must", "be", "acknowledgment", "shall", "be"};
    vector<string> result = a.fullJustify(b, 16);
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << 0 << endl;
    }

    return 0;
}