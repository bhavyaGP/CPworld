class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg=0,pos=0;
        for(auto x:nums){
            if(x>0){
                pos++;
            }else if(x<0){
                neg++;
            }else{
                continue;
            }
        }
        return max(neg,pos);
    }
};