#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int sum = ((arr.size()) * (arr.size() + 1)) / 2;
    for(int i=0;i<arr.size();i++){
        sum-=arr[i];
    }
    cout<<sum;
}
