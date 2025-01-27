class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int result=0;
        int maxlen=0;
        unordered_map<char,int> mp;
        int i=0,j=0;
        while(j<str.length()){
            mp[str[j]]++;
            while(mp[str[j]]>1){
                mp[str[i]]--;
                i++;
            }   
            result=max(result,j-i+1);         
            j++;
        } 
        return result;
    }
};