class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        map<int, int> freq;
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if(a[i]==b[i]){
                cnt++;
            }else{
                if(freq[a[i]]>0){
                    cnt++;
                }
                if(freq[b[i]]>0){
                    cnt++;
                }
            }
            freq[a[i]]++;
            freq[b[i]]++;
            ans.push_back(cnt);
        }

        return ans;
    }
};