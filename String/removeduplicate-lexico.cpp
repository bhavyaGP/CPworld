#include <bits/stdc++.h>
using namespace std;
int main()
{

    string str = "cbacdcbc";
    string ans;

    vector<bool> map(26, false);
    vector<int> lastIndex(26);

    for(int i=0;i<str.length();i++){
        lastIndex[str[i]-'a']=i;
    }

    for(int i=0;i<str.length();i++){
        
        if(map[str[i]-'a']==true){
            continue;
        }

        while(ans.length()> 0 && ans.back()>str[i] && lastIndex[ans.back()-'a']>i  ){
            map[ans.back()-'a']=false;
            ans.pop_back();
        }
        ans.push_back(str[i]);
        map[str[i]-'a']=true;
    }  
    cout<<ans; 

}