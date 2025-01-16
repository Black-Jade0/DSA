#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int size = gas.size();
        int start_index = 0;  // Potential starting station
        int lowest_fuel = 0;  // Tracks the lowest fuel balance encountered
        int current_fuel = 0; // Current fuel balance

        for (int i = 0; i < size; i++)
        {
            current_fuel += gas[i] - cost[i];
            if (current_fuel < lowest_fuel)
            {
                lowest_fuel = current_fuel;
                start_index = i + 1; // Update the starting point to the next station
            }
        }

        if (current_fuel >= 0)
        {
            return start_index; // Valid starting index wrapped around
        }
        else
        {
            return -1; // No valid solution if total fuel is insufficient
        }
    }
};

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    Solution sol;
    int start = sol.canCompleteCircuit(gas, cost);
    cout << "Start at gas station: " << start << endl;

    return 0;
}
