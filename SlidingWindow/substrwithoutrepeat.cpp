#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "abcabcbb";
    int maxlength = 0;
    for (int i = 0; i < str.length(); i++)
    {
        vector<int> count(256, 0);

        for (int j = i; j < str.length(); j++){

            if(count[str[j]-'a']==1){break;}
            maxlength=max(maxlength,j-i+1);
            count[str[j]-'a']=1;
        }
    }
    cout<<maxlength;
}