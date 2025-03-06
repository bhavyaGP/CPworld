class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans(2);
        unordered_map<int, int> mp;
        int n = grid.size();
        int expected_sum = (n * n * (n * n + 1)) / 2;
        int actual_sum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                mp[val]++;
                actual_sum += val;
                if (mp[val] > 1) {
                    ans[0] = val;
                }
            }
        }

        ans[1] = expected_sum - actual_sum + ans[0]; 
        return ans;
    }
};