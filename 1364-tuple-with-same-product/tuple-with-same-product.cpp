class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        for(auto x:mp){
            if(x.second>1){
                int fre=(x.second)*(x.second-1)/2;
                sum+=fre*8;
            }
        }
        return sum;
    }
};