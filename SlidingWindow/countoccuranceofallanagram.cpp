#include <bits/stdc++.h>
using namespace std;
int main()
{

    string str1 = "forxxorfxdofr";
    string str2 = "for";

    int low = 0, high = 0, windowsize = str2.length();
    int ans = 0;
    vector<int> count(26, 0);
    for (auto x : str2)
    {
        count[x - 'a']++;
    }
    while (high < str1.length())
    {
        count[str1[high] - 'a']--;
        if (high - low + 1 == windowsize)
        {
            if (count == vector<int>(26, 0))
            {
                ans++;
            }
            count[str1[low] - 'a']++;
            low++;
        }

        high++;
    }
    cout << ans << endl;
}