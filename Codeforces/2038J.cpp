#include <bits/stdc++.h>

using namespace std;

int main()
{
    int INP;
    cin >> INP;
    int passengers = 0;
    while (INP--)
    {
        string s;
        int num;
        cin >> s >> num;
        if (s == "P")
        {
            passengers += num;
            continue;
        }
        if (passengers < num)
        {
            passengers = 0;
            cout << "YES" << endl;
        }
        else if(passengers == num){
            passengers = 0;
            cout << "NO" << endl;
        }
        else{
            passengers -= num;
            cout << "NO" << endl;
        }
    }
    return 0;
}