#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n; // Ensure k is within the range [0, n)

        // Reverse the entire array
        reverse(nums.begin(), nums.end());

        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Reverse the rest of the elements after k
        reverse(nums.begin() + k, nums.end());
    }
};

int main()
{
    // Your code goes here
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Solution object;
    object.rotate(arr, 4);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}