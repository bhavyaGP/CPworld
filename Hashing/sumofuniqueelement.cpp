#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums={1,2,3,2};
    unordered_map<int,int> mp;
    int ans=0;
    for(auto x:nums){
        mp[x]++;
    }
    for(auto x:mp){
        if(x.second==1){
            ans+=x.first;
        }
    }

    cout<<ans;
}