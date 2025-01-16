#include <iostream>
#include <vector>

using namespace std;

// JUST LIKE THE CONTAINER WITH MOST WATER/ TRAPPED WATER CAN BE DONE THIS WAY TOO

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int size = numbers.size();
        int index_1 = 0;
        int index_2 = size - 1;
        vector<int> result;
        int sum;
        for (; numbers[index_1] + numbers[index_2] != target;)
        {
            sum = numbers[index_1] + numbers[index_2];
            if (target > sum)
            {
                index_1++;
            }
            else
            {
                index_2--;
            }
        }
        result.push_back(index_1 + 1);
        result.push_back(index_2 + 1);
        return result;
    }
};

int main()
{
    // Your code goes here

    return 0;
}