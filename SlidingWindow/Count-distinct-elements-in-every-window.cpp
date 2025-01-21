#include<bits/stdc++.h>

using namespace std;
int main(){
    vector<int> arr={1, 2, 1, 3, 4, 2, 3};
    int k=4;
    int i=0,j=0;    
    vector<int> ans;
    unordered_map<int,int> mp;
    while(j<arr.size()){
        mp[arr[j]]++;
        if(j-i+1==k){
            ans.push_back(mp.size());
            mp[arr[i]]--;
            if(mp[arr[i]]==0){
                mp.erase(arr[i]);
            }
            i++;    
        }
        j++;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}