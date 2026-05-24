class Solution {
public:
    int passwordStrength(string str) {
        set<char> st(str.begin(), str.end());
        int point=0;
        for(char x:st){

            if(isalpha(x) && islower(x)){
                point++;
            }else if(isalpha(x) && isupper(x)){
                point+=2;
            }else if(isdigit(x)){
                point+=3;
            }else if(!isalnum(x)){
                point+=5;
            }
        }
        return point;
    }
};