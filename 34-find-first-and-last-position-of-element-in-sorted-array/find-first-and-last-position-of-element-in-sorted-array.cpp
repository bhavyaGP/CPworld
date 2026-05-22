class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int cnt=0;
        int left=-1,right=-1;
        for(int i=0;i<nums.size();i++){
            if(target==nums[i]){
                if(cnt==0){
                    left=i;
                }
                right=i;
                cnt++;
            }
        }
        return {left,right};
    }
};