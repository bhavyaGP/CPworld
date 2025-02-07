class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> btc, ctb;
        vector<int> ans;

        for (const auto& query : queries) {
            int key = query[0], value = query[1];

            if (btc.find(key) == btc.end()) {
                btc[key] = value;
                ctb[value]++;
            } else {
                int oldValue = btc[key];
                ctb[oldValue]--;
                if (ctb[oldValue] == 0) {
                    ctb.erase(oldValue);
                }
                btc[key] = value;
                ctb[value]++;
            }

            ans.push_back(ctb.size());
        }
        return ans;
    }
};