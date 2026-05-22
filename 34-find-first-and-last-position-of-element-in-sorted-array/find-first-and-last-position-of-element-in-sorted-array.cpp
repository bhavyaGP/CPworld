class Solution {
public:
    int rightmost(vector<int>& nums, int target){
        int left=0,right=nums.size()-1;
        int rightMost=-1; //if don't get any idx then -1 not 0
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                rightMost=mid; //ho sakte hai mera answer 
                left=mid+1; //right me aur target element hai kya?
            }else if(target>nums[mid]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return rightMost;
    }
    int leftmost(vector<int>& nums, int target){
        int left=0,right=nums.size()-1;
        int leftMost=-1;//if don't get any idx then -1 not 0
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                leftMost=mid; //ho sakte hai mera answer 
                right=mid-1; //left me aur target element hai kya?
            }else if(target>nums[mid]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return leftMost;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {leftmost(nums,target),rightmost(nums,target)};
    }
};