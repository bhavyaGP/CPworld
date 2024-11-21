#include <bits/stdc++.h>
using namespace std;
int main()
{

    string str = "abacbc";
    unordered_map<char, int> mp;

    for (auto x : str)
    {
        mp[x]++;
    }
    vector<int> ans;
    for (auto x : mp)
    {
        ans.push_back(x.second);
    }
    for (int i = 0; i < ans.size() - 1; i++)
    {
        if (ans[i] != ans[i + 1])
        {
            cout << "false";
            break;
        }
    }
    cout << "True";
}