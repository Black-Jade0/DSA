#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

// class Solution
// {
// public:
//     unordered_map<string, vector<pair<string, float>>> connections;
//     set<string> present;
//     void calculate(string begin, string &find, double &ans, set<string> &seen, bool &found)
//     {
//         if (found || seen.find(begin) != seen.end())
//         {
//             return;
//         }
//         vector<pair<string, float>> to_visit = connections[begin];
//         seen.insert(begin);
//         for (size_t i = 0; i < to_visit.size(); i++)
//         {
//             if (to_visit[i].first == find)
//             {
//                 ans = ans * to_visit[i].second;
//                 found = true;
//                 return;
//             }
//         }
//         for (size_t i = 0; i < to_visit.size(); i++)
//         {
//             ans = ans * to_visit[i].second;
//             calculate(to_visit[i].first, find, ans, seen, found);
//             if (!found)
//             {
//                 ans = ans / to_visit[i].second;
//             }
//         }
//     }
//     vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
//     {
//         vector<double> result;
//         for (size_t i = 0; i < equations.size(); i++)
//         {
//             string num = equations[i][0], den = equations[i][1];
//             connections[num].push_back({den, values[i]});
//             connections[den].push_back({num, 1 / values[i]});
//             present.insert(num);
//             present.insert(den);
//         }

//         for (size_t i = 0; i < queries.size(); i++)
//         {
//             vector<string> query = queries[i];
//             double ans = 1;
//             if (query[0] == query[1] && present.find(query[0]) != present.end())
//             {
//                 result.push_back(1.0);
//                 continue;
//             }

//             if (present.find(query[0]) == present.end() || present.find(query[1]) == present.end())
//             {
//                 result.push_back(-1.0);
//                 continue;
//             }
//             set<string> seen;
//             bool found = false;
//             calculate(query[0], query[1], ans, seen, found);
//             if (found)
//             {
//                 result.push_back(ans);
//             }
//             else
//             {
//                 result.push_back(-1.0);
//             }
//         }
//         return result;
//     }
// };


//  ITS CORRECT, BUT U ARENT HANDELING THE ANS PROPERLY, U ARE MULTIPLYING IT EARLY AND THEN DEVIDINN IF THE ROUTE IS NOT FOUND THERE
//  DURE TO THIS, FLOATING-POINT PRECISION OCCURS


class Solution
{
public:
    unordered_map<string, vector<pair<string, float>>> connections;
    set<string> present;

    bool calculate(string begin, string &find, double &ans, set<string> &seen)
    {
        if (seen.find(begin) != seen.end())
        {
            return false;
        }
        if (begin == find)
        {
            return true;
        }

        seen.insert(begin);
        for (auto &neighbor : connections[begin])
        {
            double value = neighbor.second;
            if (calculate(neighbor.first, find, ans, seen))
            {                 // changed the condition to return directly
                ans *= value; // Multiply only when valid path is found
                return true;
            }
        }
        return false;
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        vector<double> result;

        for (size_t i = 0; i < equations.size(); i++)
        {
            string num = equations[i][0], den = equations[i][1];
            connections[num].push_back({den, values[i]});
            connections[den].push_back({num, 1 / values[i]});
            present.insert(num);
            present.insert(den);
        }

        for (size_t i = 0; i < queries.size(); i++)
        {
            string numerator = queries[i][0], denominator = queries[i][1];
            double ans = 1.0;

            if (numerator == denominator && present.find(numerator) != present.end())
            {
                result.push_back(1.0);
            }
            else if (present.find(numerator) == present.end() || present.find(denominator) == present.end())
            {
                result.push_back(-1.0);
            }
            else
            {
                set<string> seen;
                if (calculate(numerator, denominator, ans, seen))
                {
                    result.push_back(ans);
                }
                else
                {
                    result.push_back(-1.0);
                }
            }
        }

        return result;
    }
};

int main()
{
    // Your code goes here

    return 0;
}