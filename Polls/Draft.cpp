#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e9 + 7;
void fun(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    fun(n--);
}

int main()
{
    fun(5);

    return 0;
}
