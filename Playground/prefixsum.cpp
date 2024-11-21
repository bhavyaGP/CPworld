#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[5]={1,2,3,4,5};
    int prefix[5];
    prefix[0]=arr[0];
    for (int i = 1; i < 5; i++)
    {
        prefix[i]=prefix[i-1]+arr[i];
    }
    for(auto x:prefix){
        cout<<x<<" ";
    }
    
}