class Solution {
public:
    int cntzero(string s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                cnt++;
            }
        }
        return cnt;
    }
    int cntone(string s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                cnt++;
            }
        }
        return cnt;
    }
    int maxScore(string str) {
        int maxi = 0;
        int n = str.length();
        for (int i = 0; i < n - 1; i++) {
            int sum = cntzero(str.substr(0, i + 1)) +
                      cntone(str.substr(i + 1, n - i - 1));

            maxi = max(maxi, sum);
        }
        return maxi;
    }
};