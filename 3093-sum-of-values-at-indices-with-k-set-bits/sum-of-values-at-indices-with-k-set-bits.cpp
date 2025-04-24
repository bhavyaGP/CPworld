class Solution {
public:
    int countbit(int num){
        int cnt=0;
        while(num){
            if(num&1){
                cnt++;
            }
            num=num>>1;
        }
        return cnt;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(countbit(i)==k){
                sum+=nums[i];
            }
        }
        return sum;
    }
};