class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int i=0,j=0,k=p.length();
        vector<int> v(26,0);
        for(auto x:p){
            v[x-'a']++;
        }
        while(j<s.length()){
            char c=s[j];
            v[c-'a']--;
            if(j-i+1==k){
                if(vector<int>(26,0)==v)
                    ans.push_back(i);

                v[s[i] - 'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};