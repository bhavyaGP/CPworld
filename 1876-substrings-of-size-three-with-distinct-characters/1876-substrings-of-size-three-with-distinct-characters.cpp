class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int low = 0, high = 0, windowsize = 3;
        int count = 0;

        while (high < n) {

            if (high - low + 1 < windowsize) {
                high++;
            } else {
                if (s[low] != s[low + 1] && s[low] != s[high] &&
                    s[low + 1] != s[high]) {
                    count++; 
                }
                low++;
                high++;
            }
        }

        return count;
    }
};
