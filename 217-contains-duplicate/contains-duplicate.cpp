class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(auto x:nums){
            if(mp.find(x)==mp.end()){
                mp[x]++;
            }
            else{
                return true;
            }           
        }
        return false;
    }

};