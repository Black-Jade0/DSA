#include <iostream>
#include <vector>

using namespace std;
void fun(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    fun(n--);
}

void mystery(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    mystery(n - 1);
    cout << n << " ";
}

void foo(int n)
{
    cout << n << endl;
    foo(n + 1);
}

int main()
{
    int t = 0;
    cout << (~t) << endl;
    // a. 0
    // b. 1
    // c. -1
    // d. 2147483647

    // Explanation: ~0 is the bitwise NOT of 0, which results in all bits being 1.
    // The numbers are represented by a 32 bit binary string(the MSB telling whether the number is + or -)

    // -2147483648 to -1
    // 1000__00000 to 11111___111

    // 0           to 2147483647
    // 00000___000 to 01111___111

    // Answer: c. -1

    int e = 5, f = 3;
    cout << (e ^ f) << endl;
    // a. 6
    // b. 125
    // c. 7
    // d. Error

    // Explanation: XOR operation between 5 (101) and 3 (011) gives 6 (110).
    // Answer: a. 6

    double x = 0.1 + 0.2;
    if (x == 0.3)
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;

    // a) Equal
    // b) Not Equal
    // c) Compilation Error
    // d) Undefined Behavior

    // Explanation:
    // Floating - point numbers(double) suffer from precision errors due to binary representation.
    // 0.1 and 0.2 cannot be represented exactly in binary, so 0.1 + 0.2 results in something slightly different from 0.3,
    // typically 0.30000000000000004.
    // The condition x == 0.3 fails, and it goes to the else branch.
    // Answer : b) Not Equal

    fun(5);
    // A) 5 4 3 2 1
    // B) 5 4 3 2 1 0
    // C) Infinite Loop
    // D) Compilation Error

    // Explanation:
    //     The issue is with fun(n--).The post - decrement operator(n--) decreases n after passing its original value to the function, but the function expects a decremented value.Instead, n-- still passes n in the recursive call, causing infinite recursion.Many compilers will throw a warning  or error.

    // Answer: D) Compilation Error

    mystery(3);
    // A) 3 2 1 1 2 3
    // B) 3 2 1
    // C) 1 2 3 3 2 1
    // D) 1 1 2 2 3 3

    // Explanation:
    // The function first prints n, then recursively calls itself, and after that, it prints n again.

    // Answer: A) 3 2 1 1 2 3

    int a = 1e9;
    int c = 3;
    cout << a * c * 1LL << endl;
    // a) Compilation Error
    // b) 3000000000
    // c) Overflow
    // d) Garbage Value

    // Explanation:
    // 1e9 means 1 * 10⁹ = 1000000000.
    // int c = 3, so a *c = 1000000000 * 3 = 3000000000.
    // int can store values only up to 2, 147, 483, 647(INT_MAX).
    // 3000000000 exceeds this limit, causing integer overflow.
    // However, 1LL is long long, but it comes after multiplication, meaning the overflow happens before type promotion.

    foo(1);
    // A) Print numbers infinitely
    // B) Print numbers up to a certain limit and then crash
    // C) Compile-time error
    // D) Print only 1

    //  Explanation: This is an infinite recursion without a base case, meaning it keeps calling itself indefinitely. However, since every function call consumes stack space, it will eventually lead to a stack overflow error.

    // Answer: B) Print numbers up to a certain limit and then crash

    char arr[] = "Hello";
    int arr2[] = {1, 2, 3, 4};
    cout << arr + 1 << endl;
    cout << arr2 + 1 << endl;
    // A) Address of second element of arr
    //    Address of second element of arr2

    // B) e
    //    Address of second element of arr2

    // C) ello
    //    Address of second element of arr2

    // D) e
    //    2

    // Explanation:
    // arr + 1 moves the pointer to the second character of "Hello", so it prints "ello". cout treats char* as a string, so it prints "ello".
    // arr2 + 1 moves the pointer to the second element of arr2, but cout prints the memory address, not the value.cout treats int * as a pointer, so it prints a memory address.
    // Answer :
    // C) ello
    //    2
    
    return 0;
}
