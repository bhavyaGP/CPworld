#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "3[a2[c]]" ;//"3[a]2[bc]"; 
    int n = str.length();
    stack<string> st;
    stack<int> numst;    
    int i = 0;
    int num=0;
    string curr="";
    while (i < n)
    {
        if(isdigit(str[i])){
           num = num * 10 + (str[i] - '0');
        }else if(str[i]=='['){
            numst.push(num);
            st.push(curr);
            num=0;
            curr="";    
        }else if(str[i]==']'){
            string temp=curr;
            curr=st.top();
            st.pop();
            int time=numst.top();
            numst.pop();
            while(time--){
                curr+=temp;
            }
        }else if(isalpha(str[i])){
            curr+=str[i];
        }
        i++;
    }
    cout<<curr;
}