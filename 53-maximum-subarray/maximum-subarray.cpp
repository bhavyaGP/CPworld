class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=nums[0];
        int anssum=nums[0];
        for(int i=1;i<nums.size();i++){
            int currsum=maxsum+nums[i]; //previous summ rakhna hai ya nahi
            maxsum=max(currsum,nums[i]); // curr sum better hai ya i se naya sum shuru karu?
            anssum=max(maxsum,anssum); //hamare ans ko update karo
        }
        return anssum;
    }
};