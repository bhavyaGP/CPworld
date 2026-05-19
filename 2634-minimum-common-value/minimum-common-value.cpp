class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        for(auto x:nums1){
            mp[x]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(mp.find(nums2[i])!=mp.end()){
                return nums2[i];
            }
        }
        
        return -1;
    }
};