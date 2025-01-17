class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> freqMap;
        int maxCount = 0;

        for (int i = 0; i <= s.length() - minSize; i++) {
            string current = s.substr(i, minSize);
            unordered_set<char> uniqueChars(current.begin(), current.end());

            if (uniqueChars.size() <= maxLetters) {
                freqMap[current]++;
                maxCount = max(maxCount, freqMap[current]);
            }
        }
        return maxCount;
        
    }
};