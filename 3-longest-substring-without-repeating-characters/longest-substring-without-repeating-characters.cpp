class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, n = s.length(), ans = 1;
        unordered_map<char, int> mp;
        if(s.length()==0){
            return 0;
        }
        while (j < n) {
            char c = s[j];
            mp[c]++;
            while (mp[c] > 1) {
                mp[s[i]]--;
                i++;
            }   
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};