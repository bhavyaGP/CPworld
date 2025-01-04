#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "abccccdd";
    unordered_set<char> st;
    int cnt = 0;
    for (auto x : str)
    {
        if (st.find(x) == st.end())
        {
            st.insert(x);
        }
        else
        {
            st.erase(x);
            cnt += 2;
        }
    }
    if (!st.empty())
    {
        cnt++;
    }
    cout << cnt;
}