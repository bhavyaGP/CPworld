class Solution {
public:
    int findsum(int n) {
        int sum = 0;
        while (n != 0) {
            int last = n % 10;
            sum += last;
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxsum = -1;
        for (int i = 0; i < nums.size(); i++) {
            int digitsum = findsum(nums[i]);
            if (mp.find(digitsum) != mp.end()) {
                maxsum = max(maxsum, mp[digitsum] + nums[i]);
                mp[digitsum] = max(mp[digitsum], nums[i]);
            } else {
                mp[digitsum] = nums[i];
            }
        }
        return maxsum;
    }
};