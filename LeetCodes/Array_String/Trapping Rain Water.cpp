#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int size = height.size();
        int front = 0;
        int back = size - 1;
        int max1 = height[front];
        int max2 = height[back];
        int water = 0;
        while (back > front)
        {
            if (max1 >= max2)
            {
                --back;
                if (height[back] < max2)
                {
                    water += max2 - height[back];
                }
                else{
                    max2 = height[back];
                }
            }
            else
            {
                ++front;
                if (height[front] < max1)
                {
                    water += max1 - height[front];
                }
                else{
                    max1 = height[front];
                }
            }
        }
        return water;
    }
};

int main()
{
    // Your code goes here

    return 0;
}