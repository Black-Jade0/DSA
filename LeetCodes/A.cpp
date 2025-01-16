#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

void example(int &a, int &b)
{
    a = a + 1;
    b = b + 2;
    return;
}

int main()
{
    int a = 4;
    int b = 10;
    example(a, b);
    example(a, b);
    cout << a << endl;
    cout << b << endl;
    return 0;
}