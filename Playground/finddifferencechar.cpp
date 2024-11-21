#include <bits/stdc++.h>
using namespace std;
int main()
{
    // constrains
    // t.length == s.length + 1

    string s, t;
    s = "abcd";
    t = "abce";
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    int i;
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] != t[i])
            cout << t[i];
    }
    cout << t[i];
}