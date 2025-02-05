class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> v1(26, 0), v2(26, 0);
        int diffs = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diffs++;
            }
            if (diffs > 2)
                return false;
            v1[s1[i] - 'a']++;
            v2[s2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }
};