#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        vector<int> freq(n + 1, 0); 

        for (int i = 0; i < n; i++)
        {
            if (citations[i] >= n)
                freq[n]++; 
            else
                freq[citations[i]]++;
        }

        int total = 0;
       
        for (int i = n; i >= 0; i--)
        {
            total += freq[i]; 
            if (total >= i)
                return i;
        }

        return 0;
    }
};

int main()
{
    vector<int> citations = {1, 1, 1, 2, 3, 4, 4, 5, 5, 5, 5};
    Solution sol;
    int hindex = sol.hIndex(citations);
    cout << hindex << endl;

    return 0;
}
