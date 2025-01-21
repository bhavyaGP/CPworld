#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "aababcaab";
    int maxLetters = 2, minSize = 3, maxSize = 4;

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

    cout << "Maximum Frequency: " << maxCount << endl;

    return 0;
}
