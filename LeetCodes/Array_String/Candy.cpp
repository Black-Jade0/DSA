#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int min_chocolates = 1;
        int prev = 0;
        int size = ratings.size();
        vector<int> chocolates(size, 1);
        int total = 0;
        for (size_t i = 1; i < size; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                chocolates[i] = chocolates[i - 1] + 1;
            }
            else
            {
                if (chocolates[i - 1] == 1 && ratings[i - 1] > ratings[i])
                {
                    ++chocolates[i - 1];
                    for (size_t j = i - 1; j > 0; j--)
                    {
                        if (ratings[j - 1] > ratings[j] && chocolates[j - 1] > chocolates[j])
                        {
                            break;
                        }

                        else if (ratings[j - 1] < ratings[j] && chocolates[j - 1] < chocolates[j])
                        {
                            break;
                        }
                        else if (ratings[j - 1] > ratings[j] && chocolates[j - 1] <= chocolates[j])
                        {
                            ++chocolates[j - 1];
                        }
                    }
                }
                else
                {
                    continue;
                }
            }
        }
        for (size_t i = 0; i < chocolates.size(); i++)
        {
            total = total + chocolates[i];
        }
        return total;
    }
};

//ChatGpt
class Solution2
{
public:
    int candy2(vector<int> &ratings)
    {
        int size = ratings.size();
        if (size == 0)
            return 0;

        vector<int> chocolates(size, 1);

        for (int i = 1; i < size; ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                chocolates[i] = chocolates[i - 1] + 1;
            }
        }

        for (int i = size - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1])
            {
                chocolates[i] = max(chocolates[i], chocolates[i + 1] + 1);
            }
        }

        int total = 0;
        for (int i = 0; i < size; ++i)
        {
            total += chocolates[i];
        }

        return total;
    }
};

int main()
{

    return 0;
}