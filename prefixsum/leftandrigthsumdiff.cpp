#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {10, 4, 8, 3};

    // Brute force approach with Space complexity of O(3n)

    // vector<int> left(nums.size());
    // vector<int> right(nums.size());

    // left[0]=0;
    // for(int i=1;i<nums.size();i++){
    //     left[i]=left[i-1]+nums[i-1];
    // }
    // right[nums.size()-1]=0;
    // for(int i=nums.size()-2;i>=0;i--){
    //     right[i]=right[i+1]+nums[i+1];
    // }
    // vector<int> ans(nums.size());
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     ans[i]=abs(left[i]-right[i]);
    // }

    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }

    // Optimised approach with Space complexity of O(n)
    int rightsum = 0;
    for (auto x : nums)
    {
        rightsum += x;
    }
    int leftsum = 0;
    vector<int> ans(nums.size());
    for (int i = 0; i < ans.size(); i++)
    {
        rightsum -= nums[i];
        ans[i] = abs(leftsum - rightsum);
        leftsum += nums[i];
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}