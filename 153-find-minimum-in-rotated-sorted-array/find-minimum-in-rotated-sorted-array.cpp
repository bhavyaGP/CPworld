class Solution {
public:
    int findMin(vector<int>& nums) {
        int resultIdx=0;
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid] < nums[resultIdx]){ //mujhe aur chota element mila 
                resultIdx=mid;
            }
            if(nums[mid]>nums[r]){  //true hai toh min element right side hai
                l=mid+1;
            }else{
                r=mid-1;  // flase hua means min element left side hai
            }
        }
        return nums[resultIdx];
    }
};