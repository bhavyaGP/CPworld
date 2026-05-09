class Solution {
public:
    vector<int> scoreValidator(vector<string>& nums) {
        int score=0,cnt=0;
        for(auto x:nums){
            if(isdigit(x[0])) score+=stoi(x);
            else if(x=="WD" || x=="NB") score++;
            else if(x=="W") cnt++;
            
            if(cnt==10) break;
        }
        return {score,cnt};
    }
};