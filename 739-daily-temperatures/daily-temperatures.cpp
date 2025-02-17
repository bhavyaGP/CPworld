class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[i]>=arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=0;
            }else{
                ans[i]=st.top()-i;
            }
            st.push(i);
        }
        return ans;
    }
};