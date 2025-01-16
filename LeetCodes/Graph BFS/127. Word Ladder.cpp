#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_set>
#include <map>

using namespace std;

class Solution
{
public:
    bool proceed(string a, string b)
    {
        int diffCount = 0;
        for (size_t i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
            {
                if (diffCount == 1)
                    return false;
                diffCount = 1;
            }
        }
        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end())
        {
            return 0;
        }

        queue<pair<string, int>> que;
        que.push({beginWord, 1});
        while (!que.empty())
        {
            auto [currentWord, steps] = que.front();
            que.pop();

            vector<string> toErase;

            for (const auto &word : wordSet)
            {
                if (proceed(currentWord, word))
                {
                    if (word == endWord)
                    {
                        return steps + 1;
                    }
                    que.push({word, steps + 1});
                    toErase.push_back(word);
                }
            }

            for (const auto &word : toErase)
            {
                wordSet.erase(word);
            }
        }
        return 0;
    }
};

//  CODE IS CORRECT BUT TIME COMPLEXITY IS HIGH FOR THIS CODE (BEATS 18%)
//  NEW APPROACH, ONLY A LITTLE DIFFERENCE OF COMPARING THE WORDS (PROCEED FUNCTION)
//  WE CHANGE EVERY ALPHABET OF THE WORD AND CHECK IF THE NEW WORD EXIST IN THE SET
//  IF IT DOES WE PROCEED TO PUSH IT IN THE QUEUE (IF NOT ALREAYD DONE)

//  TIME COMPLEXITY FOR THE UPPER ONE IS (N*N*L) (N = NUMBER OF WORDS IN WORDlIST & L = LENGTH OF EVERY WORD)
//  FOR THE LOWER ONE IS (N*L*26)

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        map<string, int> mpp;
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (word == endWord)
                return steps;
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};

int main()
{
    // Your code goes here

    return 0;
}