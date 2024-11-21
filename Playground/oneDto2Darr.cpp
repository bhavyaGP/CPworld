#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> original={1,2,3,4};
    int n=2;
    int m=2;
    vector<vector<int>> ans(m,vector<int> (n));

    for (int i = 0; i < original.size(); i++)
    {
        ans[i/n][i%n]=original[i];
    }

    //here i/n give you row number and i%n give you column number


    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
}