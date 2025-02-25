#include<bits/stdc++.h>

using namespace std;
int main(){
    
    vector<int> nums={5,5,6,6,6,9,1,2};
    int i=0,j=0;
    int sum=0,maxi=0;
    while(j<nums.size()){
        sum+=nums[j];
        if(j+1 < nums.size() && nums[j]>=nums[j+1]){
            maxi=max(maxi,sum);
            sum=0;
            i=j+1;
        }
        j++;
    }
    cout<<max(maxi,sum);

}