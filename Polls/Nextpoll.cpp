#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int e = 5, f = 3;
    cout << (e ^ f) << endl;
    // a. 6
    // b. 125
    // c. 7
    // d. Error

    // Explanation: XOR operation between 5 (101) and 3 (011) gives 6 (110).
    // Answer: a. 6

    int arr[] = {1, 2, 3};
    int *point = arr;
    cout << *(point + 1) << endl;
    // a. 1
    // b. 2
    // c. 3
    // d. Error

    // Explanation:
    // Here arr stores the address of the first element of the array that is 1
    // we declare a pointer variable point that points to the memory location with memory address arr
    // Now we increement the memory address by 1 and get the value stored in it via '*' operator i.e. 2.

    // Answer: b. 2
    
    return 0;
}
