class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left=0,right=0;
        int ans=INT_MAX;
        unordered_map<char,int> mp;
        while(right<blocks.length()){
            mp[blocks[right]]++;
            if(right-left+1==k) {
                ans=min(ans,mp['W']);
                mp[blocks[left]]--;
                left++;
            }
            right++;
        }
        return ans;
    }
};