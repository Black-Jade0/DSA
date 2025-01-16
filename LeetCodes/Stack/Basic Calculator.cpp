#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    string simplify(string s)
    {
        string ans;
        stack<char> st;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if (c != '(' && c != ')')
            {
                if ((c != '+' && c != '-') || st.empty())
                {
                    ans.push_back(c);
                }
                else
                {
                    char sign = st.top();
                    st.pop();
                    if ((sign == '+' && c == '+') || (sign == '-' && c == '-'))
                    {
                        ans.push_back('+');
                    }
                    else if ((sign == '+' && c == '-') || (sign == '-' && c == '+'))
                    {
                        ans.push_back('-');
                    }
                    st.push(sign);
                }
            }
            else
            {
                if (c == '(')
                {
                    char sign = '+';
                    if (i > 0)
                    {
                        if (s[i - 1] == '-')
                            sign = '-';
                        else if (s[i - 1] == '+')
                            sign = '+';
                    }
                    if (!st.empty() && st.top() == '-')
                    {
                        sign = (sign == '-') ? '+' : '-';
                    }
                    st.push(sign);
                }
                else
                {
                    st.pop();
                }
            }
        }
        return ans;
    }

    string removeSpaces(string s)
    {
        string ans;
        for (char c : s)
        {
            if (c == ' ')
                continue;
            else
                ans.push_back(c);
        }
        return ans;
    }

public:
    int calculate(string s)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        string str = removeSpaces(s);
        // cout<<str<<endl;
        str = simplify(str);
        // cout<<str<<endl;
        int ans = 0, temp = 0;
        char sign = '+';
        if (str[0] == '-')
            sign = '-';
        for (int i = 0; i < str.length(); i++)
        {
            char c = str[i];
            if (c >= '0' && c <= '9')
            {
                temp = temp * 10 + (c - '0');
            }
            else
            {
                if (sign == '-')
                {
                    temp *= -1;
                }
                ans += temp;
                temp = 0;
                if (c == '-')
                    sign = '-';
                if (c == '+')
                    sign = '+';
            }
        }
        if (sign == '-')
        {
            temp *= -1;
        }
        ans += temp;
        return ans;
    }
};

int main() {
    // Your code goes here

    return 0;
}