#include <iostream>
using namespace std;

int main()
{
    // Question 1: Operator Precedence
    int x = 5, y = 2;
    cout << "Q1 Output: " << x + y * 3 - 4 / 2 << endl; // Expected Output: 9

    // Question 2: Implicit Type Conversion
    int a = 10;
    double b = 3.5;
    cout << "Q2 Output: " << a / b << endl; // Expected Output: 2.85714

    // Question 3: Post-Increment vs Pre-Increment
    int c = 3;
    cout << "Q3 Output: " << c++ * ++c << endl; // Expected Output: 16

    // Question 4: Sizeof Operator on Arrays
    int arr[] = {1, 2, 3, 4, 5};
    cout << "Q4 Output: " << sizeof(arr) / sizeof(arr[0]) << endl; // Expected Output: 5

    // Question 5: Pointers and Memory Address Manipulation
    int d = 10;
    int *p = &d;
    cout << "Q5 Output: " << *p + 1 << endl; // Expected Output: 11

    // Question 6: Bitwise AND Operator
    int e = 5, f = 3;
    cout << "Q6 Output: " << (e & f) << endl; // Expected Output: 1 (Binary: 101 & 011 = 001)

    // Question 7: Bitwise OR Operator
    cout << "Q7 Output: " << (e | f) << endl; // Expected Output: 7 (Binary: 101 | 011 = 111)

    // Question 8: Bitwise XOR Operator
    cout << "Q8 Output: " << (e ^ f) << endl; // Expected Output: 6 (Binary: 101 ^ 011 = 110)

    // Question 9: Left Shift Operator
    int g = 1;
    cout << "Q9 Output: " << (g << 3) << endl; // Expected Output: 8 (Binary: 0001 << 3 = 1000)

    // Question 10: Right Shift Operator
    int h = 16;
    cout << "Q10 Output: " << (h >> 2) << endl; // Expected Output: 4 (Binary: 10000 >> 2 = 00100)

    return 0;
}