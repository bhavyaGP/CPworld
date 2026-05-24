class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        map<int, int> mp;

        for (auto x : nums) {
            if (mp.find(x) == mp.end() || mp[x] < k) {
                mp[x]++;
            }
        }

        vector<int> ans;

        for (auto x : mp) {
            while (x.second) {
                ans.push_back(x.first);
                x.second--;
            }
        }
        return ans;
    }
};