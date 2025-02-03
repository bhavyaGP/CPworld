class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxlen=1,incL=1,decL=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                incL++;
                decL=1;
            }
            else if(nums[i]<nums[i-1]){
                incL=1;
                decL++;
            }else{
                incL=1;
                decL=1;
            }
            maxlen=max(maxlen,max(incL,decL));
        }
        return maxlen;
    }
};