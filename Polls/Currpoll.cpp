#include <iostream>
#include <vector>

using namespace std;

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

    int c = 3;
    cout << c++ * ++c << endl;
    // a. 15
    // b. 16
    // c. 12
    // d. 25

    // Explanation: c++ is post-increment (c = 3, then c becomes 4), ++c is pre-increment (c becomes 5), so 3 * 5 = 15.
    // Answer: a. 15

    int g = 1;
    cout << (g << 3) << endl;
    // a. 3
    // b. 8
    // c. 1000
    // d. 1

    // Explanation: Left shift by 3 (g = 1 << 3) gives 1 * (2^3) = 8.
    // Answer: b. 8

    int a = 10;
    double b = 3.5;
    cout << a / b << endl;
    // a. 2
    // b. 3
    // c. 2.857
    // d. 2.9

    // Explanation: The division promotes a to double, so 10.0/3.5 = 2.857....
    // Answer: c 2.857

    int d = 10;
    int *p = &d;
    cout << p + 1 << endl;
    // a. 0x5ffe78
    // b. 11
    // c. 18973
    // d. Error

    // Explanation: p + 1 increments the pointer to the next memory address for an int, which is 4 bytes away.
    // Answer: a. 0x5ffe78 (or similar address, depends on the machine)

    string st = "";
    for (int i = 1; i < 100; i++)
    {
        st += (to_string(i));
    }
    cout << st[100] << endl;
    // a. 100
    // b. 99
    // c. 5
    // d. 1

    // Explanation: st contains concatenated string "123456...99". st[100] accesses the 101st character, which is '5'.
    // Answer: c. 5

    return 0;
}
