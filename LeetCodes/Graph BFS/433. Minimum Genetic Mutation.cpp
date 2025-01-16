#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution
{
public:
    bool proceed(string a, string b)
    {
        int k = 0;
        for (size_t i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
            {
                if (k == 1)
                {
                    return false;
                }
                k = 1;
            }
        }
        return true;
    }
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        set<string> track;
        queue<pair<string, int>> que;
        que.push({startGene, 0});
        track.insert(startGene);
        while (!que.empty())
        {
            auto temp = que.front();
            que.pop();
            for (size_t i = 0; i < bank.size(); i++)
            {
                if (track.find(bank[i]) != track.end() || !proceed(bank[i], temp.first))
                {
                    continue;
                }
                if (bank[i] == endGene)
                {
                    return temp.second + 2;
                }
                track.insert(bank[i]);
                que.push({bank[i], temp.second + 1});
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