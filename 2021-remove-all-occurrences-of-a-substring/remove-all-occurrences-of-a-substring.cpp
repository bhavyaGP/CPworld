class Solution {
public:
    bool check(stack<char>& st, string& part, int n) {
        stack<char> tempSt = st;

        for(int idx = n-1; idx >= 0; idx--) {
            if(tempSt.top() != part[idx]) {
                return false;
            }

            tempSt.pop();
        }

        return true;
    }
    string removeOccurrences(string s, string part) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            st.push(s[i]);
            if(st.size()>=part.length() && check(st,part,part.length())==true){
                for(int k=0;k<part.length();k++){
                    st.pop();
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};