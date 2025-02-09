class Solution {
public:
    bool checkRecord(string s) {
        int acnt=0;
        int lcnt=0;
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='A'){acnt++;
            if(acnt>=2){
                return false;
            }}; 
            if(s[i]=='L'&& s[i+1]=='L' && s[i+2]=='L'){
                return false;
            }
        }
        return true;
    }
};