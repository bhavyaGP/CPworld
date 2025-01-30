class Solution {
public:
    int maxScore(string str) {
        int ttlone = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '1') {
                ttlone++;
            }
        }

        int leftzr = 0;
        int leftone = 0;
        int maxi = 0;
        for (int i = 0; i < str.length()-1; i++) {
            if (str[i] == '0') {
                leftzr++;
            } else {
                leftone++;
            }
            int rightone = ttlone - leftone;
            maxi = max(maxi, leftzr + rightone);
        }
        return maxi;
    }
};