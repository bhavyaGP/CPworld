#include<bits/stdc++.h>
using namespace std;
int main(){

    vector<int> nums={4,3,2,7,8,2,3,1};
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        if(nums[i]==nums[i+1]){
            cout<<nums[i]<<" ";
        }
    }
}