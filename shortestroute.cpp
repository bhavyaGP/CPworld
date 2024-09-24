#include <bits/stdc++.h>
using namespace std;
int main()
{

    string str = "NNSEWEE";
    unordered_map<char, int> mp;
    for (auto x : str)
    {
        mp[x]++;
    }
    string ans = "";
    if (mp['E'] > mp['W'])
    {
        while (mp['E'] - mp['W'] > 0)
        {
            ans += "E";
            mp['E']--;
        }
    }
    else
    {
        while (mp['W'] - mp['E'] > 0)
        {
            ans += "W";
            mp['W']--;
        }
    }
    if (mp['N'] > mp['S'])
    {
        while (mp['N'] - mp['S'] > 0)
        {
            ans += "N";
            mp['N']--;
        }
    }
    else
    {
        while (mp['S'] - mp['N'] > 0)
        {
            ans += "S";
            mp['S']--;
        }
    }
    sort(ans.begin(), ans.end());

    cout << ans;
}