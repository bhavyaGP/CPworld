class Solution {
public:
    int findMin(vector<int>& nums) {
      int low = 0, high = nums.size() - 1;
        while (low < high) {//we have sorted arr we can apply binary search that's why we have selected binary search here but in different way 
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return nums[low];
    }
};