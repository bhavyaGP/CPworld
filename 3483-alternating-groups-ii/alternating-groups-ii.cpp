class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int N = n + (k-1);
        for(int i = 0; i < k-1; i++) {
            colors.push_back(colors[i]);
        }

        int ans = 0;
        int left = 0;
        int right = 1; 
        while(right < N) {
            if(colors[right] == colors[right-1]) {
                left = right;
                right++;
                continue;
            }

            if(right - left + 1 == k) {
                ans++;
                left++;
            }

            right++;
        }

        return ans;
    }
};