#include <bits/stdc++.h>
using namespace std;
bool isvowel(char x)
{
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ||
        x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
        return true;
    else
        return false;
}
int main()
{

    string str = "lYmpH"; //lYmpH
    vector<char> v;
    string ans = "";

    for (auto x : str)
    {
        if (isvowel(x))
        {
            v.push_back(x);
        }
    }

    sort(v.begin(), v.end());

    int j = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (isvowel(str[i]))
        {
            ans += v[j];
            j++;
        }
        else
        {
            ans += str[i];
        }
    }
    cout<<ans;

}