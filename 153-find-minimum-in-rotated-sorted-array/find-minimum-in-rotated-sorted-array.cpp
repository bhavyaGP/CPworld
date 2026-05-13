class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // nlogn time complexity 
        return nums[0];
    }
};