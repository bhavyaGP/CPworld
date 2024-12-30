#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> sym = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int num = 1994;
    int i = 0;
    string ans;
    while (num > 0)
    {

        if (num >= val[i])
        {
            ans+=sym[i];
            num-=val[i];
        }else{
            i++;
        }
    }
    cout<<ans;
}