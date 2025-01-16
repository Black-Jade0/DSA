#include <iostream>
#include <vector>

using namespace std;

int maxArea(int *height, int heightSize)
{
    int front = 0;
    int back = heightSize - 1;
    int water = 0;
    int water_max = 0;
    while (back > front)
    {
        if (height[front] > height[back])
        {
            water = height[back] * (back - front); 
            back--;
        }
        else
        {
            water = height[front] * (back - front);
            front++;
        }
        if(water > water_max){
            water_max = water;
        }
    }
    return water_max;
}

int main()
{
    // Your code goes here

    return 0;
}