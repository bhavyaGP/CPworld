#include <bits/stdc++.h>
using namespace std;

bool hasAllCodes(string s, int k)
{
    int windowsize = k;
    int low = 0, high = 0;
    unordered_set<string> st;
    if (s.length() < k)
        return false;
    while (high < s.length())
    {
        if (high - low + 1 == windowsize)
        {
            st.insert(s.substr(low, windowsize));
            low++;
        }
        high++;
    }
    return st.size() == pow(2, k);
}
int main()
{

    string str = "00110110";
    int k = 2;
    if (hasAllCodes(str, k))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}