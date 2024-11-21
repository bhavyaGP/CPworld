#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    unordered_map<int, int> m;
    for (auto x : nums)
    {
        m[x]++;
    }
    for (auto x : m)
    {
        if (x.second > 1)
        {
            return true;
        }
    }
    return false;
}