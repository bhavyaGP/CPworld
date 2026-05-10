class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int cnt=0;
        int prefix=0;
        mp[prefix]=1;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];                  //1 -1 0  k=0
            if(mp.find(prefix-k)!=mp.end()){//0 1  0 0 
                cnt+=mp[prefix-k];
            }
            mp[prefix]++;
        }
        return cnt;
    }
};