#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr){
    stack<int> st;
    vector<int> ans;
    for(int i=arr.size()-1;i>=0;i--){
        if(st.size()==0){
            st.push(arr[i]);
            ans.push_back(-1);
        }
        else if(st.size()>0 && st.top()>arr[i]){ //arr[i]=2 hai aur top=3 toh push karenge na
            ans.push_back(st.top());
        }else if(st.size()>0 && st.top()<=arr[i]){ //top->0,1,2 hai aur arr[i]=8
            while(!st.empty() && st.top()<=arr[i]){ //greater nahi milta tab tak pop karo
                st.pop();
            }
            if(st.size()==0){ //koi nahi mila toh -1
                ans.push_back(-1);
            }else{
                ans.push_back(st.top()); //agar last mai ak bacha hai , jo next greater hoga 
            }
        }
        st.push(arr[i]);  // must condition hai, koi element reh na jaye
    }
    reverse(ans.begin(),ans.end()); //ans reverse aayega kyuki piche kar rahe hai (traverse)
    return ans;

}
int main(){
    vector<int> arr={6, 8, 0, 1, 3};
    vector<int> ans=solve(arr);
    for(auto x:ans){
        cout<<x<<" ";
    }
}