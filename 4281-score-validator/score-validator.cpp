class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        map<string, int> mp =
        { {"0", 0},
          {"1", 1},
          {"2", 2},
          {"3", 3},
          {"4", 4},
          {"6", 6},
          {"WD", 1},
          {"NB", 1} };
        int score=0,cnt=0;
        for (auto x : events) {
            if (mp.find(x)==mp.end()){
                cnt++;
                if(cnt==10) break;
            }else{
                score+=mp[x];
            }
        }
        return {score,cnt};
    }
};