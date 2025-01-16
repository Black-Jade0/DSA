#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = 0;
        int sell = 1;
        int size = prices.size();
        int profit = 0;
        for (; sell < size; sell++)
        {
            int buy_val = prices[buy];
            int sell_val = prices[sell];
            if (buy_val < sell_val)
            {
                profit = sell_val - buy_val;
            }
            buy++;
        }
        return profit;
    }
};

int main()
{
    // Your code goes here

    return 0;
}