#include<bits/stdc++.h>
using namespace std;
int main(){

    int eventime=5,k=2;
    vector<int> startime={0,1,2,3,4};
    vector<int> endtime={1,2,3,4,5};

    vector<int> diff;
    for(int i=0;i<startime.size();i++){
        diff.push_back(endtime[i]-startime[i]);
    }
    
    int sum=0;
    for(auto x:diff){
        sum+=x;
    }
    if(sum==eventime){
        cout<<0<<endl;
        return 0;
    }
    cout<<eventime-sum<<endl;
    


}