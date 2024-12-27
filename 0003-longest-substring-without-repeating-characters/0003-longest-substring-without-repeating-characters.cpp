class Solution {
public:
    int lengthOfLongestSubstring(string str) {
         int maxlength = 0;
        if (str.length() == 0) {
            return 0;
        }
        
        for (int i = 0; i < str.length(); i++) {
            vector<int> count(256, 0); 
            
            for (int j = i; j < str.length(); j++) {
                if (count[str[j]] == 1) { 
                    break; 
                }
                maxlength = max(maxlength, j - i + 1);
                count[str[j]] = 1; 
            }
        }
        return maxlength;
    }
};