#include <bits/stdc++.h>
using namespace std;
bool isvowel(char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
int main()
{
    string s = "leetcode";
    int k = 3;
    int low = 0, high = 0, windowsize = k;

    int count = 0;
    int maxcount = 0;
    while (high < s.length())
    {
        if (isvowel(s[high]))
        {
            count++;
        }
        if (high - low + 1 == windowsize)
        {
            maxcount = max(maxcount, count);
            if (isvowel(s[low]))
            {
                count--;
            }
            low++;
        }
        high++;
    }
    cout << maxcount << endl;
}