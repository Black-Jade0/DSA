#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int a = m + n - 1;
        int p1 = m - 1;
        int p2 = n - 1;

        for (; a > 0; a--)
        {
            if (p2 < 0)
            {
                break;
            }
            if (p1 >= 0 && nums1[p1] > nums2[p2])
            {
                nums1[a] = nums1[p1];
                p1--;
            }
            else
            {
                nums1[a] = nums2[p2];
                p2--;
            }
        }
    }
};

int main()
{
    Solution m;
    vector<int> vec1(12);
    vector<int> vecCopy = {1, 3, 5, 7, 9};

    for (int i = 0; i < vecCopy.size(); i++)
    {
        vec1[i] = vecCopy[i];
    }

    vector<int> vec2 = {2, 3, 4, 5, 6, 7, 8};

    m.merge(vec1, 5, vec2, 7);
    cout << vec1.size();
    cout << endl;
    for (int i = 0; i < vec1.size(); i++)
    {
        cout << vec1[i] << " ";
    }

    return 0;
}
