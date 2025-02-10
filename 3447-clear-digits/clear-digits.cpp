class Solution {
public:
    string clearDigits(string s) {
        string st="";
        for(auto x:s){
            if(isalpha(x)){
                st+=x;
            }else{
                st.pop_back();
            }
        }
        return st;
        

    }
};