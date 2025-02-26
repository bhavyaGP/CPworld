class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currentmaxsum = nums[0], maxsum = nums[0], currentminsum = nums[0],
            minsum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currentmaxsum = max(nums[i], currentmaxsum + nums[i]);
            currentminsum = min(nums[i], currentminsum + nums[i]);
            maxsum = max(currentmaxsum, maxsum);
            minsum = min(currentminsum, minsum);
        }

        return max(abs(minsum), abs(maxsum));
    }
};