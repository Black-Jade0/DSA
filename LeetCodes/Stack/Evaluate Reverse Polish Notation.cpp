#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int calculate(int a, int b, const string op)
    {
        if (op == "+")
        {
            return a + b;
        }
        else if (op == "-")
        {
            return a - b;
        }
        else if (op == "*")
        {
            return a * b;
        }
        else if (op == "/")
        {
            return b != 0 ? a / b : 0; // Handle division by zero
        }
        else
        {
            return 0; // Invalid operator
        }
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<string> st;
        int result;
        for (size_t i = 0; i < tokens.size(); i++)
        {
            string token = tokens[i];
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                string c = to_string(calculate(b, a, token));
                st.push(c);
            }
            else
            {
                st.push(token);
            }
        }
        result = stoi(st.top());
        return result;
    }
};

int main()
{

    return 0;
}