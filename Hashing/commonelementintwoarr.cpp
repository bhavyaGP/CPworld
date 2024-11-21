#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<int> num1 = {4, 3, 2, 3, 1},
                num2 = {2, 2, 5, 2, 3, 6};

    unordered_map<int, int> m1, m2;
    for (auto x : num1)
    {
        m1[x]++;
    }
    for (auto x : num2)
    {
        m2[x]++;
    }
    int ans1 = 0, ans2 = 0;

    for (int i = 0; i < num1.size(); i++)
    {
        if (m2.find(num1[i]) != m2.end())
        {
            ans1++;
        }
    }
    for (int i = 0; i < num2.size(); i++)
    {
        if (m1.find(num2[i]) != m1.end())
        {
            ans2++;
        }
    }
    cout << ans1 << ans2;
}