#include <iostream>
#include <stack>
using namespace std;

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        stack<char> st;
        string ans = "";

        for (int i = 0; i < str.length(); i++)
        {
            char c = str[i];
            if (isalpha(c))
            {
                ans += c;
            }
            else if (c == '(')
            {
                st.push(c);
            }
            else if (c == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && precedence(c) <= precedence(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        cout << ans;
    }

    return 0;
}