class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> count(26,0);
        for(auto x:p){
            count[x-'a']++;
        }
        vector<int> ans;
        int low = 0, high = 0, windowsize = p.length();
        while (high < s.length()) {
            count[s[high] - 'a']--;
            if (high - low + 1 == windowsize) {

                if (count == vector<int>(26, 0)) {
                    ans.push_back(low);
                }
                count[s[low] - 'a']++;
                low++;
            }
            high++;
        }
        return ans;
    }
};