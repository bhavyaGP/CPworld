class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++) {
            sort(words[i].begin(), words[i].end());
        }
        
        vector<string> result;
        string firstWord = words[0]; 
        
        for (char ch : firstWord) { 
            bool foundInAll = true;
            for (int i = 1; i < n; i++) {
                auto it = find(words[i].begin(), words[i].end(), ch);
                
                if (it == words[i].end()) {
                    foundInAll = false;
                    break;
                } else {
                    words[i].erase(it); 
                }
            }
            
            if (foundInAll) {
                result.push_back(string(1, ch));
            }
        }
        
        return result;
    }
};
