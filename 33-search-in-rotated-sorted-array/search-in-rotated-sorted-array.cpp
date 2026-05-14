class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(target==nums[mid]){
                return mid;
            }
            //left half sorted hai kya?
            if(nums[l]<=nums[mid]){
                if(target>=nums[l] && target<nums[mid]){ //window ko aur chota karo 
                    h=mid-1;
                }else{
                    l=mid+1; // nahi mila matlab woh pakka right side me hai  // 4 5 6 7 0 1 2 : target=1 
                }
            }else{ 
                if(target>nums[mid]&& target<=nums[h]){ //window ko chota karo 
                    l=mid+1;
                }else{
                    h=mid-1; //woh left side mai hai 
                }
            }
        }
        return -1;
    }
};