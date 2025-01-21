class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int low = 0, high = 0, windowsize = k;
        long long result = 0;
        unordered_set<int> st;
        long long sum = 0;
        while (high < nums.size()) {

            if (st.find(nums[high]) == st.end()) {
                st.insert(nums[high]);
                sum += nums[high];
                if (high - low + 1 == k) {
                    result = max(result, sum);
                    st.erase(nums[low]);
                    sum -= nums[low];
                    low++;
                }
                high++;
            } else {
                st.erase(nums[low]);
                sum -= nums[low];
                low++;
            }
        }
        return result;
    }
};