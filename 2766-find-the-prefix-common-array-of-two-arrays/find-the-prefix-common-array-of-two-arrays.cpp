class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        map<int, int> freq;
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            freq[a[i]]++;
            if (freq[a[i]] == 2) {
                cnt++;
            }
            freq[b[i]]++;
            if (freq[b[i]] == 2) {
                cnt++;
            }
            ans.push_back(cnt);
        }

        return ans;
    }
};