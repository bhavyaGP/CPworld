class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int i = 0, j = 0;
        int sum = 0, maxi = 0;

        while (j < nums.size()) {
            sum += nums[j];
            if (j + 1 < nums.size() && nums[j] >= nums[j + 1]) {
                maxi = max(maxi, sum);
                sum = 0;
                i = j + 1;
            }
            j++;
        }
        return max(maxi, sum);
    }
};