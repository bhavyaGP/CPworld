#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums={1,2,4};
    int ans=0;

    for(int i=0;i<nums.size();i++){ 
        int diff=abs(nums[i]-nums[(i+1)%nums.size()]);
        ans=max(ans,diff);
    }
    cout<<ans;

}