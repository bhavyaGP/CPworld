#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "((a+t)*((b+(a+c))^(c+d)))";

    stack<char> st;
    string ans;

    for (int i = 0; i < str.size(); i++)
    {
        if (isalpha(str[i]))
        {
            ans += str[i];
        }
        else if (str[i] == '(')
        {
            st.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }   
            if (!st.empty())
                st.pop(); // pop the '('
        }
        else
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    cout << ans;
}