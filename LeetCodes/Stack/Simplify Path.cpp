#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        string result;

        for (int i = 0; i < path.size(); ++i)
        {
            if (path[i] == '/')
                continue;
            string temp;
            // iterate till we doesn't traverse the whole string and doesn't encounter the last /
            while (i < path.size() && path[i] != '/')
            {
                // add path to temp string
                temp += path[i];
                ++i;
            }
            if (temp == ".")
                continue;
            // pop the top element from stack if exists
            else if (temp == "..")
            {
                if (!st.empty())
                    st.pop();
            }
            else
                // push the directory file name to stack
                st.push(temp);
        }

        // adding all the stack elements to result
        while (!st.empty())
        {
            result = "/" + st.top() + result;
            st.pop();
        }

        // if no directory or file is present
        if (result.size() == 0)
            return "/";

        return result;
    }
};

int main()
{
    string path = "/.../a/../b/c/../d/./";
    Solution a;
    string result = a.simplifyPath(path);
    cout << result;
    return 0;
}