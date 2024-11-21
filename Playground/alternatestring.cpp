#include <bits/stdc++.h>
using namespace std;
int main()
{
    string w1 = "abc";
    string w2 = "pqr";
    string ans = "";
    int minLength = min(w1.length(), w2.length());
    for (int i = 0; i < minLength; i++)
    {
        ans += w1[i];
        ans += w2[i];
    }
    if (w1.length() > w2.length())
    {
        ans += w1.substr(minLength);
    }
    else if (w1.length() < w2.length())
    {
        ans += w2.substr(minLength);
    }
    cout<<ans;

}