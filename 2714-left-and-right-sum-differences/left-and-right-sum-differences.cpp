class Solution {
public:
    //space complexity O(n);
    vector<int> leftRightDifference(vector<int>& nums) {
        int rightsum = 0;
        for (auto x : nums) {
            rightsum += x;
        }
        int leftsum = 0;
        vector<int> ans(nums.size());
        for (int i = 0; i < ans.size(); i++) {
            rightsum -= nums[i];
            ans[i] = abs(leftsum - rightsum);
            leftsum += nums[i];
        }
        return ans;
    }
};