class Solution {
public:
    bool checkPowersOfThree(int n) {
        int pw=0;
        while(pow(3,pw)<=n){
            pw++;
        }
        while(n>0){
            if(n>=pow(3,pw)){
                n-=pow(3,pw);
                if(n>=pow(3,pw)){
                    return false;
                }
            }
            pw--;
        }
        return true;
    }
};