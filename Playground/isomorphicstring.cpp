#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "title";
    string t = "paper";

    unordered_map<char, char> s2t;
    unordered_map<char, char> t2s;
    for (int i = 0; i < s.length(); i++)
    {
        char ch1 = s[i];
        char ch2 = t[i];

        if (s2t.find(ch1) != s2t.end() && s2t[ch1] == ch2 ||
            t2s.find(ch2) != t2s.end() && t2s[ch2] == ch1)
        {
            return false;
        }
        s2t[ch1] = ch2;
        t2s[ch2] = ch1;
    }
    return true;
}
