#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> str = {"flower", "flow", "flight"};
    string ans = "";

    sort(str.begin(), str.end());

    for (int i = 0; i < str[0].length(); i++)
    {
        if (str[0][i] == str[str.size() - 1][i])
        {
            ans += str[0][i];
        }
    }

    cout<<ans;
}