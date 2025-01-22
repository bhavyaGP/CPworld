class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int i = 0 , j = 9;
        unordered_map<string , int> mp;
        while(j < s.length())
        {
            mp[s.substr(i , j - i + 1)]++;
            j++;
            i++;
        }
        
        vector<string> ans;
        for(auto it : mp)
        {
            if(it.second > 1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};